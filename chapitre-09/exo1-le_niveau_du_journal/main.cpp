#include <iostream>
#include <string>

int main() {
std::string seuil;
std::cin >> seuil;
int n;
std::cin >> n;
int affiches = 0;
int filtres = 0;

for (int i = 0; i < n; i++) {
std::string testNiveau, mot;
 std::cin >> testNiveau >> mot;
int numero = 0;
if (seuil == "INFO") numero = 1;
if (seuil == "WARN") numero = 2;
 if (seuil == "ERROR") numero = 3;
 int niveau = 0;
if (testNiveau == "INFO") niveau = 1;
if (testNiveau == "WARN") niveau = 2;
if (testNiveau == "ERROR") niveau = 3;
if (niveau >= numero) {
 std::cout << testNiveau << " " << mot << "\n";
affiches++;
 } else {
filtres++;
    }
}

std::cout << "AFFICHES " << affiches << "\n";
std::cout << "FILTRES " << filtres << "\n";

    return 0;
}