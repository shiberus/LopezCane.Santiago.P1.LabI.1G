#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Util.h"
#include "Duenio.h"

int initClientes(Cliente lista[], int len)
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

int buscarCliente(Cliente lista[], int tam)
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

int buscarClienteId(Cliente lista[], int tam, int id)
{
    int res = -1;
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

int buscarClienteLibre(Cliente lista[], int len)
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

int altaCliente(Cliente lista[], int tam)
{
	int todoOk = -1;
	int indice;

	if (lista != NULL && tam > 0)
	{
		indice = buscarClienteLibre(lista, tam);

		if(indice == -1)
		{
			printf("oh oh, parece que no queda espacio.");
		}
		else
		{
			printf("    *** Alta Cliente ***   \n");
			printf("-------------------------\n");
			if(ingresarString(lista[indice].nombre, "Ingrese nombre: ", 1, 20))
			{
				printf("oh oh, hubo un error.");
			}
			else
			{
				printf("id  nombre\n");
				printf("-----------------------------\n");
				mostrarCliente(lista[indice]);
				printf("alta exitosa\n");
				todoOk = 0;
			}
		}
	}
	return todoOk;
}

int mostrarCliente(Cliente m)
{
	int todoOk = -1;
	printf("  %4d  %10s  %c\n"
			,m.id
			,m.nombre
            ,m.sexo
			);
	todoOk = 0;
	return todoOk;
}

int mostrarClientes(Cliente lista[], int tam)
{
	int todoOk = -1;

	if (lista != NULL && tam > 0)
	{
		printf(" Id       nombre      sexo\n");
		printf("-------------------------------------------------------\n");
		for (int i = 0; i < tam; i++)
		{
			if(!lista[i].isEmpty)
			{
				mostrarCliente(lista[i]);
			}
		}

		todoOk = 0;
	}

	return todoOk;
}

int validarIdCliente(Cliente lista[], int tam, int id)
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

int cargarNombreCliente(Cliente lista[], int tam, int id, char *nombre)
{
	int todoOk = -1;

	if (lista != NULL && tam > 0)
	{
		for (int i = 0; i < tam; i++)
		{
			if(!lista[i].isEmpty && lista[i].id == id)
			{
				strcpy(nombre, lista[i].nombre);
				todoOk = 0;
			}
		}
	}
	return todoOk;
}




