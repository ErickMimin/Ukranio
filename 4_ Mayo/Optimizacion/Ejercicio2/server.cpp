#include <iostream>
#include <string>
#include <map>
#include <fcntl.h>
#include <unistd.h>
#include "Response.h"
#include <sys/time.h>
#include <string.h>
#include <algorithm>    // std::binary_search, std::sort
#include <vector>       // std::vector


using namespace std;

const int ALPHABET_SIZE = 26; 
  
// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    // isEndOfWord is true if the node represents 
    // end of a word 
    bool isEndOfWord; 
}; 
  
// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
  
// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
} 
  
// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 


int main(int argc, char* argv[]){
    /* Revisamos la entrada del puerto */
    if(argc < 2){
        //cerr << "ERROR: No name file" << endl;
        exit(1);
    }
    struct TrieNode *root = getNode(); 
    Response r(3000);
    map<string, int> nbd;

    //cout << "Servidor iniciado..." << endl;
    int destino = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0666);
    std::vector<std::string> v;

    while(true){
        Menssage *msg = r.getRequest();
        //int* nums = (int*)msg->arguments;
        destino = open(argv[1], O_APPEND|O_WRONLY, 0666);

        /*cout << "Solicitud enviada desde " << r.address << ":" << r.port << endl;
        cout << " request ID = " << msg->requestId << endl;
*/
        if(msg->operationId == Menssage::allowedOperations::send){
            struct timeval tv;
            gettimeofday(&tv, NULL);
            char buffer[16];
            snprintf(buffer,16,"%ldu%ld", tv.tv_sec,tv.tv_usec); // se concatena los segundos con microsegundos
            
            Registro *regis = (Registro*)msg->arguments;
            
            
            
            if (search(root, string(regis->celular))){
                //std::cout << "Numero Repetido!\n";
                snprintf(buffer,16,"%du%d", 0,0); // se concatena los segundos con microsegundo
                r.sendResponse(buffer, strlen(buffer)); 
            }
            else {
                insert(root, string(regis->celular));
                //std::cout << "Numero NO Repetido.\n";
                memcpy(regis->sec, buffer, 16);
                /*cout << regis->celular << endl;
                cout << regis->CURP << endl;
                cout << regis->partido << endl;
                cout << regis->sec << endl;*/
                int response = write(destino, regis, sizeof(Registro));
                fsync(destino);
                close(destino);
                r.sendResponse(buffer, strlen(buffer));
                v.push_back (regis->celular);
            }
            
           

            
        } 
    }
    //cout << "Servivor apagandose..." << endl;
    return 0;
}

//|O_APPEND|O_CREAT|O_TRUNC
