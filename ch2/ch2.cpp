// Pour commencer cette épreuve utilisant le protocole TCP, vous devez vous connecter à un programme sur une socket réseau.
//
// Vous devez décoder la chaîne de caractères encodée envoyée par le programme.
// Vous avez 2 secondes pour envoyer la bonne réponse à partir du moment où le programme vous envoie la chaîne.

#include <cstring>
#include <iostream>
#include <ostream>
#include <unistd.h>
#include <vector>
#include <sys/socket.h>

#include "../socketConnector.h"
std::string base64_decode(const std::string &in) {
    static const std::string b = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";//=
    typedef unsigned char uchar;
    std::string out;

    std::vector<int> T(256,-1);
    for (int i=0; i<64; i++) T[b[i]] = i;

    int val=0, valb=-8;
    for (uchar c : in) {
        if (T[c] == -1) break;
        val = (val<<6) + T[c];
        valb += 6;
        if (valb>=0) {
            out.push_back(char((val>>valb)&0xFF));
            valb-=8;
        }
    }
    return out;
}

int main() {
    std::cout << "Début de la seconde épreuve !" << std::endl;
    int socket = SocketConnector::customConnect("challenge01.root-me.org", 52023);

    char buffer[1024] = {};
    read(socket, buffer, 1024);

    std::cout << buffer << std::endl;

    std::string message(buffer);
    int position1 = message.find("'")+1;
    int position2 = message.substr(position1).find("'");
    std::string toDecode = message.substr(position1, position2);

    std::string decoded = base64_decode(toDecode) + '\n';

    std::cout << "Chaîne envoyée :" << std::endl;
    std::cout << decoded << std::endl;
    send(socket, decoded.c_str(), 1024, 0);

    memset(buffer, 0, 1024);

    std::cout << "Chaîne reçue :" << std::endl;
    read(socket, buffer, 1024);
    std::cout << buffer << std::endl;

    close(socket);

    return 0;
}
