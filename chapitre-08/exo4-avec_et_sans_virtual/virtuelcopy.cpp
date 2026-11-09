#include <iostream>

int gEnnemi = 0;
int gFantome = 0;
int gRobot = 0;

// 1. Classe de base Ennemi
class Ennemi {
public:
    /*virtual*/ void deplacer(double  ) {
        gEnnemi++;
        
    }

    /*Destructeur virtuel obligatoire pour nettoyer proprement des objets polymorphes*/
    virtual ~Ennemi() = default;
};

class Fantome : public Ennemi {
public:
    void deplacer(double) /*override*/ {
        gFantome++;
       /*(void)dt;*/
    }
};
class Robot : public Ennemi {
public:
    void deplacer(double)/* override */{
        gRobot++;
        /*(void)dt;*/
    }
};

int main() {
    Ennemi* tab[6];
    tab[0] = new Ennemi();
    tab[1] = new Robot();
    tab[2] = new Robot();
    tab[3] = new Fantome();
    tab[4] = new Fantome();
    tab[5] = new Fantome();
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 6; ++j) {
            tab[j]->deplacer(0.016);
        }
    }
    std::cout << "Compteur Ennemi  : " << gEnnemi << std::endl;
    std::cout << "Compteur Fantome : " << gFantome << std::endl;
    std::cout << "Compteur Robot   : " << gRobot << std::endl;
    for (int j = 0; j < 6; ++j) {
        delete tab[j];
    }

    return 0;
}