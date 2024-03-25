#include<stdlib.h>

int main(int argc, char const *argv[])
{
    for (int i = 1; i < 201; i++)
    {
        if (i%5 == 0 && i%7==0)
        {
            printf("FooBar\n");
        }
        else if (i%5 == 0)
        {
            printf("Foo\n");
        }
        else if (i%7 == 0)
        {
            printf("Bar\n");
        }
        else
        {
            printf("%d\n", i); 
        }
    }
    
    return 0;
}
