#include <chrono>
#include <cstdio>

double maintenant()
{
using namespace std::chrono;
auto t = steady_clock::now().time_since_epoch();
return duration<double>(t).count();
}
class Chrono
{
private:
double start;

public:
Chrono()
    {
 start = maintenant();
    }
double ecoule() const
    {
return maintenant() - start;
    }
void redemarrer()
    {
 start = maintenant();
    }
};

int main()
{
for (int i = 0; i < 3; ++i)
    {
long long total = 0;
Chrono c;
for (long long j = 0; j < 100000000; ++j)
total += j;
printf("total: %lld, duree: %.9f\n", total, c.ecoule());
    }
Chrono c2;
for (int i = 0; i < 5; ++i)
    {
 c2.redemarrer();
printf("%.9f\n", c2.ecoule());
    }
const Chrono k;
k.ecoule();
    // k.redemarrer();
return 0;
}