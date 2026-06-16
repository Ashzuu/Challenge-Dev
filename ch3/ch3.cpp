// Pour commencer cette épreuve utilisant le protocole TCP, vous devez vous connecter à un programme sur une socket réseau.
//
// Vous devez décoder la chaîne de caractères encodée en ROT13 envoyée par le programme.
// Vous avez 2 secondes pour envoyer la bonne réponse à partir du moment où le programme vous envoie la chaîne.

#include <cstring>
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>

#include "../socketConnector.h"

char getNewLetter(char letter) {
    const char ALPHABET_MINUSCULES[26]={
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v','w','x','y','z'
    };
    const char ALPHABET_MAJUSCULES[26]={
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };
    char res = letter;
    for (int i=0; i < 26; i++) {
        if (letter == ALPHABET_MINUSCULES[i]) {
            return ALPHABET_MINUSCULES[(i+13)%26];
        }
        if (letter == ALPHABET_MAJUSCULES[i]) {
            return ALPHABET_MAJUSCULES[(i+13)%26];
        }
    }
    return res;
}
// Pour commencer cette épreuve utilisant le protocole TCP, vous devez vous connecter à un programme sur une socket réseau.
//
// Vous devez décoder la chaîne de caractères encodée en ROT13 envoyée par le programme.
// Vous avez 2 secondes pour envoyer la bonne réponse à partir du moment où le programme vous envoie la chaîne.
int main() {
    std::cout << "Début du troisième challenge !" << std::endl;
    int socket = SocketConnector::customConnect("challenge01.root-me.org", 52021);

    char buffer[1024] = {};
    read(socket, buffer, 1024);

    std::cout << buffer << std::endl;

    std::string message(buffer);
    int position1 = message.find("'")+1;
    int position2 = message.substr(position1).find("'");
    std::string toDecode = message.substr(position1, position2);

    std::cout << "Message à décoder :" << std::endl;
    std::cout << toDecode << std::endl;

    std::string decoded = "";
    for (char toDecodeChar : toDecode) {
        decoded += getNewLetter(toDecodeChar);
    }

    decoded += '\n';

    std::cout << "Message décodé :" << std::endl;
    std::cout << decoded << std::endl;

    memset(buffer, 0, 1024);

    int status = send(socket, decoded.c_str(), 1024, 0);
    if (status < 0) {
        std::cout << "Une erreur est survenue lors de l'envoi" << std::endl;
        return -1;
    }

    std::cout << "Message reçu du serveur :" << std::endl;
    read(socket, buffer, 1024);

    std::cout << buffer << std::endl;
    close(socket);
    return 0;
}

