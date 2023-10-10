#pragma once

#include "command.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <syslog.h>
using namespace std;
class server_
{
    public :
       int listening;
       sockaddr_in hint;
       sockaddr_in client;
       socklen_t clientSize;
       char host[NI_MAXHOST];      // Client's remote name
       char service[NI_MAXSERV];   // Service (i.e. port) the client is connect on
       int clientSocket;
       string choosed;
       char buf[4096];
       int bytesReceived;
       comm_is_ *command_is; //commands to call system applications 
       server_();
       void creat_socket();
       void bind_socket(int port_,const char* ip_);
       void listen_connection();
       void start_connection();
       void close_listening();
       void send_to_client(const char*);
       void accept_client(); 
       ~server_();       
};