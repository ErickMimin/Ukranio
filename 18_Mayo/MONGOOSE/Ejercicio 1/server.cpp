#define MG_ENABLE_HTTP_STREAMING_MULTIPART 1
#include "mongoose.h"
#include "Response.h"
#include "Request.h"
#include "arbol.h"
#include <iostream>
#include <string>
#include <map>
#include <fcntl.h>
#include <thread>
#include <unistd.h>
#include <unordered_map>
#include <sys/time.h>
#include <string.h>
#include <algorithm>    // std::binary_search, std::sort
#include <vector>       // std::vector

using namespace std;

static const char *s_http_port = "8000";
static struct mg_serve_http_opts s_http_server_opts;
unordered_map<string, int> servers;

void server_dbd(){
    Response res = Response(9000);
    string map;
    while(true){
        Menssage *msg = res.getRequestNoValidation();
        if(msg->operationId == Menssage::allowedOperations::http){
            map = res.address + ':' + string(msg->arguments);
            if(servers.find(map) == servers.end())
                servers[map] = 1;
            else
                servers[map] = servers[map] + 1;
            res.sendResponse(NULL, 0);
        }
    }
}

void server_web(struct mg_mgr *mgr){
    while(true)
        mg_mgr_poll(mgr, 1000);
}

static void handle_managment(struct mg_connection *nc, struct http_message *hm) {
		string query;
		//mg_get_http_var(&hm->body, "query", query,sizeof(query));
        unordered_map<string, int>::iterator it;
        for(it = servers.begin(); it != servers.end(); it++){
            query.append((it->first).c_str());
            query.push_back(';');
            query.append((to_string(it->second)).c_str());
            query.push_back(' ');
        }

		mg_send_head(nc, 200, query.length(), "Content-Type: text/plain");
		mg_printf(nc, "%s", query.c_str());
}

static void ev_handler(struct mg_connection *nc, int ev, void *p) {
	char query[256];
 	struct http_message *hm = (struct http_message *) p;


	if (ev == MG_EV_HTTP_REQUEST) {
		if (mg_vcmp(&hm->uri, "/managment") == 0) { 
			//mg_get_http_var(&hm->body, "query", query,sizeof(query));
			printf("Solicitud recibida\n");
		    handle_managment(nc, hm);  
		}else{
			mg_serve_http(nc, (struct http_message *) p, s_http_server_opts);
		}
	}

}


int main(int argc, char* argv[]){
    /* Error en los argumentos */
    if(argc < 2){
        exit(1);
    }
    struct TrieNode *root = getNode(); 
    int destino = open(argv[1], O_TRUNC|O_WRONLY|O_CREAT, 0666);

    /* Empezar el servidor UDP */
    Response r(atoi(argv[2]));
    Request req;
    cout << "Servidor UDP iniciado..." << endl;

    /* Empezar el HTTP */
    struct mg_mgr mgr;
	struct mg_connection *nc;
	mg_mgr_init(&mgr, NULL);

	printf("Servicio web iniciado en el puerto: %s\n", s_http_port);
	nc = mg_bind(&mgr, s_http_port, ev_handler);
	if (nc == NULL) {
		printf("ERROR: Creando el servidor web\n");
		return 1;
	}
    mg_set_protocol_http_websocket(nc);
	s_http_server_opts.document_root = "www"; // Serve current directory
	s_http_server_opts.enable_directory_listing = "yes";
    thread t(server_web, &mgr);
    t.detach();
    thread tb(server_dbd);
    tb.detach();

    while(true){
        Menssage *msg = r.getRequest();
        if(msg->operationId == Menssage::allowedOperations::send){
            struct timeval tv;
            gettimeofday(&tv, NULL);
            char buffer[16];
            snprintf(buffer,16,"%ldu%ld", tv.tv_sec,tv.tv_usec); // se concatena los segundos con microsegundos
            
            Registro *regis = (Registro*)msg->arguments;

            if (search(root, string(regis->celular))){
                std::cout << "Numero Repetido!\n";
                snprintf(buffer,16,"%du%d", 0,0); // se concatena los segundos con microsegundo
                r.sendResponse(buffer, strlen(buffer)); 
            }else{
                insert(root, string(regis->celular));
                std::cout << "Numero NO Repetido.\n";
                memcpy(regis->sec, buffer, 16);
                cout << regis->celular << endl;
                cout << regis->CURP << endl;
                cout << regis->partido << endl;
                cout << regis->sec << endl;
                size_t len_response;
                req.doOperationBroadcast(argv[4], 9000, Menssage::allowedOperations::http, argv[2], sizeof(argv[2]), len_response);
                int response = write(destino, regis, sizeof(Registro));
                r.sendResponse(buffer, strlen(buffer));
            }
        }
        
    }
    mg_mgr_free(&mgr);
    //cout << "Servivor apagandose..." << endl;
    return 0;
}

//|O_APPEND|O_CREAT|O_TRUNC
