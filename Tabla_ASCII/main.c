#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c = 32;
    int separar = 3;
    printf("--TABLA ASCII--\n\n");

    while(c < 127)
    {
        if(separar > 0)
        {
            printf("%d - %c\t\t", c, c);
            separar--;
        }
        else
        {
            printf("%d - %c\n", c, c);
            separar = 3;
        }
        c++;
    }
    return 0;
}
