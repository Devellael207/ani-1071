CE QUE COUT L'OPTIMISATION

Dans ce devoir on a utilise 02 programmes (c1-demo4_main.cpp et c1-demo4_million.cpp) .Dans la premiere partir du devoir nous travailler avec (c1-demo4_main.cpp) afin de determiner la taille des fichier lors de la compilation avec (-O2) et sans:

c1-demo4_main.cpp:

#include <stdio.h>
int main(){
    printf("Kuete\n");
    printf("Yaoundé\n");
    return 0;
}

compilation:

 clang++ -std=c++17 -Wall c1-demo4_main.cpp -o programme_normal
 clang++ -std=c++17 -Wall -O2 c1-demo4_main.cpp -o programme_optimise 

 puis nous verifions la taille avec la commande (dir)

resultat:

Répertoire : C:\Users\TECH-STORE CMR\Documents\ani-1071\chapitre-01\demo4-ce_que_coute_l_optimisation


Mode                 LastWriteTime         Length Name                                                                                                                         
----                 -------------         ------ ----                                                                                                                         
-a----        18/09/2026     18:15            100 c1-demo4_main.cpp                                                                                                            
-a----        21/09/2026     01:30          37990 programme_normal.exe                                                                                                         
-a----        21/09/2026     01:35          37990 programme_optimise.exe                                                                                                       


On constate qu'avec ou sans le -O2 les fichiers on toujours lameme taille

Maintenant comme prevu dans cette partie nous allons maintenant utilise le fichier (c1-demo4_million.cpp)

programme c1-demo4_million.cpp:

#include <cstdio>

int main() {
    long somme = 0;
    for (int i = 0; i < 1000000; i++) {
        somme = somme + 1;
    }
    printf("Somme finale : %ld\n", somme);
    return 0;
}

ici doc nous allons compilé et determiner temps d'execution de la compilation avec et sans -O2:

temps d'execution sans -O2:

 clang++ -std=c++17 -Wall c1-demo4_million.cpp -o million_normal

 Measure-Command { clang++ -std=c++17 -Wall c1-demo4_million.cpp -o million_normal
  }

Days              : 0
Hours             : 0
Minutes           : 0
Seconds           : 0
Milliseconds      : 212
Ticks             : 2129350
TotalDays         : 2,46452546296296E-06
TotalHours        : 5,91486111111111E-05
TotalMinutes      : 0,00354891666666667
TotalSeconds      : 0,212935
TotalMilliseconds : 212,935
 


temps d'execution avec -O2

clang++ -std=c++17 -Wall -O2 c1-demo4_million.cpp -o million_optimise

Measure-Command { clang++ -std=c++17 -Wall -O2 c1-demo4_million.cpp -o million_optimise
}

Days              : 0
Hours             : 0
Minutes           : 0
Seconds           : 0
Milliseconds      : 192
Ticks             : 1929716
TotalDays         : 2,23346759259259E-06
TotalHours        : 5,36032222222222E-05
TotalMinutes      : 0,00321619333333333
TotalSeconds      : 0,1929716
TotalMilliseconds : 192,9716



 On constate que le temps d'execution des 2 compilations sont different

 En conclusion sur le programme simple(c1-demo4_main.cpp) ,l'option -O2  ne change pas la taille de l-executable les deux executable sont identique au niveau de la taille  de l'executable.par aillieur,sur le programme qui fais (c1-demo4_million.cpp) qui etait un programme d'addition,-O2 réduit un peut  le temps de compilation on n'est passer de 212,935 milliseconde à 192,9716 millisecondes .Ce que le langage C++ garantit;c'est le resultat final du programme(le resutat de la somme est identique dans les deux cas).ce qu'il ne garantit pas;c'est la vistesse ni la taille de l'executable: c'est deux aspets dependent entierement des choix d'optimisation du compilateur,pas du language de lui-meme.