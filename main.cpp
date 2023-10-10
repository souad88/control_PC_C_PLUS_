#include "server.hpp"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    char menu_[]="Choose one of these: \n" //message to client
                                "1-terminal.\n"
                                "2-calulator.\n"
                                "3-firefox.\n";

    char ip_[]="0.0.0.0";
    server_ sock;
    sock.creat_socket();
    sock.bind_socket(3389,ip_);//for Remote connection ,TCP Protocol
    sock.listen_connection();
    sock.start_connection();
    sock.close_listening();
    sock.send_to_client(menu_);
    sock.accept_client(); 
    sock.~server_(); 
    return 0;
}
