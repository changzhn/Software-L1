#include <stdio.h>

void set_a(int *addr) {
    printf("addr = %p\n", addr);
    *addr = 100;
}

int main()
{
    float f = 1.0;
    short c = *(short*)&f; 
    printf("c = %d f = %f\n", c, f);
    return 0;
}
