#define MG_ENABLE_HTTP_STREAMING_MULTIPART 1
#include "mongoose.h"
#include "DatagramSocket.h"
#include "DatagramPacket.h"
#include <stdio.h>
#include <iostream>
#include <sys/time.h>
#include <thread>
using namespace std;

static const char *s_http_port ;
static struct mg_serve_http_opts s_http_server_opts;
struct timeval tv1, tv2;

static void handle_http(struct mg_connection *nc, struct http_message *hm, DatagramSocket &s) {
		char query[256];
		string response;
		size_t len_response;
		mg_get_http_var(&hm->body, "query", query, sizeof(query));
		printf("Address: %s\n", query);
		gettimeofday(&tv1, NULL);
		int servers = 100, r, num;
		DatagramPacket pqres((char*) &num, sizeof(num));
		while(servers--){
			r = s.receiveTimeout(pqres, 0, 500000);
			if(r >= 0){
				gettimeofday(&tv2, NULL);
				response.append(pqres.getAddress());
				response.append(", Time: ");
				response.append(to_string(tv2.tv_usec - tv1.tv_usec));
				response.append("</br>");
			}
		}
		
		mg_send_head(nc, 200, response.size(), "Content-Type: text/plain");
		mg_printf(nc, "%s", response.c_str());
}

static void ev_handler(struct mg_connection *nc, int ev, void *p) {
	char query[256];
 	struct http_message *hm = (struct http_message *) p;


	if (ev == MG_EV_HTTP_REQUEST) {
		if (mg_vcmp(&hm->uri, "/search") == 0) { 
			
			mg_get_http_var(&hm->body, "query", query,sizeof(query));
			printf("Cadena introducida: %s\n",query);
			DatagramPacket pq(NULL, 0, query, 7200);
			DatagramSocket sock(7200);
			sock.send(pq);
		    handle_http(nc, hm, sock);  
		}else{
			mg_serve_http(nc, (struct http_message *) p, s_http_server_opts);
		}
	}

}

int main(int argc, char* argv[]) {
	struct mg_mgr mgr;
	struct mg_connection *nc;
	s_http_port = (const char *)argv[1];
	mg_mgr_init(&mgr, NULL);

	printf("Starting web server on port %s\n", s_http_port);
	nc = mg_bind(&mgr, s_http_port, ev_handler);
	if (nc == NULL) {
		printf("Failed to create listener\n");
		return 1;
	}
	// Set up HTTP server parameters
	mg_set_protocol_http_websocket(nc);
	s_http_server_opts.document_root = "www"; // Serve current directory
	s_http_server_opts.enable_directory_listing = "yes";
	for (;;) {
		mg_mgr_poll(&mgr, 1000);
	}
	mg_mgr_free(&mgr);
	return 0;
}
