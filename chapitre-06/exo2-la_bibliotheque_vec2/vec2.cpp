#include <iostream>
#include <cmath>
struct Vec2
{
    double x;
    double y;
};
const double PI = 3.141592653589793;
Vec2 add(Vec2 a, Vec2 b)
{
    return {a.x + b.x, a.y + b.y};
}
Vec2 sub(Vec2 a, Vec2 b)
{
    return {a.x - b.x, a.y - b.y};
}
Vec2 scale(Vec2 a, double k)
{
    return {a.x * k, a.y * k};
}
double dot(Vec2 a, Vec2 b)
{
    return a.x * b.x + a.y * b.y;
}
double length(Vec2 a)
{
    return std::sqrt(dot(a, a));
}
Vec2 normalize(Vec2 a)
{
    double len = length(a);
    if (len == 0.0)
    {
        return {0.0, 0.0};
    }
    return scale(a, 1.0 / len);
}
Vec2 lerp(Vec2 a, Vec2 b, double t)
{

    return add(a, scale(sub(b, a), t));
}
Vec2 perp(Vec2 a)
{
    return {-a.y, a.x};
}
Vec2 rotate(Vec2 a, double angle)
{
    double c = std::cos(angle);
    double s = std::sin(angle);
    return {a.x * c - a.y * s, a.x * s + a.y * c};
}
Vec2 reflect(Vec2 v, Vec2 n)
{
    double d = dot(v, n);
    Vec2 scaledN = scale(n, 2.0 * d);
    return sub(v, scaledN);}
double radians(double degres)
{
    return degres * (PI / 180.0);
}
int main()
{
    Vec2 v_len = {3, 4};
    double l_val = length(v_len);
    std::printf("length({3, 4}) = %.17g\n", l_val);
    double d_val = dot({1, 0}, {0, 1});
    std::printf("dot({1, 0}, {0, 1}) = %.17g\n", d_val);
    Vec2 rot_res = rotate({1, 0}, radians(90));
    std::printf("rotate({1, 0}, radians(90)) = {%.17g, %.17g}\n", rot_res.x, rot_res.y);
    Vec2 ref_res = reflect({1, -1}, {0, 1});
    std::printf("reflect({1, -1}, {0, 1}) = {%.17g, %.17g}\n", ref_res.x, ref_res.y);
    Vec2 add_res = add({1, 2}, {3, 4});
    std::printf("add({1, 2}, {3, 4}) = {%.17g, %.17g}\n", add_res.x, add_res.y);
    Vec2 sub_res = sub({5, 5}, {2, 1});
    std::printf("sub({5, 5}, {2, 1}) = {%.17g, %.17g}\n", sub_res.x, sub_res.y);
    Vec2 scale_res = scale({2, 3}, 4);
    std::printf("scale({2, 3}, 4) = {%.17g, %.17g}\n", scale_res.x, scale_res.y);
    Vec2 norm_res = normalize({3, 4});
    std::printf("normalize({3, 4}) = {%.17g, %.17g}\n", norm_res.x, norm_res.y);
    Vec2 lerp_res = lerp({0, 0}, {10, 10}, 0.5);
    std::printf("lerp({0, 0}, {10, 10}, 0.5) = {%.17g, %.17g}\n", lerp_res.x, lerp_res.y);
    Vec2 perp_res = perp({1, 2});
    std::printf("perp({1, 2}) = {%.17g, %.17g}\n", perp_res.x, perp_res.y);

    return 0;
}