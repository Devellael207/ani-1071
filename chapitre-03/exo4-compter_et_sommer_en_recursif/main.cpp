#include <iostream>
using namespace std;
int chiffresRecursif(int n) {
if (n < 0) return chiffresRecursif(-n); // on ramène le signe d'abord
if (n < 10) return 1;                   // cas d'arrêt : 0 a bien 1 chiffre
return 1 + chiffresRecursif(n / 10);
}
int sommeChiffresRecursif(int n) {
if (n < 0) return sommeChiffresRecursif(-n);
if (n == 0) return 0;                   // cas d'arrêt : somme nulle
return n % 10 + sommeChiffresRecursif(n / 10);
}

int main() {
int n;
bool aLuUnEntier = false;
while (cin >> n) {
 aLuUnEntier = true;
cout << chiffresRecursif(n) << "\n";
cout << sommeChiffresRecursif(n) << "\n"; }
if (!aLuUnEntier) cout << "AUCUN\n";
    return 0;
}