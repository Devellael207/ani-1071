#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

// 1. Structure pour le tableau de structures (SoS)
struct Particule {
    float x, y;
    float vx, vy;
    int vie;
    int couleur;
};

const int NB_PARTICULES = 10000;

int main() {
    // Allocation des structures et des tableaux parallèles
    Particule* tabStruct = new Particule[NB_PARTICULES];
    
    float* p_x = new float[NB_PARTICULES];
    float* p_y = new float[NB_PARTICULES];
    float* p_vx = new float[NB_PARTICULES];
    float* p_vy = new float[NB_PARTICULES];
    int* p_vie = new int[NB_PARTICULES];
    int* p_couleur = new int[NB_PARTICULES];
   for (int i = 0; i < NB_PARTICULES; i++) {
        tabStruct[i] = { (float)i, (float)i, 1.0f, 1.0f, 100, i % 5 };
        
        p_x[i] = (float)i;
        p_y[i] = (float)i;
        p_vx[i] = 1.0f;
        p_vy[i] = 1.0f;
        p_vie[i] = 100;
        p_couleur[i] = i % 5;
    }

    ofstream fichierMesures("mesures.txt");
    if (!fichierMesures) {
        cerr << "Erreur d'ouverture de mesures.txt" << endl;
        return 1;
    }
    float dummyAcc = 0;
    for (int essai = 1; essai <= 3; essai++){
        auto debut = chrono::high_resolution_clock::now();
        for (int k = 0; k < 1000; k++) {
            for (int i = 0; i < NB_PARTICULES; i++) {
                tabStruct[i].x += tabStruct[i].vx;
                tabStruct[i].y += tabStruct[i].vy;
                dummyAcc += tabStruct[i].x;
            }
        }
        auto fin = chrono::high_resolution_clock::now();
        auto tempsStructPos = chrono::duration_cast<chrono::microseconds>(fin - debut).count();

        // B. Parallèles (SoA) - Position
        debut = chrono::high_resolution_clock::now();
        for (int k = 0; k < 1000; k++) {
            for (int i = 0; i < NB_PARTICULES; i++) {
                p_x[i] += p_vx[i];
                p_y[i] += p_vy[i];
                dummyAcc += p_x[i];
            }
        }
        fin = chrono::high_resolution_clock::now();
        auto tempsParaPos = chrono::duration_cast<chrono::microseconds>(fin - debut).count();
        debut = chrono::high_resolution_clock::now();
        for (int k = 0; k < 1000; k++) {
            for (int i = 0; i < NB_PARTICULES; i++) {
                tabStruct[i].vie--;
                dummyAcc += tabStruct[i].vie;
            }
        }
        fin = chrono::high_resolution_clock::now();
        auto tempsStructVie = chrono::duration_cast<chrono::microseconds>(fin - debut).count();

        // D. Parallèles (SoA) - Vie
        debut = chrono::high_resolution_clock::now();
        for (int k = 0; k < 1000; k++) {
            for (int i = 0; i < NB_PARTICULES; i++) {
                p_vie[i]--;
                dummyAcc += p_vie[i];
            }
        }
        fin = chrono::high_resolution_clock::now();
        auto tempsParaVie = chrono::duration_cast<chrono::microseconds>(fin - debut).count();
        fichierMesures << "structures, position, essai " << essai << " : " << tempsStructPos << " us" << endl;
        fichierMesures << "paralleles, position, essai " << essai << " : " << tempsParaPos << " us" << endl;
        fichierMesures << "structures, vie, essai " << essai << " : " << tempsStructVie << " us" << endl;
        fichierMesures << "paralleles, vie, essai " << essai << " : " << tempsParaVie << " us" << endl;
    }

    fichierMesures.close();
    
    delete[] tabStruct;
    delete[] p_x;
    delete[] p_y;
    delete[] p_vx;
    delete[] p_vy;
    delete[] p_vie;
    delete[] p_couleur;

    return 0;
}