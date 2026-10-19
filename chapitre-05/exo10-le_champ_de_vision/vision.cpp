#include <cstdio>
#include <cmath>
double scalaire(const double* a, const double* b, int n) {
double res = 0.0;
for (int i = 0; i < n; ++i) {
    res += a[i] * b[i];
    }
 return res;
}
double norme(const double* v, int n) {
return std::sqrt(scalaire(v, v, n));
}

void normaliser(double* v, int n) {
double nrm = norme(v, n);
if (nrm > 0.0) {
for (int i = 0; i < n; ++i) {
 v[i] /= nrm;
    }
 }
}
bool voit(const double* garde, const double* direction, const double* joueur) {
double v_joueur[2] = { joueur[0] - garde[0], joueur[1] - garde[1] };
double nrm = norme(v_joueur, 2);
if (nrm == 0.0) {
        return true; 
    }
normaliser(v_joueur, 2);
double produit = scalaire(direction, v_joueur, 2);
double cos_30 = std::cos(30.0 * 3.14159 / 180.0);
    return produit >= cos_30;
}

int main() {
double garde[2] = {0.0, 0.0};
double direction[2] = {0.0, 1.0} ; 
double devant[2] = {0.0, 5.0};
double cote[2] = {5.0, 0.0};
double derriere[2] = {0.0, -5.0};
double bord_dedans[2] = {2.5, 5.0}; 
double bord_dehors[2] = {3.5, 5.0};
printf("Devant : %d\n", voit(garde, direction, devant));
printf("Cote : %d\n", voit(garde, direction, cote));
printf("Derriere : %d\n", voit(garde, direction, derriere));
printf("Bord dedans : %d\n", voit(garde, direction, bord_dedans));
printf("Bord dehors : %d\n", voit(garde, direction, bord_dehors));
return 0;
}