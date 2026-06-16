// Pour commencer cette épreuve utilisant le protocole TCP, vous devez vous connecter à un programme sur une socket réseau.
//
// Vous devez décoder les chaînes de caractères compressées avec zlib et encodées en base64 envoyées par le programme.
// Vous devez renvoyer le message d’origine plusieurs fois.
// Vous avez 2 secondes pour envoyer la bonne réponse à partir du moment où le programme vous envoie la chaîne.
#include <iostream>
#include "../socketConnector.h"

int main() {
    int socket = SocketConnector::customConnect("challenge01.root-me.org", 52022);
}
