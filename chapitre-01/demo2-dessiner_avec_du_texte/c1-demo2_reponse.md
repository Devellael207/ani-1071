DEMONSTRATION 2:DESSINER UN RECTANGLE SANS BOUCLE

Pour cela on a eu besoin du fichier source (c1-demo2_main.cpp) qui est notre programme de dessin du rectangle:

#include <stdio.h>
int main(){
    printf("####################\n");
    printf("#                  #\n");
    printf("#                  #\n");
    printf("#                  #\n");
    printf("#                  #\n");
    printf("#                  #\n");
    printf("####################\n");
    return 0;
}

puis pour verifier que le programme fonctionne vraiment j'ai compilé le fichier c1-demo2_main.cpp

compilation +executable:

 clang++ -std=c++17 -Wall c1-demo2_main.cpp -o programme
 .\programme

 resultat:

####################
#                  #
#                  #
#                  #
#                  #
#                  #
####################

Pour dessiner ce rectagle de 7 ligne sur 20 colonnes,il a fallu 7 appels à la fonction printf,un par ligne de dessin,puisque aucune boucle n'était autorisée.chaque ligne devait etre ecrire en dur dans le code : la ligne du haut et du bas sont identique(20 caractères '#')et les 5 lignes du milieu repete chacune lameme structure ('#', 18 espaces,'#').mais sans l'utilisation d'une boucle nous sommes oubligé de retaper a chaque fois.Donc le nombre de code  nécessaire est:7(une instruction printf par ligne du rectangle).