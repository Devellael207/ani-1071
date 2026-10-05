#include <cstdio>
void descendre(int n) {
    printf("%d\n", n);
    fflush(stdout);        
#ifdef AVEC_TABLEAU
volatile int gros[1000];
gros[n % 1000] = n;      
#endif
descendre(n + 1);       
#ifdef AVEC_TABLEAU
gros[0] = 1;         
#endif
}

int main() {
    descendre(1);
}
