#include <cstdio>

int main() {
    int* tab = new int[10];
    tab[0] = 42;
    delete[] tab;
    printf("Valeur lue apres suppression : %d\n", tab[0]);
    
    return 0;
}