#include <iostream>
#include <cmath>
struct Vec2
{
double x;
 double y;
};
void eulerSemiImplicite(Vec2& p, Vec2& v, Vec2& a, double dt)
{
v.x = v.x + a.x * dt;
 v.y = v.y + a.y * dt;
 p.x = p.x + v.x * dt;
 p.y = p.y + v.y * dt;
}

int main()
{
double h = 3.0;
double g = 9.81;
double v0 = std::sqrt(2.0 * g * h);
double dt1 = 1.0 / 120.0; 
double dt2 = 1.0 / 30.0;
double dt3 = 1.0 / 1000.0;
auto simulerSaut = [g, v0](double dt) {
Vec2 p = {0.0, 0.0};
Vec2 v = {0.0, v0};
Vec2 a = {0.0, -g};
double max_y = p.y;
while (p.y >= 0.0)
    {
if (p.y > max_y)
{
 max_y = p.y;
}
eulerSemiImplicite(p, v, a, dt);
        }
return max_y;
    };
double max_h_120 = simulerSaut(dt1);
double max_h_30 = simulerSaut(dt2);
double max_h_petit = simulerSaut(dt3);
std::printf("v0 : %.17g\n", v0);
std::printf("1/120 : %.17g\n", max_h_120);
std::printf("1/30 : %.17g\n", max_h_30);
std::printf("Mon pas : %.17g\n", max_h_petit);
return 0;
}