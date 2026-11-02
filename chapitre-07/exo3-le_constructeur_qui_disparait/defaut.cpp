#include <cstdio>

struct P 
{
    int a;
    P() = default;
};

int main() 
{
    P x;
    P t[10];
    
    printf("x.a = %d\n", x.a);
    
    return 0;
}