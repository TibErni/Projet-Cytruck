#!/bin/bash
echo "fichier csv : $1"
CSV_FILE=$1

# Démarrer le chronomètre
START_TIME=$(date +%s)

# Chemin vers le fichier CSV
#CSV_FILE="data.csv"

# Fichier de sortie pour les trajets
TRAJETS_FILE="trajets.txt"

# Fichier de sortie pour l'histogramme
OUTPUT_GRAPH="D3.png"

# Calculez la distance totale pour chaque trajet et ajoutez un index séquentiel
awk -F';' 'NR > 1 {trajet[$1] += $5} END {for (t in trajet) print t, trajet[t]}' "$CSV_FILE" | sort -k2nr | head -10 | sort -k1n | awk '{print NR " " $0}' > "$TRAJETS_FILE"

# Commande Gnuplot mise à jour pour utiliser l'index séquentiel
gnuplot -e "
    set terminal png size 800,600;
    set output '$OUTPUT_GRAPH';
    set style fill solid 1.0 border -1;
    set boxwidth 0.5 relative;
    set xlabel 'ROUTE ID';
    set ylabel 'Distance (Km)';
    set xtics rotate by -45 font ',8';
    set title 'Option -I : Distance = f(Route)';
    plot '$TRAJETS_FILE' using 1:3:xticlabels(2) with boxes notitle lt rgb 'blue';
"


# Arrêter le chronomètre
END_TIME=$(date +%s)

# Calculer le temps d'exécution
ELAPSED_TIME=$(($END_TIME - $START_TIME))

echo "Temps d'exécution: $ELAPSED_TIME secondes"


