#include <iostream>
#include <cstdio>
struct Vec2
{
    double x, y;
    Vec2() : x(0.0), y(0.0) {}
    Vec2(double x_, double y_) : x(x_), y(y_) {}
    Vec2& operator+=(Vec2 b) { x += b.x; y += b.y; return *this; }
};

Vec2 operator+(Vec2 a, Vec2 b) { return {a.x + b.x, a.y + b.y}; }
Vec2 operator*(Vec2 a, double k) { return {a.x * k, a.y * k}; }
const int MAX = 1000;
using Entite = int;

struct Transform { Vec2 position; double rotation; Vec2 echelle; };
struct Corps     { Vec2 vitesse; double masse; };
struct Sprite    { char glyphe; };

Transform transforms[MAX];  bool aTransform[MAX] = {};
Corps     corps[MAX];       bool aCorps[MAX]     = {};
Sprite    sprites[MAX];     bool aSprite[MAX]    = {};

struct Cellule
{
    Vec2 position;
    Vec2 vitesse;
    int suivante;  
};

Cellule pool[MAX];
int premiereLibre = 0; 

void initialiser()
{
    for (int i = 0; i < MAX - 1; ++i)
    {
        pool[i].suivante = i + 1;
    }
    pool[MAX - 1].suivante = -1;
}

int allouer()
{
    if (premiereLibre == -1) return -1;
    int i = premiereLibre;
    premiereLibre = pool[i].suivante;
    return i;
}

void liberer(int i)
{
    pool[i].suivante = premiereLibre;
    premiereLibre = i;
}
Entite creerEntite()
{
    return allouer();
}

void detruireEntite(Entite e)
{
    if (e < 0 || e >= MAX) return;
    aTransform[e] = false;
    aCorps[e]     = false;
    aSprite[e]    = false;
    liberer(e);
}

//
int systemePhysique(double dt)
{
    int count = 0;
    Vec2 gravite(0.0, -9.81);
    for (int i = 0; i < MAX; ++i)
    {
        if (aCorps[i] && aTransform[i])
        {
            corps[i].vitesse = corps[i].vitesse + (gravite * dt);
            transforms[i].position = transforms[i].position + (corps[i].vitesse * dt);
            count++;
        }
    }
    return count;
}
const int H = 20, L = 40;
char image[H][L];

void effacer(char c = ' ')
{
    for (int y = 0; y < H; ++y)
        for (int x = 0; x < L; ++x)
            image[y][x] = c;
}

void point(int x, int y, char c = '#')
{
    if (x < 0 || x >= L || y < 0 || y >= H) return;
    image[y][x] = c;
}

void afficher()
{
    for (int y = 0; y < H; ++y)
    {
        for (int x = 0; x < L; ++x)
            std::printf("%c", image[y][x]);
        std::printf("\n");
    }
}
int systemeRendu()
{
    int count = 0;
    effacer(' ');
    for (int i = 0; i < MAX; ++i)
    {
     if (aSprite[i] && aTransform[i])
        {
 int px = static_cast<int>(transforms[i].position.x);
int py = static_cast<int>(transforms[i].position.y);
point(px, H - 1 - py, sprites[i].glyphe);
            count++;
        }
    }
 afficher();
return count;
}

int main()
{
initialiser();
for (int i = 0; i < 40; ++i)
{
 Entite e = creerEntite();
  if (e != -1)
        {
            aTransform[e] = true;
            transforms[e].position = {static_cast<double>(i % L), static_cast<double>(i % H)};
            aSprite[e] = true;
            sprites[e].glyphe = '.';
        }
    }
    for (int i = 0; i < 40; ++i)
    {
        Entite e = creerEntite();
        if (e != -1)
        {
            aTransform[e] = true;
            transforms[e].position = {5.0 + (i % 20), 10.0};
            aCorps[e] = true;
            corps[e].vitesse = {1.0, 2.0};
            corps[e].masse = 1.0;
            aSprite[e] = true;
            sprites[e].glyphe = 'o';
        }
    }

    for (int i = 0; i < 20; ++i)
    {
        Entite e = creerEntite();
        if (e != -1)
        {
            aTransform[e] = true;
            transforms[e].position = {static_cast<double>(i * 2), 15.0};
            aCorps[e] = true;
            corps[e].vitesse = {0.0, -1.0};
            corps[e].masse = 2.0;
            aSprite[e] = true;
            sprites[e].glyphe = 'X';
        }
    }

    std::cout << "--- Debut de la simulation initiale ---" << std::endl;
    for (int pas = 0; pas < 5; ++pas)
    {
        int nbPhysique = systemePhysique(0.1);
        int nbRendu = systemeRendu();
        std::printf("Pas %d -> Physique traites : %d | Rendu traites : %d\n", pas + 1, nbPhysique, nbRendu);
    }
    for (int e = 5; e <= 50; e += 5)
    {
        detruireEntite(e);
    }
    std::cout << "\nCreation de 5 nouvelles entites (recyclage par la free list) : ";
    for (int i = 0; i < 5; ++i)
    {
        Entite e = creerEntite();
        if (e != -1)
        {
            aTransform[e] = true;
            transforms[e].position = {10.0, 10.0};
            aSprite[e] = true;
            sprites[e].glyphe = 'N';
        }
        std::printf("%d ", e);
    }
    std::printf("\n\n");
    int nbPhysiqueFin = systemePhysique(0.1);
    int nbRenduFin = systemeRendu();
    std::printf("Dernier pas -> Physique traites : %d | Rendu traites : %d\n", nbPhysiqueFin, nbRenduFin);

    return 0;
}