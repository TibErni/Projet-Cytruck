# Readme du projet Cytruck

Les créateurs de ce projet sont Thibault Raillard et Camille Béaur.

Ce readme va servir à présenter le fonctionnement de notre projet.

## Fonctionnement de Cytruck :

**Pour exécuter le programme, il existe 2 possibilités :** 

Pour chaque étape il faut être dans le répertoire ProjetCyTruck de notre projet.

- La première méthode pour exécuter notre projet est d'entrer la commande : **" ./cytruck.sh -f data.csv -d1 "**, (la commande -d1 est un exemple de traitement, on peut en demander un autre.)

  ![](https://media.discordapp.net/attachments/1098669939398811790/1202680267823784037/methode_1.png?ex=65ce5648&is=65bbe148&hm=83a692610cb06f6dfe457b821ad7306bfe14f969650cf72475b1b48799054874&=&format=webp&quality=lossless)
- La seconde méthode se déroule en 3 temps : en rentre la commande :**"./cytruck.sh "**, on va alors demander le chemin vers le document à traiter, on rentre donc la commande **" data.csv "**, le programme va ensuite nous demander quel traitment on souhaite faire et on rentre par exemple : **" -d1 -d2 "**.

Ce projet comporte plusieurs commandes/traitement dans le but de trier le document CSV, voici la liste :

## L'argument "-h" : 

L'argument **-h** sers à afficher toutes les différentes façons de trier le document CSV et la commande qui explique comment faire le tri en question. 

## L'argument "-d1" : 

L'argument **-d1** sers à trier le document en fonction du nombre de trajets réalisés par les conducteurs. 

Cet histogramme horizontal va afficher les 10 conducteurs ayant fait le plus de trajet de façon décroissante. Le graphique va afficher en abscisse le nombre de trajets effectués et en ordonnée les noms des conducteurs. 

Exmeple de graphique -d1 :

![](https://media.discordapp.net/attachments/1098669939398811790/1202328304670232586/-d1.png?ex=65cd0e7e&is=65ba997e&hm=3374e36b2fca49367e3dcbccda3c7c94660d53cf5aa8b8ec319ea0da31558cde&=&format=webp&quality=lossless)

## L'argument "-d2" :

L'argument **-d2** sers à trier le document en fonction de la plus grande distance totale parcourue par les chauffeurs.

Cet histogramme horizontal va afficher les 10 conducteurs ayant parcourus le plus de distance cumulée de façon décroissante. Le graphique va afficher en abscisse la distance totale parcourue et en ordonnée les noms des conducteurs.

Exmeple de graphique -d2 :

![](https://media.discordapp.net/attachments/1098669939398811790/1202224435487326208/image.png?ex=65ccadc1&is=65ba38c1&hm=d8754e2226ca09689b74fd57f73b3fd92a8330ffd5c75da75a82d5fa0dcde90a&=&format=webp&quality=lossless&width=796&height=597)

## L'argument "-l" :

L'argument **-l** sers à trier le document en fonction des trajets les plus longs, c'est-à-dire l'addition de la distance de toutes les étapes de ce trajet. Chaque trajet a un identifiant

Cet histogramme vertical va afficher les 10 trajets les plus longs de façon croissante en fonction de l'identifiant du trajet. Le graphique va afficher en abscisse l'identifiant du trajet et en ordonnée la distance en kilomètres du trajet.

Exmeple de graphique -l :

![](https://media.discordapp.net/attachments/1098669939398811790/1202224688617771018/image.png?ex=65ccadfe&is=65ba38fe&hm=82659c73c3c4e0fe88aa9d767139a25d8b37ea682d9ff1b15165a47a7a676bd1&=&format=webp&quality=lossless&width=796&height=597)

## L'argument "-t" :

L'argument **-t** sers à trier le document en fonction des villes les plus traversées par les conducteurs.

Cet histogramme regroupé (histogramme vertical mais chaque donnée possède 2 colonnes verticals) va afficher les 10 villes qui ont été le plus parcourus par les chauffeurs de façon alphabétique. Le graphique va afficher en abscisse le nom des villes et en ordonnée le nombre de trajets. 

Chaque ville est composée de barres verticales, une affiche le nombre de trajet total qui traverse la ville et une qui affiche le nombre de fois que la ville a été le départ d'un trajet.

**IMPLÉMENTATION PAS TERMINÉE**

## L'argument "-s" :

L'argument **-s** sers à afficher la distance moyenne, minimale et maximale pour chaque trajet. 

Ce graphique de type min max moyenne va créer 3 courbes, une pour la distance minimale, une pour la distance maximale et une pour la distance moyenne. On va récupérer les 3 données de chaque trajet, ce graphique va afficher les 50 premières trajets triés par *"trajet maximal - trajet minimal "*, autrement dit on va privilégier les trajets dont les étapes se rapprochent le plus en matière de distance. Le graphique va afficher en abscisse les identifiants du trajet et en ordonnée les kilométrages.

**IMPLÉMENTATION PAS TERMINÉE**
