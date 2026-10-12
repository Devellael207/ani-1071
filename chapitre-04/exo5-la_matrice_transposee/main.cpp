#include <iostream>
using namespace std;
void transposer(const int source[], int lignes, int colonnes, int destination[]) {
    for (int y = 0; y < lignes; y++) {
        for (int x = 0; x < colonnes; x++){
            int indexSource = y * colonnes + x;
            int indexDest = x * lignes + y;
            destination[indexDest] = source[indexSource];}
    }
}
int main() {
    int lignes, colonnes;
    if (!(cin >> lignes >> colonnes)) return 0;
    int source[10005];
    int destination[10005];
    for (int i = 0; i < lignes * colonnes; i++) {
        cin >> source[i];}
    transposer(source, lignes, colonnes, destination);
    for (int y = 0; y < colonnes; y++) {
    for (int x = 0; x < lignes; x++) {
    cout << destination[y * lignes + x];
            if (x < lignes - 1) {
cout << " ";} }
 cout << endl;}
 return 0;
}