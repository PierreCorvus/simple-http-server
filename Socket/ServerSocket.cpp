#include "ServerSocket.h"
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <tchar.h>
#define BUFFER_SIZE 1024
#define _WINSOCK_DEPRECATED_WARNINGS
int InitSocketLib() {
    WSADATA wsaData;
    int wsaErr;
    WORD wVersionRequested = MAKEWORD(2, 2);
    wsaErr = WSAStartup(wVersionRequested, &wsaData);
    if (wsaErr != 0) {
        return wsaErr;
    }
    /*WSACleanup();*/
    return 0;
}

int ServerSocket::Listen() {
    SOCKET serverSocket;
    serverSocket = INVALID_SOCKET;
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    
    if (serverSocket == INVALID_SOCKET) {

        WSACleanup();
        return -1;
    }
    sockaddr_in service;
    service.sin_family = AF_INET;
    InetPton(AF_INET, _T("127.0.0.1"), &service.sin_addr.s_addr);
    service.sin_port = htons(this->port); 
    // Use the bind function
    if (bind(serverSocket, reinterpret_cast<SOCKADDR*>(&service), sizeof(service)) == SOCKET_ERROR) {
        closesocket(serverSocket);
        WSACleanup();
        return -2;
    }
    if (listen(serverSocket, 1) == SOCKET_ERROR) {
        return -3;
    }
    SOCKET acceptSocket;
    acceptSocket = accept(serverSocket, nullptr, nullptr);

    // Check for successful connection
    if (acceptSocket == INVALID_SOCKET) {
        WSACleanup();
        return -4;
    }

    char receiveBuffer[BUFFER_SIZE];
    int rbyteCount = recv(acceptSocket, receiveBuffer, BUFFER_SIZE, 0);
    if (rbyteCount < 0) {
        return 0;
    }
    char buffer[BUFFER_SIZE]="Aog";
    int sbyteCount = send(acceptSocket, buffer, BUFFER_SIZE, 0);
    if (sbyteCount == SOCKET_ERROR) {
        return -5;
    }
    return 0;
}
