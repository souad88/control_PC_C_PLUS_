#include "server.hpp"
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    const char *menu_="Choose one of these: \n" //message to client
                                "1-terminal.\n"
                                "2-calulator.\n"
                                "3-firefox.\n";
    server_ server_;
    server_.creat_socket();
    server_.bind_socket(3389,"0.0.0.0");//for Remote connection ,TCP Protocol
    server_.listen_connection();
    server_.start_connection();
    server_.close_listening();
    server_.send_to_client(menu_);
    server_.accept_client(); 
    server_.~server_(); 
    return 0;
}