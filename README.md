# Challenges - Programmation

Ce dépôt regroupe mes solutions personnelles aux challenges de la catégorie **Programmation** d'une plateforme d'apprentissage.

## ⚠️ Avertissement

> **Ces challenges sont tirés d'un site et ne doivent pas être recopiés !**
> Si vous connaissez / reconnaissez la source de ces challenges, merci de ne pas les utiliser pour faciliter la résolution des épreuves sans effort personnel.

L'objectif de ce dépôt n'est pas de favoriser la "triche", mais de démontrer mes capacités à concevoir des solutions techniques et algorithmiques à partir d'un énoncé spécifique. L'énoncé de chaque challenge est systématiquement inclus en commentaire au début de chaque fichier source.

## Structure du Projet

Le projet est organisé de la manière suivante :

- `chX/` : Répertoire dédié à chaque challenge contenant le code source (`chX.cpp`).
- `socketConnector.h` / `socketConnector.cpp` : Utilitaire réutilisable développé pour simplifier la gestion des connexions socket TCP, composant essentiel pour interagir avec les services distants des épreuves.
- `launch.sh` : Script utilitaire pour automatiser la compilation et l'exécution des épreuves.

## Technologies Utilisées

- **Langage** : C++
- **Réseau** : Sockets TCP/IP (Standard POSIX)
- **Environnement** : Linux / Bash

## Utilisation

Pour compiler et lancer un challenge spécifique, vous pouvez utiliser le script `launch.sh` :

```bash
chmod +x launch.sh
./launch.sh
```

Le script vous invitera à saisir le numéro du challenge souhaité, puis se chargera de la compilation avec les dépendances nécessaires avant de lancer l'exécutable.