#include <cstdio>

double vitesse(double v0, double a, double t) {
    return v0 + a * t;
}

double position(double x0, double v0, double a, double t) {
    return x0 + v0 * t + 0.5 * a * t * t;
}

int main() {
    double x0, v0, a, t;
    scanf("%lf %lf %lf %lf", &x0, &v0, &a, &t);
    printf("%.4f\n", vitesse(v0, a, t));
    printf("%.4f\n", position(x0, v0, a, t));
    return 0;
}
