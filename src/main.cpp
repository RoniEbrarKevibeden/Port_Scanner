#include <iostream>
#include <string>
#include <cstdlib>
#include <winsock2.h>
#include "scanner.h"

#pragma comment(lib, "Ws2_32.lib")

static void usage() {
    std::cout << "Usage: cpp-port-scanner <ip> <port1> <port2> ...\n";
    std::cout << "Example: cpp-port-scanner 127.0.0.1 22 80 443\n";
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        usage();
        return 1;
    }

    std::string ip = argv[1];

    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        std::cerr << "WSAStartup failed.\n";
        return 1;
    }

    std::cout << "Target: " << ip << "\n";

    for (int i = 2; i < argc; i++) {
        int port = std::atoi(argv[i]);
        if (port <= 0 || port > 65535) {
            std::cout << argv[i] << ": invalid port\n";
            continue;
        }

        PortStatus st = check_port(ip, port, 300);

        std::cout << port << ": ";
        if (st == PortStatus::Open) std::cout << "open";
        else if (st == PortStatus::Closed) std::cout << "closed";
        else std::cout << "error";
        std::cout << "\n";
    }

    WSACleanup();
    return 0;
}

