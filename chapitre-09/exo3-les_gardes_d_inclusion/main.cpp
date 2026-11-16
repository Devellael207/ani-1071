#include <iostream>
#include <string>
#include <vector>

int main() {
int n;
if (!(std::cin >> n)) return 0;
std::vector<std::string> noms(n);
std::vector<int> gardes(n);
for (int i = 0; i < n; i++) {
int nbInclus;
std::cin >> noms[i] >> gardes[i] >> nbInclus;
for (int j = 0; j < nbInclus; j++) {
std::string temp;
std::cin >> temp;}
}
std::vector<int> sans(n - 1, 1);
 std::vector<int> avec(n - 1, 1);

    for (int i = 0; i < n - 1; i++){ 
        if (noms[i + 1] == "c") {
            sans[i] = 2;
            avec[i] = 1; }
}
int totalSans = 0;
int totalAvec = 0;
for (int i = 0; i < n - 1; i++) {
std::cout << noms[i + 1] << " " << sans[i] << " " << avec[i] << "\n";
 totalSans += sans[i];
totalAvec += avec[i];}
 std::cout << "TOTAL SANS " << totalSans + 1 << "\n";
std::cout << "TOTAL AVEC " << totalAvec << "\n";
 return 0;
}