#include "server.hpp"
#include "command.hpp"
#include <iostream>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <syslog.h>
#include <string>
#include <array>
using namespace std;
server_::server_(){}
void server_::creat_socket()
{
    listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1)
       {
         cerr << "Can't create a socket! Quitting" << endl;
         
       }
    
}
void server_::bind_socket(int port_,char ip_[])
{
   
     hint.sin_family = AF_INET;
     hint.sin_port = htons(port_);//remote
     hint.sin_addr.s_addr = INADDR_ANY;
     inet_pton(AF_INET, ip_, &hint.sin_addr);
     bind(listening, (sockaddr*)&hint, sizeof(hint));
}
void server_::listen_connection()
{
      // send to Winsock that the socket is for listening
     listen(listening, SOMAXCONN);
}
void server_::start_connection()
{
    
    clientSize = sizeof(client);
    clientSocket = accept(listening, (sockaddr*)&client, &clientSize);
    memset(host, 0, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);
    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
    {
        cout << host << " connected on port " << service << endl;
    }
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on port " << ntohs(client.sin_port) << endl;
    }
}
void server_::close_listening()
{
     close(listening);
}
void server_::send_to_client(char message[])
{
    send(clientSocket,message,strlen(message),0);
}
void server_::accept_client()
{
   
   while (true)
    {
        pid_t pid;
       
        memset(buf, 0,4096);
        // Wait for client to send data
        
        bytesReceived = recv(clientSocket,buf, 4096, 0);
        //choosed=buf;
        if (bytesReceived == -1)
        {
            cerr << "Error in recv(). Quitting" << endl;
            break;
        }

        if (bytesReceived == 0)
        {
            cout << "Client disconnected " << endl;
            break;
        }
        
        else
        {
            string choosed=buf;
            //cout<<choosed<<endl;
            cout<<choosed.substr(0,4)<<endl; //substring to take 4 char only from the buffer and compare it
            //cout<<buf[0]<<endl;
            pid = fork();//fork for working two process together
            if(pid==0)
            {
              cout<<"pid created"<<endl;
              //if(buf[0]=='f'){}
              if(choosed.substr(0,4)=="fire")
              {
                    
                  command_is.open_firefox();  //system("firefox");
              }
             //if(buf[0]=='t'){} 
             if(choosed.substr(0,4)=="term")
              {
                    command_is.open_terminal();
              }
              //if(buf[0]=='c'){}
             if(choosed.substr(0,4)=="calc")
              {
                   command_is.open_calculator();
              }  
            }    
              
        }       
        
      
    }
     command_is.~comm_is_();
}
server_::~server_()
{
     close(clientSocket); //close socket     
}
