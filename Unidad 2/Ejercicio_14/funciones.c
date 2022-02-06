#include "main.h"

char *MiStrCpy(char *s1, const char *s2)
{
    char* cad1 = s1;
    const char* cad2 = s2;

    while(*cad1)
    {
        if(*cad2)
            *cad1 = *cad2;
        else
            *cad1 = '\0';
        cad1++;
        cad2++;
    }

    return cad1;
}

int MiStrCmpi(const void *s1, const void *s2)
{
    unsigned char* cad1 = (unsigned char*)s1;
    unsigned char* cad2 = (unsigned char*)s2;

    while(*cad1 && *cad2)
    {
        if(tolower(*cad1) == tolower(*cad2))
        {
            cad1++;
            cad2++;
        }
        else if(*cad1 > *cad2)
            return 1;
        else
            return -1;
    }

    return 0;
}

size_t MiStrlen(const char *s)
{
    size_t n = 0;
    while(*s)
    {
        n++;
        s++;
    }
    return n;
}

char* cmpLxcg(char* cad1, char* cad2)
{
    int contMayorCad1 = 0, contMayorCad2 = 0;
    char *c1 = cad1, *c2 = cad2;

    while(*c1 && *c2)
    {
        if(*c1 > *c2)
            contMayorCad1++;
        else if(*c1 < *c2)
            contMayorCad2++;
        else
        {
            contMayorCad1++;
            contMayorCad2++;
        }
        c1++;
        c2++;
    }

    return contMayorCad1 > contMayorCad2 ? c1 : c2;
}
