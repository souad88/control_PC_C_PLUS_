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
    $g++ main.cpp server.cpp command.cpp -o server_ -std=c++11
    $./server_
  -test client on your terminal : Telnet 0.0.0.0 8080.
  -open Tcp/Udp Server&Client : 
      -type your IP :ex: 192.0.0.0.
      -type your port.
  - choose one of services, Server will excute the command on your desktop.    
For Socket_programmming :
  -I recommend Sloan youtube channel : 
    https://www.youtube.com/watch?v=cNdlrbZSkyQ&t=0s













