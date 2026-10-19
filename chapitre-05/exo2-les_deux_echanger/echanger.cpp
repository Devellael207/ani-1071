#include <cstdio>
void echanger(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void echanger(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void echangerDouble(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}
void echangerChar(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

int main() {
 int x = 1, y = 2;
printf("Avant echange pointeurs : x = %d, y = %d\n", x, y);
echanger(&x, &y); 
printf("Apres echange pointeurs : x = %d, y = %d\n", x, y);
printf("Avant echange references : x = %d, y = %d\n", x, y);
 echanger(x, y);  
printf("Apres echange references : x = %d, y = %d\n", x, y);
double d1 = 3.14, d2 = 6.28;
printf("Avant echange double : d1 = %.2f, d2 = %.2f\n", d1, d2);
echangerDouble(d1, d2);
printf("Apres echange double : d1 = %.2f, d2 = %.2f\n", d1, d2);
char c1 = 'A', c2 = 'B';
printf("Avant echange char : c1 = %c, c2 = %c\n", c1, c2);
echangerChar(c1, c2);
printf("Apres echange char : c1 = %c, c2 = %c\n", c1, c2);

    return 0;
}