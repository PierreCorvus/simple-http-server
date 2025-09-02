#pragma once
#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H
#include <string>
class ServerSocket
{
public:
	ServerSocket(std::string host, unsigned int port) {


	}
	int Listen();
protected:
	std::string host="";
	unsigned int port=0;


};
int InitSocketLib();
#endif

