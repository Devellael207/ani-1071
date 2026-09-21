MESURE LE COUT DES ETAPES
compilateur utilisé: clang++ (mesures via 'Measure-Command sous PowerShell)

|Fichier                |-E(preprocesseur)  |-c(compilateur)     | complet(avec link)     |
|-----------------------|-------------------|--                  |                        |                       
|programme normal       |0.0533s            |0.0442s             |0.2100s                 |                        
|Avec 10 entete         |0.0480s            |0.0418s             |0.0366s                 |
Observation 
Sur le programme normal,l'ordre est cohérent avec la theorie:la compilation complete (0.2100 s) domine, car elle inclut le travail de '-c' en plus de l'etape de link( resolution des symboles, generation de l'executable).

Sur le fichier à 10 en-tetes en revanche, la compilation complète (0.0366 s) apparait plus rapide que '-c' seul (0.0418 s), ce qui est illogique : le link s'ajoute forcemen au travail de compilation, il ne peut pas le rendre plus rapide.Cette anomalie vient tres problablement du bruit de mesure plutot que d'un effet réel du code : le premier executable genere dans le dossier à surement été scanner avant .En conclusion la tendance  reste que d'utilsation du (-c) est celle qui pèse le plus lourd dans le cout total et que l'ajout de 10 entete alourdit surtout le preprocesseur(-E),sans changement total sur -c.
ici joint les 6 lignes de commande de commande que j'ai du executé:

Measure-Command { clang++ -E c1-demo5_main.cpp -o c1-demo5_main.i }
Measure-Command { clang++ -c c1-demo5_main.cpp -o c1-demo5_main.o }
Measure-Command { clang++ c1-demo5_main.cpp -o c1-demo5_main.exe } 
Measure-Command { clang++ -E c1-demo5_main_10headers.cpp -o c1-demo5_main_10headers.i } 
Measure-Command { clang++ c1-demo5_main_10headers.cpp -o c1-demo5_main_10headers.o }
Measure-Command { clang++ c1-demo5_main_10headers.cpp -o c1-demo5_main_10headers.exe } 