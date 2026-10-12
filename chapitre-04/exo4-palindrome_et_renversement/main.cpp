#include <iostream>
using namespace std;
int longueur(const char s[]) {
int len = 0;
while (s[len] != '\0') {
len++;}
return len;
}
bool estPalindrome(const char s[]) {
    int len = longueur(s);
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) {
            return false;}
    }
    return true;}
void renverserTexte(char s[]) {
    int len = longueur(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}
int main(){
    char s[201];
    if (!(cin >> s)) return 0;
    if (estPalindrome(s)) {
    cout << "oui" << endl;
    } else {
    cout << "non" << endl;}
    renverserTexte(s);
    cout << s << endl;
    return 0;
}