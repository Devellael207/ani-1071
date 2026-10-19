#include <cstdio>
#include <cstring>
int somme(const int* t, int n) {
int total = 0;
const int* fin = t + n;
while (t < fin) {
    total += *t;
    t++;
    }
return total;
}
int maximum(const int* t, int n) {
if (n <= 0) return 0;
int max_val = *t;
const int* fin = t + n;
t++;
while (t < fin) {
     if (*t > max_val) {
         max_val = *t;
     }
    t++;
}
return max_val;
}
void inverser(int* t, int n) {
int* debut = t;
int* fin = t + n - 1;
while (debut < fin) {
int temp = *debut;
*debut = *fin;
*fin = temp;
debut++;
fin--;
    }
}
int longueur(const char* s) {
const char* p = s;
while (*p != '\0') {
    p++;
    }
    return p - s; 
}

int main() {
int tab[] = {12, 7, 19, 3, 15};
int n = 5;
printf("Somme = %d\n", somme(tab, n));
printf("Maximum = %d\n", maximum(tab, n));
int tab_inv[] = {1, 2, 3, 4, 5};
printf("Avant inversion : %d %d %d %d %d\n", tab_inv[0], tab_inv[1], tab_inv[2], tab_inv[3], tab_inv[4]);
inverser(tab_inv, 5);
printf("Apres inversion : %d %d %d %d %d\n", tab_inv[0], tab_inv[1], tab_inv[2], tab_inv[3], tab_inv[4]);
const char* s1 = "bonjour";
const char* s2 = "Yaoundé";
printf("longueur(\"bonjour\") = %d, strlen = %lu\n", longueur(s1), strlen(s1));
printf("longueur(\"Yaoundé\") = %d, strlen = %lu\n", longueur(s2), strlen(s2));

    return 0;
}