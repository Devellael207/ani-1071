#include <iostream>
using namespace std;
void cribler(bool premier[], int n) {
    for (int i = 0; i <= n; i++) {
        premier[i] = true;
    }
    if (n >= 0) premier[0] = false;
    if (n >= 1) premier[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (premier[i]) {
            for (int j = i * i; j <= n; j += i) {
                premier[j] = false;}
            }
        }
    }
int main() {
    int n;
    if (!(cin >> n)) return 0;
    if (n < 2) {
        cout << "AUCUN" << endl;
        return 0;
    }
    bool premier[100005];
    cribler(premier, n);
    for (int i = 2; i <= n; i++) {
    if (premier[i]) {
    cout << i << endl;}
        }
    return 0;
}