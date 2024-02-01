#!/bin/bash

echo "fichier csv : $1"
CSV_FILE=$1

# Démarrer le chronomètre
START_TIME=$(date +%s)

# Chemin vers le fichier CSV
#CSV_FILE="data.csv"


OUTPUT_FILE="top_conducteurs.txt"


# Extraire les conducteurs et le nombre de trajets, puis sélectionner les 10 premiers
# Utiliser ';' comme séparateur de champs
awk -F ';' 'NR > 1 { cle=$6";"$1; if (!(cle in tableau_conducteur)) { tableau_conducteur[cle] = 1; compteur[$6]++; }} END { for (conducteur in compteur) { print compteur[conducteur] " " conducteur; }}' "$CSV_FILE" | sort -k1,1nr | head -n10 > "$OUTPUT_FILE"



# Fichier de données
DATA_FILE="top_conducteurs.txt"

# Sauvegarder temporairement les données inversées
tac "$DATA_FILE" > temp.txt && mv temp.txt "$DATA_FILE"


# Arrêter le chronomètre
END_TIME=$(date +%s)

# Calculer le temps d'exécution
ELAPSED_TIME=$(($END_TIME - $START_TIME))

echo "Temps d'exécution: $ELAPSED_TIME secondes"


gnuplot -p plot1.gp
