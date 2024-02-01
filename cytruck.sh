#!/bin/bash


while getopts 'ld:f:h' opt; do

  # Utilise une structure 'case' pour traiter chaque option
  case "$opt" in


    # Si l'option est 'f', traite le paramètre comme le chemin du fichier CSV
    f)
      arg="$OPTARG"  # Stocke l'argument de l'option 'f' dans une variable
      echo "Fichier data :  '${OPTARG}' "
      DATA_CSV=${OPTARG}  # Définit DATA_CSV avec le chemin du fichier CSV
      echo "le fichier à analyser est  : $DATA_CSV"
      ;;

    # Si l'option est 'd', traite le paramètre pour les scripts D1.sh ou D2.sh
    d)
      arg="$OPTARG"
      echo "Processing option 'd' with '${OPTARG}' argument"
      
      # Vérifie si l'argument de 'd' est '1' et exécute D1.sh
      if [[ "${OPTARG}" == "1" ]]; then
        ./D1.sh $DATA_CSV
      fi

      # Vérifie si l'argument de 'd' est '2' et exécute D2.sh
      if [[ "${OPTARG}" == "2" ]]; then
        ./D2.sh $DATA_CSV
      fi
      ;;
      
      
    # Si l'option est 'l', exécute le script L.sh
    l)
      echo "Processing option 'l'"
      ./L.sh $DATA_CSV
      ;;

    # Si une option inconnue ou 'h' est fournie, affiche l'usage du script
    ?|h)
      echo "Usage: $(basename $0) fichier_csv.csv [-d1] [-d2] [-l]"
      exit 1
      ;;

  esac

done

# Ajuste l'indice de l'option pour les arguments restants après les options traitées
shift "$(($OPTIND -1))"


echo $OPTIND

