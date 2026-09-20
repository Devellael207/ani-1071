DEMONSTRATION:L'exécutable ne dépend plus du code source 

fichier utilser pour la démonstation:Fichier c1-demo1_main.cpp (qui est notre programme ci dessous)

#include <stdio.h>
int main(){
    printf("Kuete\n");
    printf("Yaoundé\n");
    return 0;
}

Nous allons compile notre fichier pou verifier son fonctionnement sachant que son code source n'a pas été encore supprimer:

compilation du fichier c1-demo1_main.cpp:

 clang++ -std=c++17 -Wall c1-demo1_main.cpp -o programme

 puis lancement de l'executable:.\programme

 resultat:

 Kuete
Yaoundé

on constate que tout c'est bien passer le fichier à été compile et execute sans probleme avec son code source(fichier utilisé).maintenant pou poursuivre la consigne de notre devoir nous allons demontrer que sans le code source l'executable fonctionne toujours:

supprimons le code source :

rm c1-demo1_main.cpp

puis maintenant relançons l'excecutable:

.\programme

resultat:

Kuete
Yaoundé

On constate qu'il n'a pas eu de probleme au niveau de l-execution

En conclusion cela prouve que l'exécutable est un fichier autonome et complet: on peut donc dire que le compilateur a traduit le code source en 'instructions machine' directement compréhensibles par le processeur,et cette traduction est entierement contenu dans ce qu'on va appelr le binaire final.On peut donc dire ainsi que le fichier source n'est qu'un intermediaire utile à la compilation,pas une dépendance d'execution.mais la vrai remarque qui attire mon attention est que recemment j'ai pu constaté que l'utilisateur reçoit uniquement le binaire,qu'il faut pour faire fonctionner le programme,sans jamais avoir accès au programme interne ecrit par les developpeur.