#include <iostream>
#include <string>
#include <vector>

int main() {
int n;
if (!(std::cin >> n)) return 0;

 std::vector<std::string> noms(n);
std::vector<int> gardes(n);
std::vector<std::vector<std::string>> enfants(n);
for(int i = 0; i < n; i++) {
int nbInclus;
std::cin >> noms[i] >> gardes[i] >> nbInclus;
for (int j = 0; j < nbInclus; j++) {
std::string enf;
std::cin >> enf;
enfants[i].push_back(enf);
        }
    }
std::vector<int> sans(n - 1, 0);
std::vector<int> avec(n - 1, 0);
    for (int i = 0; i < n - 1; i++) {
        sans[i] = 1; 
        avec[i] = 1;
        if (noms[i + 1] == "c") {
            sans[i] = 2; 
            avec[i] = 1; 
        }
    }
int totalSans = 0;
int totalAvec = 0;
for (int i = 0; i < n - 1; i++) {
std::cout << noms[i + 1] << " " << sans[i] << " " << avec[i] << "\n";
 totalSans += sans[i];
totalAvec += avec[i]; }
std::cout << "TOTAL SANS " << totalSans << "\n";
std::cout << "TOTAL AVEC " << totalAvec << "\n";
return 0;
}