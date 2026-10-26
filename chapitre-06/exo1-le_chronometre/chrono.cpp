#include <chrono>
#include <cstdio>

double maintenant() {
    using namespace std;
    using namespace std::chrono;
    auto t = steady_clock::now().time_since_epoch();
    return duration<double>(t).count(); // en secondes
}
int main() {
double t_debut_boucle = maintenant();
long long total = 0;
for (long long i = 1; i <= 1000000; ++i) {
        total += i;
    }
double t_fin_boucle = maintenant();
double duree_boucle = t_fin_boucle - t_debut_boucle;
std::printf("Total : %lld\n", total);
std::printf("Duree boucle : %f secondes\n", duree_boucle);
std::printf("\n--- Mesures des printf ---\n");
for (int i = 0; i < 5; ++i) {
 double t1 = maintenant();
std::printf("Test printf %d\n", i + 1);
double t2 = maintenant();
std::printf("  -> Duree : %f s\n", t2 - t1);
    }

    return 0;
}