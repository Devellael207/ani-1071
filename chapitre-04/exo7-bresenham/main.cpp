#include <iostream>
#include <cmath> 
using namespace std;
void tracerSegment(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int sx = (x0 < x1) ? 1 : -1;
    int dy = -abs(y1 - y0); 
    int sy = (y0 < y1) ? 1 : -1;
    int erreur = dx + dy;
    while (true) {
        cout << x0 << " " << y0 << endl;
        if (x0 == x1 && y0 == y1) {
            break;}
        int e2 = 2 * erreur;
        if (e2 >= dy) {
            if (x0 == x1) break; 
            erreur += dy;
            x0 += sx;}
        if (e2 <= dx) {
            if (y0 == y1) break; 
            erreur += dx;
            y0 += sy; }
    }
}
int main() {
    int x0, y0, x1, y1;
    if (!(cin >> x0 >> y0 >> x1 >> y1)) return 0;
    tracerSegment(x0, y0, x1, y1);
return 0;
}