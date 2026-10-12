#include <iostream>
#include <fstream>
using namespace std;
char tuile(const char carte[], int largeur, int x, int y) {
    return carte[y * largeur + x];}

int compter(const char carte[], int largeur, int hauteur, char quoi) {
    int total = 0;
    int taille = largeur * hauteur;
    for (int i = 0; i < taille; i++) {
        if (carte[i] == quoi) {
            total++;
        }
    }
    return total;
}

int main() {
    ifstream fichier("carte.txt");
    if (!fichier) {
        cerr << "Erreur d'ouverture du fichier carte.txt" << endl;
        return 1;
    }

    int largeur, hauteur;
    if (!(fichier >> largeur >> hauteur)) return 1;
    char carte[1000];
    int index = 0;
    for (int y = 0; y < hauteur; y++) {
        for (int x = 0; x < largeur; x++) {
            fichier >> carte[index];
            index++;}
    }
    fichier.close();
    ofstream sortie("sortie.txt");
    if (!sortie) {
        cerr << "Erreur de creation du fichier sortie.txt" << endl;
        return 1;}
    for (int y = 0; y < hauteur; y++) {
    for (int x = 0; x < largeur; x++) {
    sortie << tuile(carte, largeur, x, y);}
    sortie << endl;}
    sortie << ". : " << compter(carte, largeur, hauteur, '.') << endl;
    sortie << "# : " << compter(carte, largeur, hauteur, '#') << endl;
    sortie << "~ : " << compter(carte, largeur, hauteur, '~') << endl;
    sortie << "Tuile en (3, 2) : " << tuile(carte, largeur, 3, 2) << endl;
    sortie.close();
    return 0;
}