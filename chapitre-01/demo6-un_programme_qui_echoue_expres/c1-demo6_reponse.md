# UN COMPILATEUR QUI ECHOUE EXPRES
Compilateur utilisé : clang++
## programme
 le programme que j"ai ecrit se trouve dans (c1-demo6_main.cpp)
 #include <iostream>

int main() {
    int n;
    std::cin >> n;
    return (n % 2 == 0) ? 0 : 1 ;
}
 ### DEMONSTATION 
 |entrée            | code de sortie attendu  | code de sortie obtenu |
 |------------------|-------------------------|-----------------------|
 |4                 |0(pair)                  |0                      |
 |7                 |1(impair)                |1                      |
 |10                |0(pair)                  |0                      |
 |3                 |1(impair)                |1                      |
 
 En coclusion le programme se comporte comme prévu à chaque essai:le code de sortie vaut 0 pour un nombre pair et 1 pour un nombre impair, sans jamais afficher de message.