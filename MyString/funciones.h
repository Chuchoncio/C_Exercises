#ifndef FUUNCIONES_H_INCLUDED
#define FUUNCIONES_H_INCLUDED

#include <stdio.h>

char *MiStrchr(char *s, int c);
char *MiStrrchr(char *s, int c);
int MiMemCmp(const void *s1, const void *s2, size_t n);
void* MiMemCpy(void *s1, const void *s2, size_t n);
void* MiMemMove(void *s1, const void*s2, size_t n);
void* MiMemSet(void *s, int c, size_t n);
char* MiStrcat(char *s1, const char *s2);
size_t MiStrcspn(const char *s1, const char *s2);
size_t MiStrlen(const char *s);
char *MiStrncat(char*s1, const char *s2, size_t n);
int MiStrncmp(const void *s1, const void *s2, size_t n);
char *MiStrncpy(char *s1, const char *s2, size_t n);
char* MyStrerror(int errnum);
char* MiStrpbrk(const char* s1, const char* s2);
char* MiStrtok(char* s1, const char* s2);

#endif // FUUNCIONES_H_INCLUDED
