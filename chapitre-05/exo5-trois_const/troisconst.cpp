#include <cstdio>
int main() {
int x = 1, y = 2;
const int* a = &x;       
int* const b = &x;    
const int* const c = &x; 
  a = &y;             
 *b = 5;  
printf("Execution terminee avec succes.\n");
    return 0;
}