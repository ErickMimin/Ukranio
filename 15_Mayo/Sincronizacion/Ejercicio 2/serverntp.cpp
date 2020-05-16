#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <thread>
#include <chrono>
#include "Response.h"

using namespace std;


int main(int argc, char* argv[]){

	struct tm *info;
    time_t rawtime;
    char timestring[80];
    char final_time[80];
    struct timeval tv;
    Response r(atoi(argv[1]));
    while(true){
        Menssage *msg = r.getRequestNoValidation();
        gettimeofday(&tv, NULL);

        if(msg->operationId == Menssage::allowedOperations::send){
            info = localtime(&tv.tv_sec);
            r.sendResponse((char*)&tv, sizeof(tv));
            strftime(timestring, 80, "%H:%M:%S.%%06u", info);//Convierte tiempo en char
            snprintf(final_time, 80, timestring, tv.tv_usec);
            printf("%s\n", final_time);
        }
    }
}