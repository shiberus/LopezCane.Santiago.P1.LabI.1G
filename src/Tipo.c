#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Util.h"
#include "Tipo.h"

int initTipos(Tipo lista[], int len)
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

int buscarTipo(Tipo lista[], int tam)
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

int buscarTipoLibre(Tipo lista[], int len)
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

int altaTipo(Tipo lista[], int tam)
{
	int todoOk = -1;
	int indice;

	if (lista != NULL && tam > 0)
	{
		indice = buscarTipoLibre(lista, tam);

		if(indice == -1)
		{
			printf("oh oh, parece que no queda espacio.");
		}
		else
		{
			printf("    *** Alta Tipo ***   \n");
			printf("-------------------------\n");
			if(ingresarString(lista[indice].descripcion, "Ingrese descripcion: ", 1, 20))
			{
				printf("oh oh, hubo un error.");
			}
			else
			{
				printf("id  descripcion\n");
				printf("-----------------------------\n");
				mostrarTipo(lista[indice]);
				printf("alta exitosa\n");
				todoOk = 0;
			}
		}
	}
	return todoOk;
}

int mostrarTipo(Tipo m)
{
	int todoOk = -1;
	printf("  %4d  %10s\n"
			,m.id
			,m.descripcion
			);
	todoOk = 0;
	return todoOk;
}

int mostrarTipos(Tipo lista[], int tam)
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
				mostrarTipo(lista[i]);
			}
		}

		todoOk = 0;
	}

	return todoOk;
}

int validarIdTipo(Tipo lista[], int tam, int id)
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

int cargarDescripcionTipo(Tipo lista[], int tam, int id, char *descripcion)
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

