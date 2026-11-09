#include <iostream>
#include <vector>
class Trace {
public:
    ~Trace() {
        std::cout << "~Trace" << std::endl;
    }
};
class Ennemi {
public:
    virtual void deplacer(double dt) {
        (void)dt;
    }

    // Destructeur virtuel (à mettre en commentaire pour tester la partie "Sans virtual")
    /*virtual*/ ~Ennemi() {
        std::cout << "~Ennemi" << std::endl;
    }
};

class Fantome : public Ennemi {
private:
    std::vector<int> donnees; 
    Trace traceur;           

public:
    Fantome() : donnees(1000) {}

    ~Fantome() /*override*/ {
        std::cout << "~Fantome (taille du vecteur : " << donnees.size() << ")" << std::endl;
    }
};

int main() {
    std::cout << "--- Test avec Ennemi* pointant vers Fantome ---" << std::endl;
    Ennemi* e = new Fantome();
    delete e; 
    std::cout << "\n--- Test avec Fantome* direct ---" << std::endl;
    Fantome* f = new Fantome();
    delete f;

    return 0;
}