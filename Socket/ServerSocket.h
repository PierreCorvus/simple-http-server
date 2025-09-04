#pragma once
#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H
#include <string>

#define BUFFER_SIZE 1024
class ServerSocket
{
public:
	ServerSocket(std::string host, unsigned int port) {
		this->host = host;
		this->port = port;
	}
	int Listen();
protected:
	virtual std::string processData(std::string recieved) = 0;
	std::string host="";
	unsigned int port=0;
	

};

int InitSocketLib();
#endif

