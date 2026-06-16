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


int searchNumberInMessage(std::string message, std::string toFind) {
    int position = message.find(toFind);
    std::string toExtract = message.substr(position + toFind.length());
    return std::stoi(toExtract);
}


int main() {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        perror("Erreur avec le socket");
        return -1;
    }

    std::string adress = "challenge01.root-me.org";
    int port = 52002;
    struct sockaddr_in infoServer;
    infoServer.sin_family = AF_INET;
    infoServer.sin_port = htons(port);

    struct hostent* host = gethostbyname(adress.c_str());
    if (host == nullptr) {
        std::cerr << "Erreur : Impossible de résoudre le nom de domaine." << std::endl;
        close(clientSocket);
        return -1;
    }

    std::memcpy(&infoServer.sin_addr, host->h_addr_list[0], host->h_length);

    int connexionResult = connect(clientSocket, reinterpret_cast<struct sockaddr *>(&infoServer), sizeof(infoServer));
    if (connexionResult == -1) {
        perror("Erreur avec le connect");
        close(clientSocket);
        return -1;
    }

    std::cout << "Connexion au serveur réussie !" << std::endl;

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
