#include <iostream>
using namespace std;
long long valeurAbsolue(long long n) {
if (n < 0) {
return -n; }
 return n;
}
long long pgcd(long long a, long long b)
{
    a = valeurAbsolue(a);
    b = valeurAbsolue(b);

    while (b != 0) {
        long long reste = a % b;
        a = b;
        b = reste;
    }
    return a;
}
long long ppcm(long long a, long long b) {
if (a == 0 || b == 0) {
return 0; }
return valeurAbsolue(a) / pgcd(a, b) * valeurAbsolue(b);
}

int main()
{
 long long a = 0;
 long long b = 0;
bool trouve = false;
while (cin >> a >> b)
    {
trouve = true;
 cout << pgcd(a, b) << "\n";
cout << ppcm(a, b) << "\n";
    }
if (!trouve) {
 cout << "AUCUN\n";
    }
return 0;
}
