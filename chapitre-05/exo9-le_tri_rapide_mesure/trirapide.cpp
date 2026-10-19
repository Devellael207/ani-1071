#include <cstdio>
#include <cstdlib>
#include <ctime>
void echanger(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void triSelection(int t[], int n, long long& comparateurs) {
for (int i = 0; i < n - 1; ++i) {
 int min_idx = i;
for (int j = i + 1; j < n; ++j) {
     comparateurs++;
    if (t[j] < t[min_idx]) {
             min_idx = j;
            }
        }
 if (min_idx != i) {
     echanger(t[i], t[min_idx]);
        }
    }
}
void triRapideRec(int t[], int bas, int haut, long long& comparateurs) {
if (bas >= haut) return;
int mid = bas + (haut - bas) / 2;
echanger(t[mid], t[haut]); 
int pivot = t[haut];
int i = bas - 1;
for (int j = bas; j < haut; ++j) {
 comparateurs++;
 if (t[j] <= pivot) {
      i++;
     echanger(t[i], t[j]);
        }
    }
echanger(t[i + 1], t[haut]);
int pi = i + 1;

triRapideRec(t, bas, pi - 1, comparateurs);
triRapideRec(t, pi + 1, haut, comparateurs);
}

void triRapide(int t[], int bas, int haut, long long& comparateurs) {
triRapideRec(t, bas, haut, comparateurs);
}

int main() {
std::srand(static_cast<unsigned int>(std::time(nullptr)));
 int tailles[] = {100, 1000, 10000, 100000};
 printf("--- Mesures sur tableaux aleatoires ---\n");
for (int t_idx = 0; t_idx < 4; ++t_idx) {
 int n = tailles[t_idx];
int* tab1 = new int[n];
int* tab2 = new int[n];
for (int i = 0; i < n; ++i) {
 int val = std::rand();
tab1[i] = val;
tab2[i] = val;
        }
long long comp_sel = 0;
long long comp_rap = 0;
triSelection(tab1, n, comp_sel);
triRapide(tab2, 0, n - 1, comp_rap);
 printf("Taille %d -> Selection : %lld comps | Tri rapide : %lld comps\n", n, comp_sel, comp_rap);
delete[] tab1;
delete[] tab2;
    }
int n_rie = 10000;
int* tab_trie = new int[n_rie];
for (int i = 0; i < n_rie; ++i) {
tab_trie[i] = i;
    }
long long comp_trie = 0;
triRapide(tab_trie, 0, n_rie - 1, comp_trie);
printf("Tri rapide sur tableau deja trie (avec pivot median) : %lld comps\n", comp_trie);
delete[] tab_trie;

return 0;
}