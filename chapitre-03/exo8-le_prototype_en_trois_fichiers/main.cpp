#include <iostream>
#include <iomanip>
#include "aire.h"

int main() {
    double longueur, hauteur, rayon;
    std::cin >> longueur >> hauteur >> rayon;

    std::cout << std::fixed << std::setprecision(4);
    std::cout << aireRectangle(longueur, hauteur) << std::endl;
    std::cout << aireDisque(rayon) << std::endl;
    std::cout << aireTriangle(longueur, hauteur) << std::endl;
    return 0;
}