#include <iostream>

class Entite {
public:
    virtual const char* nom() const {
        return "entite";
    }
    virtual ~Entite() = default;
};

class Ennemi : public Entite {
public:
    int degats;
    const char* nom() const override {
        return "ennemi";
    }
};

void f(Entite e) {
    std::cout << e.nom() << std::endl;
}

void g(Entite& e) {
    std::cout << e.nom() << std::endl;
}

void h(Entite* e) {
    std::cout << e->nom() << std::endl;
}

int main() {
    Ennemi monEnnemi;

    /* Appel des trois fonctions avec le même objet*/
    f(monEnnemi); 
    g(monEnnemi); 
    h(&monEnnemi);
    std::cout << "Taille Entite : " << sizeof(Entite) <<std::endl;
    std::cout << "Taille Ennemi : " << sizeof(Ennemi) << std::endl;

    return 0;
}