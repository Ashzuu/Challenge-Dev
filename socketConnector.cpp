//
// Created by edynak on 16/06/2026.
//

#include "socketConnector.h"

#include <cstring>
#include <iostream>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

int SocketConnector::customConnect(std::string host, int port) {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        perror("Erreur avec le socket");
        return -1;
    }

    struct sockaddr_in infoServer;
    infoServer.sin_family = AF_INET;
    infoServer.sin_port = htons(port);

    struct hostent* adress = gethostbyname(host.c_str());
    if (adress == nullptr) {
        std::cerr << "Erreur : Impossible de résoudre le nom de domaine." << std::endl;
        close(clientSocket);
        return -1;
    }

    std::memcpy(&infoServer.sin_addr, adress->h_addr_list[0], adress->h_length);

    int connexionResult = connect(clientSocket, reinterpret_cast<struct sockaddr *>(&infoServer), sizeof(infoServer));
    if (connexionResult == -1) {
        perror("Erreur avec le connect");
        close(clientSocket);
        return -1;
    }

    std::cout << "Connexion au serveur réussie !" << std::endl;

    return clientSocket;
}