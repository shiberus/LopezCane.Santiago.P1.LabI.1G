#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Util.h"
#include "Servicio.h"

int initServicios(Servicio lista[], int len)
{
	int todoOk = -1;
	if (lista != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			lista[i].isEmpty = 1;
		}
		todoOk = 0;
	}
	return todoOk;
}

int buscarServicio(Servicio lista[], int tam)
{
    int res = 0;
	if (lista != NULL && tam > 0)
	{
		for (int i = 0; i < tam; i++)
		{
			if (!lista[i].isEmpty) 
            {
                res = 1;
                break;
		    }
		}
	}
	return res;
}

int buscarServicioId(Servicio lista[], int tam, int id)
{
    int res = 0;
	if (lista != NULL && tam > 0)
	{
		for (int i = 0; i < tam; i++)
		{
			if (!lista[i].isEmpty && lista[i].id == id) 
            {
                res = i;
                break;
		    }
		}
	}
	return res;
}

int buscarServicioLibre(Servicio lista[], int len)
{
	int res = -1;
	if (lista != NULL && len > 0)
	{
		for (int i = 0; i < len; i++) {
			if (lista[i].isEmpty) {
				res = i;
				break;
			}
		}
	}
	return res;
}

int altaServicio(Servicio lista[], int tam)
{
	int todoOk = -1;
	int indice;
    float precio;

	if (lista != NULL && tam > 0)
	{
		indice = buscarServicioLibre(lista, tam);

		if(indice == -1)
		{
			printf("oh oh, parece que no queda espacio.");
		}
		else
		{
			printf("    *** Alta Servicio ***   \n");
			printf("-------------------------\n");
			if(ingresarString(lista[indice].descripcion, "Ingrese descripcion: ", 1, 20))
			{
				printf("oh oh, hubo un error.");
			}
			else
			{
                printf("Ingrese precio: ");
                fflush(stdin);
                scanf("%f", &precio);
                while(precio < 500 || precio > 10000)
                {
                    printf("Error. Ingrese precio (minimo %d y maximo %d): ", 500, 10000);
                    fflush(stdin);
                    scanf("%f", &precio);
                }
                lista[indice].precio = precio;
				printf("id  descripcion    precio\n");
				printf("-----------------------------\n");
				mostrarServicio(lista[indice]);
				printf("alta exitosa\n");
				todoOk = 0;
			}
		}
	}
	return todoOk;
}

int mostrarServicio(Servicio m)
{
	int todoOk = -1;
	printf("  %4d  %10s  %4.2f\n"
			,m.id
			,m.descripcion
            ,m.precio
			);
	todoOk = 0;
	return todoOk;
}

int mostrarServicios(Servicio lista[], int tam)
{
	int todoOk = -1;

	if (lista != NULL && tam > 0)
	{
		printf(" Id       descripcion \n");
		printf("-------------------------------------------------------\n");
		for (int i = 0; i < tam; i++)
		{
			if(!lista[i].isEmpty)
			{
				mostrarServicio(lista[i]);
			}
		}

		todoOk = 0;
	}

	return todoOk;
}

int validarIdServicio(Servicio lista[], int tam, int id)
{
	int esValido = 0;

	if (lista != NULL && tam > 0)
	{
		for (int i = 0; i < tam; i++)
		{
			if(!lista[i].isEmpty && lista[i].id == id)
			{
				esValido = 1;
			}
		}
	}
	return esValido;
}

int cargarDescripcionServicio(Servicio lista[], int tam, int id, char *descripcion)
{
	int todoOk = -1;

	if (lista != NULL && tam > 0)
	{
		for (int i = 0; i < tam; i++)
		{
			if(!lista[i].isEmpty && lista[i].id == id)
			{
				strcpy(descripcion, lista[i].descripcion);
				todoOk = 0;
			}
		}
	}
	return todoOk;
}
