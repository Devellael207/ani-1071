#include <iostream>

struct Vec2 {
    double x, y;
};
class Entite {
protected:
    Vec2 position;
    const char* nom;

public:
    Entite(Vec2 pos, const char* n) : position(pos), nom(n) {}
};

class Ennemi : public Entite {
private:
    int degats;
    int chance;

public:
    Ennemi(Vec2 pos, const char* n, int d) : Entite(pos, n), degats(d) {}
    void deplacer(double dx, double dy) {
        position.x += dx;
        position.y += dy;
    }double getDegats() const {
        return degats;
    }double getChance() const {
        return chance;}
};
class Joueur : public Entite {
private:
    double vie;

public:
    Joueur(Vec2 pos, const char* n, double v) : Entite(pos, n), vie(v) {}
    double getVie() const {
        return vie;
    }
};

int main() {
    std::cout << "Taille de Vec2 : " << sizeof(Vec2) << " octets\n";
    std::cout << "Taille de const char* : " << sizeof(const char*) << " octets\n";
    std::cout << "Taille de Entite : " << sizeof(Entite) << " octets\n";
    std::cout << "Taille de Ennemi : " << sizeof(Ennemi) << " octets\n";
    std::cout << "Taille de Joueur : " << sizeof(Joueur) << " octets\r\n\n";
    std::cout << "Taille de const char* : " << sizeof(const char*) << " octets\n";

    /*faire des test*/
    Vec2 posInitiale = {0.0, 0.0};
    Ennemi monEnnemi(posInitiale, "Gobelin", 15);
    Joueur monJoueur(posInitiale, "Héros", 100.0);

    // Utilisation des getters pour afficher les valeurs (ce qui résout les warnings)
    std::cout << "Ennemi cree avec " << monEnnemi.getDegats() << " points de degats.\n";
    std::cout << "Joueur cree avec " << monJoueur.getVie() << " points de vie.\n";
    std::cout << "Ennemi cree avec " << monEnnemi.getChance() << " points de chance.\n";


    /*ici c'est l'appel qui vas declancer l'erreur attendu aupres du compilateur*/
    /*monEnnemi.position.x = 5.0; */
  return 0;
}