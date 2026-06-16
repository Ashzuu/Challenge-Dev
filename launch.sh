#!/bin/bash
# Attention : Fichier à maintenir en fonction des bibliothèques internes utilisées + les conventions de nommage !
echo Quel challenge souhaitez-vous exécuter ?
read nbChallenge
c++ ch$nbChallenge/ch$nbChallenge.cpp socketConnector.cpp -o ch$nbChallenge/ch$nbChallenge.out
./ch$nbChallenge/ch$nbChallenge.out