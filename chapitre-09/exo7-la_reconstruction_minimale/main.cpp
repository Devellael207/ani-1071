#include <iostream>
#include <string>
#include <vector>

int main() {
    int nombreCibles = 0;
    if (!(std::cin >> nombreCibles)) {
        return 0;
    }
std::vector<std::string> noms(nombreCibles);
std::vector<int> dates(nombreCibles);
std::vector<bool> reconstruire(nombreCibles, false);
int totalReconstruire = 0;
int totalAJour = 0;
for (int i = 0; i < nombreCibles; ++i) {
int nombreDependances = 0;
std::cin >> noms[i] >> dates[i] >> nombreDependances;
if (dates[i] == -1) {
 reconstruire[i] = true;
}
for (int j = 0; j < nombreDependances; ++j) {
std::string nomDependance;
std::cin >> nomDependance;
for (int k = 0; k < i; ++k) {
if (noms[k] == nomDependance) {
if (dates[k] >= dates[i] || reconstruire[k]) {
reconstruire[i] = true;
}
 }
 }
 }if (reconstruire[i]) {
std::cout << noms[i] << " A RECONSTRUIRE\n";
totalReconstruire++;
 } else {
std::cout << noms[i] << " A JOUR\n";
totalAJour++;
    }
}
std::cout << "A RECONSTRUIRE " << totalReconstruire << "\n";
std::cout << "A JOUR " << totalAJour << "\n";
return 0;
}