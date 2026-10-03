#include <iostream>
using namespace std;
long long fibonacci(int n, long long& appels) {
appels++;                 // dès l'entrée, avant tout test
 if (n == 0) return 0;
if (n == 1) return 1;
return fibonacci(n - 1, appels) + fibonacci(n - 2, appels);
}

int main() {
int n;
cin >> n;
long long appels = 0;     // remise à zéro
long long resultat = fibonacci(n, appels);
cout << resultat << "\n" << appels << "\n";
return 0;
}
