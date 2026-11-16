#include <iostream>
#include <string>

int main() {
    int nombreAssertions = 0;
    if (!(std::cin >> nombreAssertions)) {
        return 0;
    }
int reussis = 0;
int echoues = 0;
for(int numero = 1; numero <= nombreAssertions; ++numero) {
std::string type;
int attendu = 0;
 int obtenu = 0;
std::cin >> type >> attendu >> obtenu;
 bool succes = false;
if (type == "EQUAL" && attendu == obtenu) {
succes = true;
} else if (type == "NOT_EQUAL" && attendu != obtenu) {
 succes = true;
 } else if (type == "LESS" && attendu < obtenu) {
succes = true;
 } else if (type == "GREATER" && attendu > obtenu) {
succes = true;}
if (succes) {
std::cout << "cas " << numero << " OK\n";
reussis++;
 } else {
std::cout << "cas " << numero << " ECHEC attendu " << attendu << " obtenu " << obtenu << "\n";
echoues++;}
    }
std::cout << "REUSSIS " << reussis << "\n";
std::cout << "ECHOUES " << echoues << "\n";
if (echoues == 0) {
std::cout << "VERDICT VERT\n";
} else {
std::cout << "VERDICT ROUGE\n";}

  return 0;
}