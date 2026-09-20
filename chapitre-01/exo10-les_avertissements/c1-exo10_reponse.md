LES AVERTISSEMENTS (la difference entre un avertissement et une erreur )

commande:
clang++ -std=c++17 -Wall -Wextra c1-exo10_main.cpp -o progamme

resultat:

c1-exo10_main.cpp:4:9: warning: unused variable 'variable_gamme_programming' [-Wunused-variable]
    4 |     int variable_gamme_programming = 45;
      |         ^~~~~~~~~~~~~~~~~~~~~~~~~~
1 warning generated.
Le progamme a été compilé normalement et l'executable a été bien crée (programme.exe) et ce malgré cet avertissement .

la difference entre un avertissement et une erreur :

Une ERREUR bloque complètement la compilation : le compilateur refuse de produire un exécutable tant que l'erreur n'est pas corrigée.c'est le cas quand le code ne respecte pas les règles du language (syntaxe incorrecte,référence à quelque chose d'inexistant).Par exemple je vais faire expres de faire une erreur à fin qu'on puisse faire plus de differece meme au niveau du message d'erreur afficher:le nom du fichier de mon programme pour cree l'erreur est c1-exo10_erreur.cpp :
Compilation du fichier d'erreur:
Clang++ -std=c++17 -Wall -Wextra c1-exo10_erreur.cpp -o programme_erreur

resultat:

c1-exo10_erreur.cpp:4:25: error: expected ';' after expression
    4 |     printf("erreur++\n")
      |                         ^
      |                         ;
1 error generated.

Ici,aucun exécutable n'a été crée(contrairement au cas de l'avertissement) :la commande 'dir' confirme l'abscence de 'programme_erreur.exe'. Ceci illustre bien la difference,conclusion l'erreur empeche totalement la comilation,l'avertissement non.

Un AVERTISSEMENT n'empeche pas la compilation :le programme est quand meme produit et fonctionne .Il signale simplement quelque chose de suspect ou d'inhabituel dans le code(ici par exemple une variable declaree mais jamais utilisée),mais il est important de noté qu'il ne sagis pas d'une faute de syntaxe,mais qui pourrait indiquer une erreur liéé au programmeur(donc supposons moi) il peut donc sagir (d'une variable oubliée,un code qui ne sert à rien...).

on peut alors se poser la question pourquoi l'avertissement existe vu qu'il ne bloque rien ? Alors je dirais que c'est pour permettre a celui qui ecris le code (programmeur) de répere des oublie ou des maladresse avant qu'elle ne devient un vrai probleme plutard mais tous cela sans bloqué la suite du travaille.