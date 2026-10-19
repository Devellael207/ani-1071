#include <cstdio>
#include <cmath>
using Fonction = double (*)(double);
double carre(double x) {
    return x * x;
}
double f_exo(double x) {
    return x * x - 2.0;
}
double integrale(Fonction f, double a, double b) {
double pas = (b - a) / 1000.0;
double somme = 0.0;
for (int i = 0; i < 1000; ++i) {
 double x = a + i * pas;
somme += f(x) * pas;
    }
return somme;
}
double derivee(Fonction f, double x) {
double h = 1e-6;
    return (f(x + h) - f(x - h)) / (2.0 * h);
}
double zero(Fonction f, double a, double b) {
double m = a;
for (int i = 0; i < 50; ++i) {
m = (a + b) / 2.0;
if (f(m) == 0.0) {
 break;
}
 if (f(a) * f(m) < 0) {
 b = m;
 } else {
 a = m;
 }
}
    return m;
}

int main() {
double res_sin = integrale(sin, 0.0, 3.14159);
double res_carre = integrale(carre, 0.0, 1.0);
printf("Integrale sin : %f\n", res_sin);printf("Integrale carre : %f\n", res_carre);
 double der_sin = derivee(sin, 0.0);
printf("Derivee sin en 0 : %f\n", der_sin);
double racine = zero(f_exo, 1.0, 2.0);
printf("Zero de x*x - 2 : %f (sqrt(2) = %f)\n", racine, sqrt(2.0));

    return 0;
}