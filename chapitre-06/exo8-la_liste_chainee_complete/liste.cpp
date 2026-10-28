#include <iostream>
int nbNoeudsVivants = 0;

struct Noeud
{
    int valeur;
    Noeud* suivant;
};
Noeud* ajouterEnTete(Noeud* tete, int v)
{
    Noeud* nouveau = new Noeud{v, tete};
    nbNoeudsVivants++;
    return nouveau;
}
Noeud* ajouterEnQueue(Noeud* tete, int v)
{
Noeud* nouveau = new Noeud{v, nullptr};
nbNoeudsVivants++;
if (tete == nullptr)
    {
        return nouveau;
    }

Noeud* courant = tete;
while (courant->suivant != nullptr)
{
 courant = courant->suivant;
 }
courant->suivant = nouveau;
    return tete;
}
int compter(const Noeud* n)
{
int count = 0;
const Noeud* courant = n;
while (courant != nullptr)
    {
count++;
courant = courant->suivant;
    }
    return count;
}
bool contient(const Noeud* n, int v)
{
const Noeud* courant = n;
while (courant != nullptr)
    {
if (courant->valeur == v)
        {
return true;
        }
courant = courant->suivant;
    }
    return false;
}

// 3. afficher
void afficher(const Noeud* n)
{
const Noeud* courant = n;
std::cout << "[";
while (courant != nullptr)
    {
std::cout << courant->valeur;
if (courant->suivant != nullptr)
{
std::cout << ", ";
 }
courant = courant->suivant;
    }
    std::cout << "]" << std::endl;
}
Noeud* retirer(Noeud* tete, int v)
{
if (tete == nullptr)
    {
return nullptr;
    }
    if (tete->valeur == v)
    {
Noeud* aSupprimer = tete;
Noeud* nouvelleTete = tete->suivant;
delete aSupprimer;
nbNoeudsVivants--;
 return nouvelleTete;
    }
    Noeud* courant = tete;
    while (courant->suivant != nullptr && courant->suivant->valeur != v)
    {
 courant = courant->suivant;
    }
    if (courant->suivant != nullptr)
    {
    Noeud* aSupprimer = courant->suivant;
    courant->suivant = aSupprimer->suivant;
    delete aSupprimer;
    nbNoeudsVivants--;
    }
return tete;
}
void liberer(Noeud*& tete)
{
Noeud* courant = tete;
while (courant != nullptr)
    {
Noeud* suivant = courant->suivant;
delete courant;
nbNoeudsVivants--;
courant = suivant;
    }
tete = nullptr;
}
Noeud* inverser(Noeud* tete)
{
Noeud* precedent = nullptr;
Noeud* courant = tete;
while (courant != nullptr)
    {
Noeud* suivant = courant->suivant;
courant->suivant = precedent;
precedent = courant;
courant = suivant;
    }
return precedent;
}

int main()
{
Noeud* maListe = nullptr;
std::cout << "--- CONSTRUCTION DE LA LISTE ---" << std::endl;
maListe = ajouterEnQueue(maListe, 10);
maListe = ajouterEnQueue(maListe, 20);
maListe = ajouterEnQueue(maListe, 30);
maListe = ajouterEnQueue(maListe, 40);
maListe = ajouterEnQueue(maListe, 50);
std::cout << "Liste initiale : ";
afficher(maListe);
std::cout << "Nombre de elements : " << compter(maListe) << std::endl;
std::cout << "\n--- TEST RETIRER ---" << std::endl;
std::cout << "Retrait de 10 (en tete) : ";
maListe = retirer(maListe, 10);
afficher(maListe);
std::cout << "Retrait de 30 (au milieu) : ";
maListe = retirer(maListe, 30);
afficher(maListe);
std::cout << "Retrait de 999 (absent) : ";
maListe = retirer(maListe, 999);
afficher(maListe);
std::cout << "\n--- TEST INVERSER ---" << std::endl;
maListe = inverser(maListe);
std::cout << "Liste inversee : ";
afficher(maListe);
std::cout << "\nVivants : " << nbNoeudsVivants << std::endl;
std::cout << "\n--- TEST LIBERER ---" << std::endl;
liberer(maListe);
 std::cout << "Vivants apres liberation : " << nbNoeudsVivants << std::endl;

return 0;
}
#include <iostream>
int nbNoeudsVivants = 0;

struct Noeud
{
    int valeur;
    Noeud* suivant; // le suivant, ou nullptr
};

// 1. ajouterEnTete
Noeud* ajouterEnTete(Noeud* tete, int v)
{
    Noeud* nouveau = new Noeud{v, tete};
    nbNoeudsVivants++;
    return nouveau;
}
Noeud* ajouterEnQueue(Noeud* tete, int v)
{
    Noeud* nouveau = new Noeud{v, nullptr};
    nbNoeudsVivants++;

    if (tete == nullptr)
    {
        return nouveau;
    }

    Noeud* courant = tete;
    while (courant->suivant != nullptr)
    {
        courant = courant->suivant;
    }
    courant->suivant = nouveau;
    return tete;
}

// 3. compter
int compter(const Noeud* n)
{
    int count = 0;
    const Noeud* courant = n;
    while (courant != nullptr)
    {
        count++;
        courant = courant->suivant;
    }
    return count;
}
bool contient(const Noeud* n, int v)
{
    const Noeud* courant = n;
    while (courant != nullptr)
    {
        if (courant->valeur == v)
        {
            return true;
        }
        courant = courant->suivant;
    }
    return false;
}
void afficher(const Noeud* n)
{
    const Noeud* courant = n;
    std::cout << "[";
    while (courant != nullptr)
    {
        std::cout << courant->valeur;
        if (courant->suivant != nullptr)
        {
            std::cout << ", ";
        }
        courant = courant->suivant;
    }
    std::cout << "]" << std::endl;
}
Noeud* retirer(Noeud* tete, int v)
{
    if (tete == nullptr)
    {
        return nullptr;
    }
    if (tete->valeur == v)
    {
        Noeud* aSupprimer = tete;
        Noeud* nouvelleTete = tete->suivant;
        delete aSupprimer;
        nbNoeudsVivants--;
        return nouvelleTete;
    }
    Noeud* courant = tete;
    while (courant->suivant != nullptr && courant->suivant->valeur != v)
    {
        courant = courant->suivant;
    }
    if (courant->suivant != nullptr)
    {
        Noeud* aSupprimer = courant->suivant;
        courant->suivant = aSupprimer->suivant;
        delete aSupprimer;
        nbNoeudsVivants--;
    }

    return tete;
}
void liberer(Noeud*& tete)
{
    Noeud* courant = tete;
    while (courant != nullptr)
    {
        Noeud* suivant = courant->suivant;
        delete courant;
        nbNoeudsVivants--;
        courant = suivant;
    }
    tete = nullptr;
}

Noeud* inverser(Noeud* tete)
{
    Noeud* precedent = nullptr;
    Noeud* courant = tete;
    while (courant != nullptr)
    {
        Noeud* suivant = courant->suivant;
        courant->suivant = precedent;
        precedent = courant;
        courant = suivant;
    }
    return precedent;
}

int main()
{
    Noeud* maListe = nullptr;

    std::cout << "--- CONSTRUCTION DE LA LISTE ---" << std::endl;
    maListe = ajouterEnQueue(maListe, 10);
    maListe = ajouterEnQueue(maListe, 20);
    maListe = ajouterEnQueue(maListe, 30);
    maListe = ajouterEnQueue(maListe, 40);
    maListe = ajouterEnQueue(maListe, 50);

    std::cout << "Liste initiale : ";
    afficher(maListe);
    std::cout << "Nombre de elements : " << compter(maListe) << std::endl;

    std::cout << "\n--- TEST RETIRER ---" << std::endl;
    // Retirer sur la tête (10)
    std::cout << "Retrait de 10 (en tete) : ";
    maListe = retirer(maListe, 10);
    afficher(maListe);

    // Retirer dans le milieu (30)
    std::cout << "Retrait de 30 (au milieu) : ";
    maListe = retirer(maListe, 30);
    afficher(maListe);

    // Retirer une valeur absente (999)
    std::cout << "Retrait de 999 (absent) : ";
    maListe = retirer(maListe, 999);
    afficher(maListe);

    std::cout << "\n--- TEST INVERSER ---" << std::endl;
    maListe = inverser(maListe);
    std::cout << "Liste inversee : ";
    afficher(maListe);

    std::cout << "\nVivants : " << nbNoeudsVivants << std::endl;

    std::cout << "\n--- TEST LIBERER ---" << std::endl;
    liberer(maListe);
    std::cout << "Vivants apres liberation : " << nbNoeudsVivants << std::endl;
    return 0;
}