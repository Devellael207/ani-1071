#include <cstdio>

int main() {
    for (int i = 0; i < 1000; ++i) {
        int* tab = new int[1000];
        (void)tab; 
    }
    printf("Boucle de fuite terminee.\n");
    return 0;
}