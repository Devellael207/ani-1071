#include <iostream>
using namespace std;
void tourner(int t[], int n, int k) {
    if (n <= 0) return;
    k = k % n;
    if (k < 0) {
        k = k + n;
    }
    int temp[1000];
    for (int i = 0; i < n; i++) {
        temp[i] = t[(i + k) % n];}
    for (int i = 0; i < n; i++) {
    t[i] = temp[i];}
    }
    int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;
    if (n == 0) {
    cout << "AUCUN" << endl;
    return 0;}
    int t[1000];
    for (int i = 0; i < n; i++) {
    cin >> t[i];
    }
    tourner(t, n, k);
    for (int i = 0; i < n; i++) {
    cout << t[i] << endl;
    }
    return 0;
}