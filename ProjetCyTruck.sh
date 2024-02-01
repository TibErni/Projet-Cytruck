#!/bin/bash

# Chemin du fichier CSV
echo "Entrez le chemin du fichier CSV :"
read CSV_FILE

# Vérification si le fichier CSV est fourni
if [ -z "$CSV_FILE" ]; then
    echo "Aucun fichier CSV fourni."
    exit 1
fi

# Création des dossiers nécessaires
mkdir -p progc data images temp demo

# Demander à l'utilisateur les traitements à effectuer
echo "Entrez les options de traitement (parmi -d1, -d2, -l) séparées par des espaces :"
read -ra OPTIONS

# Aucune option entrée
if [ ${#OPTIONS[@]} -eq 0 ]; then
    echo "Aucune option de traitement fournie."
    exit 1
fi

# Traitement des options
for option in "${OPTIONS[@]}"; do
    case "$option" in
        -d1)
            echo "Traitement D1 sélectionné"
            ./D1.sh "$CSV_FILE"
            ;;
        -d2)
            echo "Traitement D2 sélectionné"
            ./D2.sh "$CSV_FILE"
            ;;
        -l)
            echo "Traitement L sélectionné"
            ./L.sh "$CSV_FILE"
            ;;
        *)
            echo "Option inconnue: $option"
            ;;
    esac
done

echo "Traitement terminé."

