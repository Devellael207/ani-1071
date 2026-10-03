#include <iostream>
using namespace std;
void echangerParValeur(int a, int b) {
int tmp = a;
a = b;
b = tmp;
}
void echangerParReference(int& a, int& b) {
int tmp = a;
a = b;
b = tmp;
}

int main() {
int a, b;
cin >> a >> b;
echangerParValeur(a, b);
cout << a << "\n" << b << "\n";
echangerParReference(a, b);
cout << a << "\n" << b << "\n";
return 0;
}
