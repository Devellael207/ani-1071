#include <iostream>
using namespace std;
 int nombreDechiffres(int n) {
    if (n == 0) return 1;
    int compte = 0;
    while (n != 0) {
     n /= 10;
     ++compte;
    }
    return compte;
    }
    int main() {
        int n;
        bool aucun = true;
        while (cin >> n) {
        aucun = false;
        cout << nombreDechiffres(n) << "\n";
        }
       if (aucun) cout << "AUCUN\n";
        return 0;
    }