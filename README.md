# Readme du projet Cytruck

Les créateurs de ce projet sont Thibault Raillard et Camille Béaur.

Ce readme va servir à présenter le fonctionnement de notre projet.

## Fonctionnement de Cytruck :

**Pour exécuter le programme, le chemin du document CSV que l'on souhaite traiter doit être écrit en premier argument.**

Ce projet comporte plusieurs commandes/traitement dans le but de trier le document CSV, voici la liste :

## L'argument "-h" : 

L'argument **-h** sers à afficher toutes les différentes façons de trier le document CSV et la commande qui explique comment faire le tri en question. 

## L'argument "-d1" : 

L'argument **-d1** sers à trier le document en fonction du nombre de trajets réalisés par les conducteurs. 

Cet histogramme horizontal va afficher les 10 conducteurs ayant fait le plus de trajet de façon décroissante. Le graphique va afficher en abscisse le nombre de trajets effectués et en ordonnée les noms des conducteurs. 

## L'argument "-d2" :

L'argument **-d2** sers à trier le document en fonction de la plus grande distance totale parcourue par les chauffeurs.

Cet histogramme horizontal va afficher les 10 conducteurs ayant parcourus le plus de distance cumulée de façon décroissante. Le graphique va afficher en abscisse la distance totale parcourue et en ordonnée les noms des conducteurs.

## L'argument "-l" :

L'argument **-l** sers à trier le document en fonction des trajets les plus longs, c'est-à-dire l'addition de la distance de toutes les étapes de ce trajet. Chaque trajet a un identifiant

Cet histogramme vertical va afficher les 10 trajets les plus longs de façon croissante en fonction de l'identifiant du trajet. Le graphique va afficher en abscisse l'identifiant du trajet et en ordonnée la distance en kilomètres du trajet.

## L'argument "-t" :

L'argument **-t** sers à trier le document en fonction des villes les plus traversées par les conducteurs.

Cet histogramme regroupé (histogramme vertical mais chaque donnée possède 2 colonnes verticals) va afficher les 10 villes qui ont été le plus parcourus par les chauffeurs de façon alphabétique. Le graphique va afficher en abscisse le nom des villes et en ordonnée le nombre de trajets. 

Chaque ville est composée de barres verticales, une affiche le nombre de trajet total qui traverse la ville et une qui affiche le nombre de fois que la ville a été le départ d'un trajet.

## L'argument "-s" :

L'argument **-s** sers à afficher la distance moyenne, minimale et maximale pour chaque trajet. 

Ce graphique de type min max moyenne va créer 3 courbes, une pour la distance minimale, une pour la distance maximale et une pour la distance moyenne. On va récupérer les 3 données de chaque trajet, ce graphique va afficher les 50 premières trajets triés par *"trajet maximal - trajet minimal "*, autrement dit on va privilégier les trajets dont les étapes se rapprochent le plus en matière de distance. Le graphique va afficher en abscisse les identifiants du trajet et en ordonnée les kilométrages.
