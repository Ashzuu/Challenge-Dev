//
// Challenge n°1 :
// Pour commencer cette épreuve utilisant le protocole TCP, vous devez vous connecter à un programme sur une socket réseau.
//
// Vous devez calculer la racine carrée du nombre n°1 et multiplier le résultat obtenu par le nombre n°2.
// Vous devez ensuite arrondir à deux chiffres après la virgule le résultat obtenu.
// Vous avez 2 secondes pour envoyer la bonne réponse à partir du moment où le programme vous envoie le calcul.
//
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>

#include "../socketConnector.h"


int searchNumberInMessage(std::string message, std::string toFind) {
    int position = message.find(toFind);
    std::string toExtract = message.substr(position + toFind.length());
    return std::stoi(toExtract);
}


int main() {
    int clientSocket = SocketConnector::customConnect("challenge01.root-me.org", 52002);

    char buffer[1024] = {};
    int byteRead = read(clientSocket, buffer, 1024);
    std::cout << buffer << std::endl;

    const std::string message(buffer);

    int firstNumber = searchNumberInMessage(message, "square root of");
    int secondNumber = searchNumberInMessage(message, "and multiply by");

    float result = std::sqrt(firstNumber)*secondNumber;

    std::ostringstream fluxReponse;
    fluxReponse << std::fixed << std::setprecision(2) << result;
    std::string finalResponse = fluxReponse.str() + "\n";

    std::cout << finalResponse << std::endl;

    send(clientSocket, finalResponse.c_str(), 1024, 0);

    memset(buffer, 0, 1024);
    read(clientSocket, buffer, 1024);

    std::cout << buffer << std::endl;

    close(clientSocket);
    return 0;
}
