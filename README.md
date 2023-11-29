# RAYMARCHING OCEAN

## Contexte du Projet
Ce projet a été réalisé dans le cadre du cours de Synthèse d'Image à EPITA. Il s'agit d'une simulation des vagues océaniques en utilisant la technique de raymarching, inspirée par le papier de recherche de Jerry Tessendorf (2001). L'objectif était de recréer de manière réaliste les mouvements et l'aspect visuel des vagues océaniques.

## Pourquoi Jerry Tessendorf?
Jerry Tessendorf est renommé pour sa méthode innovante dans la simulation des fluides, particulièrement les vagues océaniques. Ce qui distingue son travail est l'utilisation de données réelles pour informer le modèle de vagues, permettant un rendu plus réaliste. Son approche combine l'exactitude scientifique avec la faisabilité computationnelle, faisant de son papier un choix idéal pour notre projet visant à simuler de manière convaincante les vagues d'un océan.

## Description Technique
Le projet s'articule autour de plusieurs étapes clés pour simuler les vagues :
1. **Génération du Spectre Initial** : Utilisation du spectre de Phillips pour créer un modèle initial des vagues.
2. **Hauteur Initiale des Vagues** : Combinaison du spectre de Phillips avec un bruit gaussien pour générer la hauteur initiale des vagues.
3. **Évolution Temporelle** : Application de la relation de dispersion pour simuler le mouvement des vagues au fil du temps.
4. **Transformation de Fourier Inverse (IFFT)** : Conversion du spectre des vagues du domaine fréquentiel au domaine spatial pour obtenir la surface de l'océan.

## Raymarching et Moteur de Rendu
- Implémentation d'un raymarcher classique avec SDF (Signed Distance Function) pour modéliser les objets dans la scène.
- Utilisation du modèle d'illumination de Phong pour le calcul de l'éclairage.
- Intégration d'une heightmap (carte des hauteurs) pour représenter la surface de l'océan.
