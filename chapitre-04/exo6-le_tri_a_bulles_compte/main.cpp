#include <iostream>

using namespace std;
long long trierParBulles(int t[], int n) {
    long long nbEchanges = 0;
    bool change = true;
    while (change) {
        change = false;
        for (int i = 0; i < n - 1; i++) {
            if (t[i] > t[i + 1]) {
                int temp = t[i];
                t[i] = t[i + 1];
                t[i + 1] = temp;
                 nbEchanges++;
                change = true;
            }
        }
    }
    return nbEchanges;
}
int main() {
    int n;
    if (!(cin >> n)) return 0;
    if (n == 0) {
    cout << "AUCUN" << endl;
    cout << 0 << endl;
        return 0;}
        int t[1000];
for (int i = 0; i < n; i++) {
 cin >> t[i]; }
    long long echanges = trierParBulles(t, n);
for (int i = 0; i < n; i++) {
cout << t[i] << endl;
    }
cout << echanges << endl;
return 0;
}