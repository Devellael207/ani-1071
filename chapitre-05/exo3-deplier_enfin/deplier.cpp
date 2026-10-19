#include <cstdio>

void deplier(int i, int largeur, int& x, int& y) {
    x = i % largeur;
    y = i / largeur;
}
void minMax(const int t[], int n, int& min, int& max) {
    if (n <= 0) return;
    min = t[0];
    max = t[0];
    for (int i = 1; i < n; ++i) {
        if (t[i] < min) {
            min = t[i];
        }
        if (t[i] > max) {
            max = t[i];
        }
    }
}
bool diviser(int a, int b, int& quotient, int& reste) {
    if (b == 0) {
        return false; 
    }
    quotient = a / b;
    reste = a % b;
    return true;
}

int main() {
int largeur = 40;
 int x = -1, y = -1;
deplier(0, largeur, x, y);
printf("deplier(0) -> x = %d, y = %d\n", x, y);
    
deplier(39, largeur, x, y);
printf("deplier(39) -> x = %d, y = %d\n", x, y);
deplier(40, largeur, x, y);
printf("deplier(40) -> x = %d, y = %d\n", x, y);
int tab[] = {12, 7, 19, 3, 15};
int mn = 0, mx = 0;
minMax(tab, 5, mn, mx);
printf("minMax -> min = %d, max = %d\n", mn, mx);
int q = 0, r = 0;
bool ok1 = diviser(17, 5, q, r);
printf("diviser(17, 5) -> succes = %d, quotient = %d, reste = %d\n", ok1, q, r);
bool ok2 = diviser(-20, 6, q, r);
printf("diviser(-20, 6) -> succes = %d, quotient = %d, reste = %d\n", ok2, q, r);
int valeur_initiale_q = 999;
int valeur_initiale_r = 888;
q = valeur_initiale_q;
r = valeur_initiale_r;
bool ok3 = diviser(10, 0, q, r);
printf("Par zero : succes = %d, quotient = %d, reste = %d\n", ok3, q, r);

    return 0;
}