#!/bin/bash
echo "fichier csv : $1"
CSV_FILE=$1

# Démarrer le chronomètre
START_TIME=$(date +%s)


# Chemin vers le fichier CSV
#CSV_FILE="data.csv"

# Fichier de sortie pour les distances
DISTANCES_FILE="distances.txt"

# Fichier de sortie pour l'histogramme
OUTPUT_GRAPH="conducteurs_distances.png"

# Calculez la distance totale parcourue par chaque conducteur
# Assurez-vous que le séparateur de champ est correct (-F';') et que les colonnes sont correctement référencées
awk -F';' 'NR > 1 {distance[$6] += $5} END {for (d in distance) print distance[d], d}' "$CSV_FILE" | sort -nr | head -10 > "$DISTANCES_FILE"


# Fichier de données
DATA_FILE="distances.txt"

# Sauvegarder temporairement les données inversées
tac "$DATA_FILE" > temp.txt && mv temp.txt "$DATA_FILE"


# Arrêter le chronomètre
END_TIME=$(date +%s)

# Calculer le temps d'exécution
ELAPSED_TIME=$(($END_TIME - $START_TIME))

echo "Temps d'exécution: $ELAPSED_TIME secondes"

gnuplot -p plot2.gp
