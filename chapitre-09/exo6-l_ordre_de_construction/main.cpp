#include <iostream>
#include <string>
#include <vector>

int main() {
int nombreProjets = 0;
if (!(std::cin >> nombreProjets)) {
        return 0;
    }
std::vector<std::string> noms(nombreProjets);
std::vector<std::vector<std::string>> dependances(nombreProjets);
std::vector<bool> construit(nombreProjets, false);
for (int i = 0; i < nombreProjets; ++i) {
int nombreDependances = 0;
 std::cin >> noms[i] >> nombreDependances;
for (int j = 0; j < nombreDependances; ++j) {
std::string nomDependance;
 std::cin >> nomDependance;
 dependances[i].push_back(nomDependance);
        }
    }
std::vector<std::string> ordre;
while ((int)ordre.size() < nombreProjets) {
 bool projetConstruitCeTour = false;
for (int i = 0; i < nombreProjets; ++i) {
if (construit[i]) {
continue;
 }
bool pret = true;
for (const std::string& nomDependance : dependances[i]) {
bool dependanceTrouvee = false;
for (int k = 0; k < nombreProjets; ++k) {
if (noms[k] == nomDependance && construit[k]) {
 dependanceTrouvee = true;
}
 }
if (!dependanceTrouvee) {
pret = false;
 }
    }
if (pret) {
construit[i] = true;
ordre.push_back(noms[i]);
 projetConstruitCeTour = true;
break;
            }
        }
if (!projetConstruitCeTour) {
std::cout << "CYCLE\n";
std::cout << "PROJETS 0\n";
return 0;
    }
    }
for (const std::string& projet : ordre) {
 std::cout << projet << "\n";
    }
std::cout << "PROJETS " << ordre.size() << "\n";
 return 0;
}