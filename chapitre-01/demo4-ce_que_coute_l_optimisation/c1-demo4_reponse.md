CE QUE COUT L'OPTIMISATION

Dans ce devoir on a utilise 02 programmes (c1-demo4_main.cpp et c1-demo4_million.cpp) .Dans la premiere partir du devoir nous travailler avec (c1-demo4_main.cpp) afin de determiner la taille des fichier lors de la compilation avec (-02) et sans:

c1-demo4_main.cpp:

#include <stdio.h>
int main(){
    printf("Kuete\n");
    printf("Yaoundé\n");
    return 0;
}

compilation:

 clang++ -std=c++17 -Wall c1-demo4_main.cpp -o programme_normal
 clang++ -std=c++17 -Wall -02 c1-demo4_main.cpp -o programme_optimise 

 puis nous verifions la taille avec la commande (dir)

resultat:

Répertoire : C:\Users\TECH-STORE CMR\Documents\ani-1071\chapitre-01\demo4-ce_que_coute_l_optimisation


Mode                 LastWriteTime         Length Name                                                                                                                         
----                 -------------         ------ ----                                                                                                                         
-a----        18/09/2026     18:15            100 c1-demo4_main.cpp                                                                                                            
-a----        21/09/2026     01:30          37990 programme_normal.exe                                                                                                         
-a----        21/09/2026     01:35          37990 programme_optimise.exe                                                                                                       


On constate qu'avec ou sans le -o2 les fichiers on toujours lameme taille

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

ici doc nous allons compilé et determiner temps d'execution de la compilation avec et sans -o2:

temps d'execution sans -o2:

 clang++ -std=c++17 -Wall c1-demo4_million.cpp -o million_normal

 Measure-Command { .\million_normal }

 Days              : 0
Hours             : 0
Minutes           : 0
Seconds           : 23
Milliseconds      : 284
Ticks             : 232844300
TotalDays         : 0,000269495717592593
TotalHours        : 0,00646789722222222
TotalMinutes      : 0,388073833333333
TotalSeconds      : 23,28443
TotalMilliseconds : 23284,43


temps d'execution avec -o2

clang++ -std=c++17 -Wall -o2 c1-demo4_main.cpp -o programme_optimise

Measure-Command { .\million_optimise }

Days              : 0
Hours             : 0
Minutes           : 0
Seconds           : 22
Milliseconds      : 852
Ticks             : 228524919
TotalDays         : 0,000264496434027778
TotalHours        : 0,00634791441666667
TotalMinutes      : 0,380874865
TotalSeconds      : 22,8524919
TotalMilliseconds : 22852,4919


 On constate que le temps d'execution des 2 compilations sont different

 En conclusion sur le programme simple(c1-demo4_main.cpp) ,l'option -o2 change peut la taille  de l'executable.par aillieur,sur le programme qui fais (c1-demo4_million.cpp) qui etait un programme d'addition,-o2 réduit fortement le temps d'execution .Ce que le langage C++ garantit;c'est le resul.tat final du programme(le resutat de la somme est identique dans les deux cas).ce qu'il ne garantit pas;c'est la vistesse ni la taille de l'executable: c'est deux aspets dependent entierement des choix d'optimisation du compilateur,pas du language de lui-meme.