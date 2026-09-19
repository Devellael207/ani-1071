 Compilation 1:
 >clang++ -std=c++17 -Wall c1-exo5_main.cpp -o essai_un
 
 (Aucune sortie, la compilation a reussi)

 Execution 1:

 > .\essai_un

 cours de game programming a ENSPY

 Compilation 2 :
 >clang++ -std=c++17 -Wall c1-exo5-main.cpp -o essai_deux

 (Aucune sortie:la compilation a reussi)

 Execution 2:
 > .\essai_deux
 
 cours de gamme programming a ENSPY

 
 En compilant le meme fichier source (c1-exo5_main.cpp) de manier succesive avec (-o essai_un) puis (-o essai_deux), les deux exécutables produits fonctionnent de façon identique et affiche aussi le meme résultat.
En conclusion cela nous montre que le nom du fichier source et le nom de l'exécutable sont totalement independants(donc ils ne sont pas liée).Ansi le compilateur ne base jamais le nom du programme sur le nom du fichier (.cpp) d'origine.c'est donc uniquement l'option (-o) qui determine le nom du fichier de sortie (c'est l'exemple le cas de essai_un et essai_deux dans notre devoir) peut importe le nom du fichier source utilisé .