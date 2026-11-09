#include <iostream>

class Base {
protected:
    int protegee;
private:
    int privee;
public:
    int publique;
};

class Derivee : public Base {
       
public:
    void testerAccesDerivee() {
        /*Tentative 1 : Accès au membre public depuis la classe dérivée*/
       publique = 10;
        /* Tentative 2 : Accès au membre protégé depuis la classe dérivée*/
        protegee=20;
        /* Tentative 3:Accès au membre privé depuis la classe dérivée*/
         /* privee = 30;*/
        
    }
};

void soigner(Base& b) {
    /*Tentative avec la fonction libre sur un objet Base reçu en paramètre :*/
    /* b.protegee = 5;*/
    
}

int main() {
    Derivee d;

    /*Tentative 4 : Accès au membre public depuis main*/
    d.publique = 1; 

    /* Tentative 5 : Accès au membre protégé depuis main*/
    /*  d.protegee=2*/

    /* Tentative 6 : Accès au membre privé depuis main*/
    /* d.privee = 3*/
    return 0;
}