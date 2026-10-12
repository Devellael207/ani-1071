#include <iostream>
#include <fstream>
using namespace std;
int voisinsVivants(const char g[], int largeur, int hauteur, int x, int y) {
    int count = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            // Règle de bord : les cellules hors grille comptent comme mortes ('.')
            if (nx >= 0 && nx < largeur && ny >= 0 && ny < hauteur) {
                if (g[ny * largeur + nx] == '#') {
                count++;}
            }
        }
    }
    return count;
}

int main() {
    int largeur = 25;
    int hauteur = 25;
    char grilleA[1000];
    char grilleB[1000];
    for (int i = 0; i < largeur * hauteur; i++) {
        grilleA[i] = '.';
    }
    int startX = 1;
    int startY = 1;
    grilleA[(startY) * largeur + (startX + 1)] = '#';
    grilleA[(startY + 1) * largeur + (startX + 2)] = '#';
    grilleA[(startY + 2) * largeur + (startX)] = '#';
    grilleA[(startY + 2) * largeur + (startX + 1)] = '#';
    grilleA[(startY + 2) * largeur + (startX + 2)] = '#';
    ofstream fichier("generations.txt");
    if (!fichier) {
        cerr << "Erreur d'ouverture du fichier generations.txt" << endl;
        return 1;
    }
    for (int gen = 0; gen < 10; gen++) {
        fichier << "generation " << gen << endl;
        for (int y = 0; y < hauteur; y++) {
            for (int x = 0; x < largeur; x++) {
                fichier << grilleA[y * largeur + x];
            }
            fichier << endl;
        }
        for (int y = 0; y < hauteur; y++) {
            for (int x = 0; x < largeur; x++) {
                int index = y * largeur + x;
                int vivants = voisinsVivants(grilleA, largeur, hauteur, x, y);
                char cellule = grilleA[index];

                if (cellule == '#') {
                
                    if (vivants == 2 || vivants == 3) {
                        grilleB[index] = '#';
                    } else {
                        grilleB[index] = '.';
                    }
                } else {
                
                    if (vivants == 3) {
                        grilleB[index] = '#';
                    } else {
                        grilleB[index] = '.';
                    }
                }
            }
        }
        for (int i = 0; i < largeur * hauteur; i++) {
            grilleA[i] = grilleB[i];
        }
    }

    fichier.close();
    return 0;
}