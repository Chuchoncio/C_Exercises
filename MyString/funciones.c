#include "funciones.h"

int MiMemCmp(const void *s1, const void *s2, size_t n)
{
    unsigned char* cad1 = (unsigned char*)s1;
    unsigned char* cad2 = (unsigned char*)s2;

    while(n)
    {
        if(*cad1 == *cad2)
        {
            cad1++;
            cad2++;
        }
        else if(*cad1 > *cad2)
            return 1;
        else
            return -1;
        n--;
    }

    return 0;
}

/** \fn char *strchr(char *s, int c)
 * \brief Localiza la primera aparición de c (convertido a unsigned char) en la cadena apuntada
 *          por s (incluyendo el carácter nulo)
 * \param s cadena de caracteres, c caracter a buscar
 * \return retorna un puntero a partir del carácter encontrado. Si no se ha encontrado
 *          el carácter c, entonces retorna un puntero null
 **/
char *MiStrchr(char *s, int c)
{
    while(*s != c && *s)
        s++;

    return s;
}

char *MiStrrchr(char *s, int c)
{
    char *r = NULL;

    while(*s)
    {
        if(*s == c)
            r = s;
        s++;
    }

    return r;
}

void* MiMemCpy(void *s1, const void *s2, size_t n)
{
    char* cad1 =  (char*)s1;
    char* cad2 =  (char*)s2;

    while(n)
    {
        *(cad1) = *(cad2);
        cad1++;
        cad2++;
        n--;
    }

    return (void*)cad1;
}

void* MiMemMove(void *s1, const void*s2, size_t n)
{
    char* cad1 = (char *)s1;
    char* cad2 =  (char*)s2;
    char tempCad[n];
    int i;

    for(i = 0; i<n; i++,cad2++)
        tempCad[i] = *cad2;

    cad2 -= n;

    for(i = 0; i<n; i++, cad1++)
        *(cad1) = tempCad[i];

    return (void*)cad1;
}

void* MiMemSet(void *s, int c, size_t n)
{
    char *cad = (char*)s;
    unsigned char valor = c;

    while(n)
    {
        *cad = valor;
        cad++;
        n--;
    }

    return (void*)cad;
}

char* MiStrcat(char *s1, const char *s2)
{
    char* cad1 = s1;
    const char* cad2 = s2;

    while(*cad1)
        cad1++;

    while(*cad2)
    {
        *cad1 = *cad2;
        cad1++;
        cad2++;
    }

    // Copia el caracter nulo
    *cad1 = *cad2;

    return cad1;
}

size_t MiStrcspn(const char *s1, const char *s2)
{
    size_t n = 0;
    const char* cad = s2;
    while(*s1)
    {
        while(*s1 != *cad && *cad)
            cad++;

        if(*s1 == *cad)
            break;
        else
            cad = s2;

        s1++;
        n++;
    }

    return n;
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

char *MiStrncat(char*s1, const char *s2, size_t n)
{
    char* cad1 = s1;
    const char* cad2 = s2;

    while(*cad1)
        cad1++;

    while(n && *cad2)
    {
        *cad1 = *cad2;
        cad1++;
        cad2++;
        n--;
    }

    // Copia el caracter nulo
    *cad1 = '\0';

    return cad1;
}

int MiStrncmp(const void *s1, const void *s2, size_t n)
{
    unsigned char* cad1 = (unsigned char*)s1;
    unsigned char* cad2 = (unsigned char*)s2;

    while(n && *cad1 && *cad2)
    {
        if(*cad1 == *cad2)
        {
            cad1++;
            cad2++;
        }
        else if(*cad1 > *cad2)
            return 1;
        else
            return -1;
        n--;
    }

    return 0;
}

char *MiStrncpy(char *s1, const char *s2, size_t n)
{
    char* cad1 = s1;
    const char* cad2 = s2;

    while(n && *cad1)
    {
        if(*cad2)
            *cad1 = *cad2;
        else
            *cad1 = '\0';
        cad1++;
        cad2++;
        n--;
    }

    return cad1;
}

char* MyStrerror(int errnum)
{
    char* errstr;
    switch(errnum)
    {
        case 0: errstr = "No error"; break;
        case 1: errstr = "Operation not permitted"; break;
        case 2: errstr = "No such file or directory"; break;
        case 3: errstr = "No such process"; break;
        case 4: errstr = "Interrupted function call"; break;
        case 5: errstr = "Input/output error"; break;
        case 6: errstr = "No such device or address"; break;
        case 7: errstr = "Arg list too long"; break;
        case 8: errstr = "Exec format error"; break;
        case 9: errstr = "Bad file descriptor"; break;
        case 10: errstr = "No child processes"; break;
        case 11: errstr = "Resource temporarily unavailable"; break;
        case 12: errstr = "Not enough space"; break;
        case 13: errstr = "Permission denied"; break;
        case 14: errstr = "Bad address"; break;
        case 15: errstr = "Unknown error"; break;
        case 16: errstr = "Resource device"; break;
        case 17: errstr = "File exists"; break;
        case 18: errstr = "Improper link"; break;
        case 19: errstr = "No such device"; break;
        case 20: errstr = "Not a directory"; break;
        case 21: errstr = "Is a directory"; break;
        case 22: errstr = "Invalid argument"; break;
        case 23: errstr = "Too many open files in system"; break;
        case 24: errstr = "Too many open files"; break;
        case 25: errstr = "Inappropriate I/O control operation"; break;
        case 26: errstr = "Unknown error"; break;
        case 27: errstr = "File too large"; break;
        case 28: errstr = "No space left on device"; break;
        case 29: errstr = "Invalid seek"; break;
        case 30: errstr = "Read-only file system"; break;
        case 31: errstr = "Too many links"; break;
        case 32: errstr = "Broken pipe"; break;
        case 33: errstr = "Domain error"; break;
        case 34: errstr = "Result too large"; break;
        case 35: errstr = "Unknown error"; break;
        case 36: errstr = "Resource deadlock avoided"; break;
        case 37: errstr = "Unknown error"; break;
        case 38: errstr = "Filename too long"; break;
        case 39: errstr = "No locks available"; break;
        case 40: errstr = "Function not implemented"; break;
        case 41: errstr = "Directory not empty"; break;
        case 42: errstr = "Illegal byte sequence"; break;
        default: errstr = "Unknown error";
    }
    return errstr;
}

char* MiStrpbrk(const char* s1, const char* s2)
{
    const char* cad1 = s1;
    const char* cad2 = s2;

    while(*cad1)
    {
        while(*cad2)
        {
            if(*cad2 == *cad1)
                return (char*)cad1;
            cad2++;
        }
        cad2 = s2;
        cad1++;
    }
    return NULL;
}

char* MiStrtok(char* s1, const char* s2)
{
    int strRtc = MiStrlen(s2), strRtc2 = 0;

    while(*s1)
    {
        while(*s2)
        {
            if(*s2 != *s1)
                s2++;
            else
            {
                *s1 = '\0';
                s1 -= strRtc2;
                return s1;
            }
        }
        strRtc2++;
        s2 -= strRtc;
        s1++;
    }

    return NULL;
}
