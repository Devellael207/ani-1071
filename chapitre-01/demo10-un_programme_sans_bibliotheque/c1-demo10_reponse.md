# UN PROGRAMME SANS BIBLIOTHEQUE 
Nous avons ecris et compiler le programme suivant:
int main() {
    

    return 7;
}

puis nous l'avons compilez:
 clang++ -std=c++17 -Wall c1-exo10_main.cpp -o programme
 puis nous avons mesurer la taille de l'executable en ko :

 ( Get-Item .\programme.exe ).Length / 1KB 
 resultat:
 36,783203125 
 pour notre devoir nous avons ecris et compiler aussi le programme suivant:

 #include <cstdio>


int main() {
    printf("bonjour\n");
    return 0;
}
puis nous compilons et mesurons la taille de l'executable:
clang++ -std=c++17 -Wall c1-bonjour_main.cpp -o programme1

clang++ -std=c++17 -Wall c1-bonjour_main.cpp -o programme1

resultat:

70,8798828125

On constate que le programme "c1-bonjour_main.cpp"a une taille de 70,879882815 ko contre 36,783203125 ko.Cette difference nous montre que la taille d'un programme depend aussi de la quantité d'instruction quelle contient par seulemnet du contenu de sa bibliotheque.Mais cependant une question se pose: pourquoi malgres le fait que notre programme ne contenant aucune instruction ni de bibliotheque ( c'est a dire sachant qu'on a enlever la ligne de #include) pourquoi il ce programme pèse autant ? pourquoi la difference de taille du entre nos deux programme n'est pas aussi grande sachant que le premier programme ne contient presque rien ?.Alors pour verifier cela j'ai ajouter #include au premier programme puis j'ai compilé et ensuite j'ai pésé a nouveau voila le  resultat:

#include <cstdio>


int main() {
     return 7;
}

puis je compile et je pese sa taille a nouveau

 clang++ -std=c++17 -Wall c1-exo10_main.cpp -o programme
  ( Get-Item .\programme.exe ).Length / 1KB 
  resuitat:
36,783203125

On remarque avec le ou sans le #include dans notre programme il a toujours la meme taille . En coclusion cela  montre la bibliotheque correspondant a notre probleme à été ajouter sans qu'on ne lui demande donc l'ajout de la bibliotheque se fait de automatique et c'est donc par l'action du "preprocesseur" que cela est fait.Donc de façon simple l'ajout de la bibliotheque se fait de manier automatque par le preprocesseur lors du traitement du dit programme. 