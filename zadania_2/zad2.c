#include<stdlib.h>
void func(float*val)
{
    *val *= 2;
}

int main()
{
    float val = 2.3;
    printf("zmienna przed funkcją: %.3f\n", val);
    func(&val);
    printf("zmienna po funkcji: %.3f\n", val);

    return 0;
}