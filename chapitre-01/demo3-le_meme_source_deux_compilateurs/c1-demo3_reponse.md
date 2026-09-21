LE MEME SOURCE,DEUX COMPILATEUR
Lors de mon devoir j'ai utilisé clang++(version 22.1.8) et le g++(version 16.2.0) comme élément de comparaison .Alors je me suis servie de mon code source (demo3_main.cpp)

code source(demo3_main.cpp):

#include <stdio.h>
int main(){
    printf("Kuete\n");
    printf("Yaoundé\n");
    return 0;
}

par la suite compilons ce fichier avec clang++ et g++

clang++ -std=c++17 -Wall demo3_main.cpp -o programme_clang++

g++ -std=c++17 -Wall demo3_main.cpp -o programme_g++

maintenant à partir de la commande (dir) nous allons evaluer d'abord la taille des 2 compilation :

PS C:\Users\TECH-STORE CMR\Documents\ani-1071\chapitre-01\demo3-le_meme_source_deux_compilateurs> dir

resultat:

Répertoire: C:\Users\TECH-STORE 
    CMR\Documents\ani-1071\chapitre-01\demo3-le_meme_source_deux_compilateurs


Mode                 LastWriteTime         Length Name                                                     
----                 -------------         ------ ----                                                     
-a----        18/09/2026     18:15            100 demo3_main.cpp                                           
-a----        21/09/2026     00:14          37990 programme_clang++.exe                                    
-a----        21/09/2026     00:16          38953 programme_g++.exe                                        


nous pouvons constater qu'il y a une difference de taille(length)
Taille de programme_clang.exe : 37990 o
Taille de programme_g++.exe: 38953 o
Mais verifions aussi si en lançant les 2 executable si la meme chose s'affiche:

 .\programme_clang++

 resultat:
Kuete
Yaoundé

.\programme_g++

resultat:
Kuete
Yaoundé

CONCLUSION:Malgrés la difference de taille ,les deux executables produisent exactement le meme resultat visible .cela nous montre que le language C++ garantit le comportement du programme(ce qu'il doit faire,la norme du langage) mais il ne garantit non plus l'implementation.On diras donc que chaque compilateur est libre de traduire le code source en instruction machine differentes avec ses prpopre dependance d'où la difference de taille entre les 2.


