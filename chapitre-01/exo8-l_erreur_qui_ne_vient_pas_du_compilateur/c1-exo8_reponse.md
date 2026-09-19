L'ERREUR QUI NE VIENT PAS DU COMPILATEUR


Compilation avec (-c):

> clang++ -c c1-exo8_main.cpp

(Aucune erreur,la compilation a doc reussit)

Compilation sans (-c):

> clang++ -std=c++17 -Wall c1-exo8_main.cpp -o programme

C:/msys64/ucrt64/bin/ld: C:/Users/TECH-S~1/AppData/Local/Temp/c1-exo8_main-656fc5.o:c1-exo8_main.cpp:(.text+0x17): undefined reference to `calculer()'
clang++: error: linker command failed with exit code 1 (use -v to see invocation)

On observe que la premier commande (-c) reussit car on voit l'apparition d'un fichier objet (c1-exo8_main.o) de plus cette ligne de compilation ne demande uniquement l'intervention du compilateur.il ne cherche donc pas par consequent si notre fonction 'int calculer' existe ou pas il compile seulement et rien d'autre.
La deuxieme commande sans (-c) il y'a pas de reussite car le message d'erreur specifie ceux ci:clang++: error: linker command failed with exit code 1 (use -v to see invocation) cela montre la partir où le liker(edition de liens) devais prendre la suite de l'execution n'a pas eu lieu car comme on peut le voir dans le message: undefined reference to `calculer()'cela signifie que la fonction a été declarer mais n'as jamais été definie .
on conclue donc que dans la premier commande c'est le compilateur qui parle mais dans la commande c'est le liker qui agis(parle) c'est pourquoi sur le message on peut voir:linker command failed ce qui signifie 'la commande liker a echouer'.