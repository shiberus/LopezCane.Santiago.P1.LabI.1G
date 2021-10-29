#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Util.h"

int ingresarString(char *destino, char *mensaje, int min, int max)
{
    int todoOk = -1;
    char auxString[1000];

    if(destino != NULL && mensaje != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(auxString);
        while(strlen(auxString) < min || strlen(auxString) > max)
        {
            printf("Error. %s (minimo %d y maximo %d caracteres)", mensaje, min, max);
            fflush(stdin);
            gets(auxString);
        }

        strcpy(destino, auxString);
        todoOk = 0;
    }

    return todoOk;
}

int validarLetras(char str[])
{
    int todoOk = 0;
    int i = 0;
    while(str[i] != '\0')
    {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
       {
           todoOk = -1;
           break;
       }
       i++;
    }
    return 1;
}
