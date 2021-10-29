#include <stdio.h>
#include <stdlib.h>
#include "Fecha.h"

int cargarFecha(Fecha *fecha)
{
    int todoOk = -1;
    Fecha auxFecha = {0,0,0};
    printf("Ingrese fecha (dd/mm/aaaa)");
    fflush(stdin);
    scanf("%d/%d/%d", &auxFecha.dia, &auxFecha.mes, &auxFecha.anio);
    while((auxFecha.dia < 1 || auxFecha.dia > 31)
        || (auxFecha.mes < 1 || auxFecha.mes > 12)
        || (auxFecha.anio < 1983 || auxFecha.anio > 2021))
        {
            printf("Error, fecha invalida, ingrese fecha (dd/mm/aaaa)");
            fflush(stdin);
            scanf("%d/%d/%d",  &auxFecha.dia, &auxFecha.mes, &auxFecha.anio);
        }
        *fecha = auxFecha;
        todoOk = 0;
        return todoOk;
}