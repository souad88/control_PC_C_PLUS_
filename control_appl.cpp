#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include<fcntl.h>
#include<cstdlib>
#include <syslog.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
   
  system("gnome-calculator");
   pid_t pid;
   pid = fork();//fork for working two process together
   if(pid==0)
  {
   // cout<<"Output from the child process."<<endl;
    //system("gnome-terminal");
    //system("gnome-calculator");
  }
else if(pid==1)
 {
      cout<<"Output from the parent process."<<endl;
 }  
return 0;
}