#include <iostream>
using namespace std;
long long compte = 0;
void hanoi(int n, char depart, char arrivee, char intermediaire) {
if (n <= 0) return;
hanoi(n - 1, depart, intermediaire, arrivee);
cout << depart << '>' << arrivee << '\n';
++compte;
hanoi(n - 1, intermediaire, arrivee, depart);
}

int main() {
int n;
cin >> n;
hanoi(n, 'A', 'C', 'B');
cout << compte << '\n';
return 0;
}
