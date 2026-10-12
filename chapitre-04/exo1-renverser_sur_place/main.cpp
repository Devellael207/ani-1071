#include <iostream>
using namespace std;
void renverser(int t[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = t[i];
        t[i] = t[n - 1 - i];
        t[n - 1 - i] = temp; }
    }
    int main() {
    int n;
    if (!(cin >> n)) return 0;
    if (n == 0) {
        cout << "AUCUN" << endl;
        return 0;
    }
    int t[1000];
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    renverser(t, n);
    for (int i = 0; i < n; i++) {
        cout << t[i] << endl;
    }
    return 0;
}