#include "aire.h"
const double PI = 3.14159265358979323846;
double aireRectangle(double longueur, double hauteur) {
    return longueur * hauteur; }
double aireDisque(double rayon) {
    return PI * rayon * rayon;
}
double aireTriangle(double base, double hauteur) {
    return base * hauteur / 2;
}