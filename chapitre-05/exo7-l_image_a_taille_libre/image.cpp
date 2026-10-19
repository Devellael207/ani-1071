#include <cstdio>
#include <cmath>
char* creerImage(int l, int h) {
char* img = new char[l * h];
for (int i = 0; i < l * h; ++i) {
    img[i] = ' ';
 }
return img;
}
void detruireImage(char* img) {
    delete[] img;
}
void point(char* img, int l, int h, int x, int y, char c) {
if (x >= 0 && x < l && y >= 0 && y < h) {
    img[y * l + x] = c;
    }
}
void afficher(const char* img, int l, int h) {
for (int y = 0; y < h; ++y) {
for (int x = 0; x < l; ++x) {
     putchar(img[y * l + x]);
     }
     putchar('\n');
 }
}
void dessinerCercle(char* img, int l, int h, char caractere) {
double cx = (l - 1) / 2.0;
double cy = (h - 1) / 2.0;
double r = h / 2.5; 
for (int y = 0; y < h; ++y) {
 for (int x = 0; x < l; ++x) {
double dx = x - cx;double dy = y - cy;
if (dx * dx + dy * dy <= r * r) {
 point(img, l, h, x, y, caractere);
            }
        }
    }
}

int main() {
int l1 = 30, h1 = 10;
 char* img1 = creerImage(l1, h1);
 dessinerCercle(img1, l1, h1, '#');
afficher(img1, l1, h1);
detruireImage(img1);
int l2 = 80, h2 = 24;
char* img2 = creerImage(l2, h2);
dessinerCercle(img2, l2, h2, '#');
afficher(img2, l2, h2);
detruireImage(img2);

return 0;
}