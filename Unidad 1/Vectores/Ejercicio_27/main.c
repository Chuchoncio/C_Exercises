/* Desarrollar una funci�n que determine si una cadena
 *  de car�cteres es un pal�ndromo (o no).
 */

#include "main.h"

int main()
{
    char frase[]= "Ligar es ser agil";
    int verif = 0;

    verif = determinarPalindromo(frase);

    if(verif == 1)
        printf("La cadena \"%s\" es palindromo\n", frase);
    else
        printf("La cadena \"%s\" NO es palindromo\n", frase);

    return 0;
}
