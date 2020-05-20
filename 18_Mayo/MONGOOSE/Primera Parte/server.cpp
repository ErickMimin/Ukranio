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
#include "arbol.h"
#include "mongoose.h"

using namespace std;
static const char *s_http_port = "8000";
static struct mg_serve_http_opts s_http_server_opts;
struct timeval tv;


static void handle_deleteDuplicated(struct mg_connection *nc, struct http_message *hm){
            char query[256]= "Probando\0";     
            Menssage *msg = r.getRequest();    
             
            mg_send_head(nc,200,strlen(query), "Content-Type: text/plain");
            mg_printf(nc, "%s", query);
}

static void ev_handler(struct mg_connection *nc, int ev, void *p) {
        char query[256];
        struct http_message *hm = (struct http_message *) p;

        if (ev == MG_EV_HTTP_REQUEST) {
            if (mg_vcmp(&hm->uri, "/search") == 0) {
                mg_get_http_var();
                if(msg->operationId == Menssage::allowedOperations::send){            
                            gettimeofday(&tv, NULL);
                            char buffer[16];
                            snprintf(buffer,16,"%ldu%ld", tv.tv_sec,tv.tv_usec); // se concatena los segundos con microsegundos
                            mg_get_http_var(&hm->body, "query", query,sizeof(query));

                            Registro *regis = (Registro*)msg->arguments;
                                if (search(root, string(regis->celular))){
                                    std::cout << "Numero Repetido!\n";
                                    snprintf(buffer,16,"%du%d", 0,0); // se concatena los segundos con microsegundo
                                    r.sendResponse(buffer, strlen(buffer)); 
                                }
                                else {
                                    insert(root, string(regis->celular));
                                    std::cout << "Numero NO Repetido.\n";
                                    memcpy(regis->sec, buffer, 16);
                                    /*cout << regis->celular << endl;
                                    cout << regis->CURP << endl;
                                    cout << regis->partido << endl;
                                    cout << regis->sec << endl; */
                                    int response = write(destino, regis, sizeof(Registro));
                                    r.sendResponse(buffer, strlen(buffer));
                                }
                    
                    } 
                handle_search( nc, hm );  
            }else{
                mg_serve_http(nc, (struct http_message *) p, s_http_server_opts);
            }
    }
}

int main(int argc, char* argv[]){
    
    struct mg_mgr mgr;
    struct mg_connection *nc;
    mg_mgr_init(&mgr, NULL);
    Response r(atoi(argv[2]));
    
    if(argc < 2){
        //cerr << "ERROR: No name file" << endl;
        exit(1);
    }

    printf("Starting web server on port %s\n", s_http_port);
    nc = mg_bind(&mgr, s_http_port, ev_handler);
    /* Revisamos la entrada del puerto */
    
    struct TrieNode *root = getNode(); 
    //cout << "Servidor iniciado..." << endl;
    int destino = open(argv[1], O_TRUNC|O_WRONLY|O_CREAT, 0666);

    while(true){
       if (nc == NULL) {
        printf("Failed to create listener\n");
        return 1;
        }
       
    }

    // Set up HTTP server parameters
        mg_set_protocol_http_websocket(nc);
        s_http_server_opts.document_root = "www"; // Serve current directory
        s_http_server_opts.enable_directory_listing = "yes";
        for(;;){
            mg_mgr_poll(&mgr, 1000);
        }
        mg_mgr_free(&mgr);
        return 0;
        
}

//|O_APPEND|O_CREAT|O_TRUNC
