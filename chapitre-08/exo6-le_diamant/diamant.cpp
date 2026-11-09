#include <iostream>

struct Vec2 {
    double x, y;
};
struct Entite {
    Vec2 position;
};
struct Mobile : /*virtual public */Entite {
    Vec2 vitesse;
};
struct Visible : /*virtual*/ public Entite {
    char glyphe;
};
struct Ennemi : public Mobile, public Visible {
};
int main() {
    std::cout << "--- Tailles sans heritage virtuel ---" << std::endl;
    std::cout << "sizeof(Entite)  : " << sizeof(Entite) << std::endl;
    std::cout << "sizeof(Mobile)  : " << sizeof(Mobile) << std::endl;
    std::cout << "sizeof(Visible) : " << sizeof(Visible) << std::endl;
    std::cout << "sizeof(Ennemi)  : " << sizeof(Ennemi) << std::endl;

    Ennemi e;
    /*e.position.x = 3.0;*/

    Mobile& m = e;
    Visible& v = e;

    std::cout << "Position via Mobile& : " << m.position.x << std::endl;
    std::cout << "Position via Visible&: " << v.position.x << std::endl;

    return 0;
}