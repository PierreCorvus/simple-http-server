// SimpleHttpServer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Socket/ServerSocket.h"

class BasicSocket: public ServerSocket {
public:
    BasicSocket(std::string host, unsigned int port) : ServerSocket(host, port) {

    }
protected:
    std::string processData(std::string recieved) override {
        std::cout << recieved << std::endl;
        return "HTTP/1.1 200 OK\nContent-Type: text/html; charset=utf-8\nConnection:close\n Aaaaa\r\n\r\n";
    }
};

int main()
{
    std::cout << InitSocketLib()<< " Hello World!\n";
    auto s = BasicSocket("127.0.0.1", 8000);
    std::cout << s.Listen() <<std::endl;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
