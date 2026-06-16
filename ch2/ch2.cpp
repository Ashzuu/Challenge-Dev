// Pour commencer cette épreuve utilisant le protocole TCP, vous devez vous connecter à un programme sur une socket réseau.
//
// Vous devez décoder la chaîne de caractères encodée envoyée par le programme.
// Vous avez 2 secondes pour envoyer la bonne réponse à partir du moment où le programme vous envoie la chaîne.

#include <iostream>
#include <ostream>
#include <unistd.h>

#include "../socketConnector.h"

int main() {
    std::cout << "Début de la seconde épreuve !" << std::endl;
    int socket = SocketConnector::customConnect("challenge01.root-me.org", 52023);

    char buffer[1024] = {};
    read(socket, buffer, 1024);

    std::cout << buffer << std::endl;

    return 0;
}
