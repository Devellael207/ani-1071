LE MASSACRE DU POINT VIRGULE


Sans aucun point-virgule

resultat: 2 erreurs générées

> clang++ -std=c++17 -Wall copie_massacre.cpp -o programme2.0

copie_massacre.cpp:4:14: error: expected ';' at end of declaration
    4 |     int a = 5
      |              ^
      |              ;
copie_massacre.cpp:5:14: error: expected ';' at end of declaration
    5 |     int b = 3
      |              ^
      |              ;
2 errors generated.

Avec un seul point-virgule remis à la ligne 4

resultat :1 erreur générée

> clang++ -std=c++17 -Wall copie_massacre.cpp -o programme2.0

copie_massacre.cpp:5:14: error: expected ';' at end of declaration
    5 |     int b = 3
      |              ^
      |              ;
1 error generated.

En remettant un seul point-virgule(voir le fichier (copie_massacre.cpp) ),on constate que seulement une seule erreur a disparu: celle exactement associée à la ligne où le point-virgule manquant a été corrigé .cela montre que chaque erreur de 'syntaxe' est liée à un endroit precis du code,et non à un compteur global.
on remarque aussi  meme si 4 points virgules manques au depart, au ligne 4,5,6,7 et meme 8 seules 2 erreurs  ont été signalées :ainsi donc le compilateur s'arrete de continuer son analyse au-dela d'un certain point,car trop d'erreur à la suite peuvent fausser l'interpretation du reste de code .