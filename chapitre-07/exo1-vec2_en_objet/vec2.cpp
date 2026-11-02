#include <iostream>
#include <cmath>

struct Vec2 
{
    double x, y;
Vec2() : x(0.0), y(0.0) {}
Vec2(double x_, double y_) : x(x_), y(y_) {}
double length() const 
    {
 return std::sqrt(x * x + y * y);
    }
double dot(const Vec2& b) const 
    {
 return x * b.x + y * b.y;
    }
Vec2 normalized() const 
    {
 double l = length();
if (l == 0.0) return Vec2(0.0, 0.0);
return Vec2(x / l, y / l);
    }
 void normalize() 
    {
double l = length();
if (l != 0.0) 
        {
x /= l;
y /= l;
        }
    }
Vec2 operator+(const Vec2& b) const 
    {
 return Vec2(x + b.x, y + b.y);
    }
Vec2 operator-(const Vec2& b) const 
    {
return Vec2(x - b.x, y - b.y);
    }
Vec2 operator-() const 
    {
return Vec2(-x, -y);
    }
Vec2 operator/(double s) const 
    {
 return Vec2(x / s, y / s);
    }
bool operator==(const Vec2& b) const 
    {
return x == b.x && y == b.y;
    }
bool operator!=(const Vec2& b) const 
    {
 return !(*this == b);
    }
Vec2& operator+=(const Vec2& b) 
    {
 x += b.x;
y += b.y;
return *this;
    }
Vec2& operator-=(const Vec2& b) 
    {
x -= b.x;
y -= b.y;
return *this;
    }
Vec2& operator*=(double s) 
    {
 x *= s;
 y *= s;
 return *this;
    }
double& operator[](int i) 
    {
if (i == 0) return x;
return y;
    }
const double& operator[](int i) const 
    {
 if (i == 0) return x;
 return y;
    }
};
Vec2 operator*(const Vec2& v, double s) 
{
return Vec2(v.x * s, v.y * s);
}
Vec2 operator*(double s, const Vec2& v) 
{
 return Vec2(v.x * s, v.y * s);
}
int main() 
{
Vec2 v1;
Vec2 v2(3.0, 4.0);
std::cout << v2.length() << " " << v2.normalized().x << "\n";
Vec2 v3 = v2 + Vec2(1.0, 1.0);
v3 += v2;
v3[1] = 5.0;
Vec2 p(0.0, 10.0);
Vec2 v(3.0, 0.0);
Vec2 g(0.0, -9.81);
double dt = 0.1;
double t = 0.0;
while (p.y >= 0.0) 
    {
 v += g * dt;
 p += v * dt;
 t += dt;
 std::cout << t << " " << p.x << " " << p.y << " " << v.x << " " << v.y << "\n";
    }
double t_exact = std::sqrt(10.0 / 4.905);
std::cout << t_exact << "\n";
return 0;
}