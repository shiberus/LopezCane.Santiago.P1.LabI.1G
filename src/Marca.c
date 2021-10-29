#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Util.h"
#include "Marca.h"

int initMarcas(Marca lista[], int len)
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

int buscarMarca(Marca lista[], int tam)
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

int buscarMarcaLibre(Marca lista[], int len)
{
	int res = -1;
	for (int i = 0; i < len; i++) {
		if (lista[i].isEmpty) {
			res = i;
			break;
		}
	}
	return res;
}

int altaMarca(Marca lista[], int tam)
{
	int todoOk = -1;
	int indice;

	indice = buscarMarcaLibre(lista, tam);

	if(indice == -1)
	{
		printf("oh oh, parece que no queda espacio.");
	}
	else
	{
		printf("    *** Alta Marca ***   \n");
		printf("-------------------------\n");
		if(ingresarString(lista[indice].descripcion, "Ingrese descripcion: ", 1, 20))
		{
			printf("oh oh, hubo un error.");
		}
		else
		{
			printf("id  descripcion\n");
			printf("-----------------------------\n");
			mostrarMarca(lista[indice]);
			printf("alta exitosa\n");
			todoOk = 0;
		}
	}

	return todoOk;
}

int mostrarMarca(Marca m)
{
	int todoOk = -1;
	printf("  %4d  %10s\n"
			,m.id
			,m.descripcion
			);
	todoOk = 0;
	return todoOk;
}

int mostrarMarcas(Marca lista[], int tam)
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
				mostrarMarca(lista[i]);
			}
		}

		todoOk = 0;
	}

	return todoOk;
}

int validarIdMarca(Marca lista[], int tam, int id)
{
	int esValido = 0;

	for (int i = 0; i < tam; i++)
	{
		if(!lista[i].isEmpty && lista[i].id == id)
		{
			esValido = 1;
		}
	}

	return esValido;
}

int cargarDescripcionMarca(Marca lista[], int tam, int id, char *descripcion)
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
