# control_PC_C_PLUS_
Control Pc through Mopile using Socket Programming :
 -simple application using socket programming in C++ language to control desktop 
  applications.

Features :
    -Send Client requests to server.
    -Client send one of services to Server to excute it.
    -server excute requestes sent by client using system calls.

Pre-requests:
    -O.S :Linux Operating System (Ubuntu22).
    -VS code, or code blocks (iam using VS Code).
    -C++ language.
    -Tcp/Udp Server&Client :
     https://play.google.com/store/apps/details?id=tcpudpserverclient.steffenrvs.tcpudpserverclient&pcampaignid=web_share&pli=1&raii=tcpudpserverclient.steffenrvs.tcpudpserverclient&raboi=CAE%3D&rasi=4822299910820656511&rapt=AEjHL4NXXWRRFC-pBBf7QN3Z57KFHLF2rqiMm7vLv5tyTZ5drYogeQicX9BrcM-QV0_IJd1YK6ePhKtGpkh1ctK6skH9F54BleojvmuW0YYXTC7FDgbvmqE
    
    
    -check for open ports for local host and remote host :
      netstat -na|grep :port

Start Project :
  -Clone Project Repository.
  -Compile Server Program in VS terminal:
    $g++ main.cpp server_.cpp -o server_ -std=c++11
  
    $./server_
 
  -test client on your terminal : Telnet 0.0.0.0 8080.
  
  -open Tcp/Udp Server&Client : 
      -type your IP :ex: 192.0.0.0.
      -type your port.
  - choose one of services, Server will excute the command on your desktop.    
For Socket_programmming :
  -I recommend Sloan youtube channel : 
    https://www.youtube.com/watch?v=cNdlrbZSkyQ&t=0s
---------------------------------------
Some Updates :
  -I changed the way of comparing between buffer value and any string :
     EX: The old one was : if(buf=="fire"){//commands}; but this method gave me
          a bad issue. the compiler take the complete size of the buffer buf[4096]
          with empty spaces also. 

   -The new one , is to take the value in the buffer and store it in a string , then use C++ substring to take only the number of character to compare between it and the choosed word by the User :
    EX:  if(choosed.substr(0,4)=="fire"){//commands}; //substring to take 4 char only from the  buffer and compare it       
