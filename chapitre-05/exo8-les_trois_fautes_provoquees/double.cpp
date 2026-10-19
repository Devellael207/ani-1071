#include <cstdio>

int main() {
    int* tab = new int[10];
    tab[0] = 123;
    delete[] tab;
    delete[] tab; 
    
    return 0;
}