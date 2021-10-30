#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Util.h"
#include "Trabajo.h"

int initTrabajos(Trabajo lista[], int len)
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

int buscarTrabajo(Trabajo lista[], int tam)
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

int buscarTrabajoId(Trabajo lista[], int tam, int id)
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

int buscarTrabajoLibre(Trabajo lista[], int len)
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

int altaTrabajo(Trabajo lista[], int tam, Marca marcas[], int tamMar, Tipo tipos[], int tamTip, Servicio servicios[],int tamServ, Notebook notebooks[],int tamNots, Cliente clientes[], int tamCli, int *nextIdTrabajo)
{
	int todoOk = -1;
	int indice;
    int input;

	if (lista != NULL && tam > 0)
	{
		indice = buscarTrabajoLibre(lista, tam);

		if(indice == -1)
		{
			printf("oh oh, parece que no queda espacio.");
		}
		else
		{
            mostrarNotebooks(notebooks, tamNots, marcas, tamMar, tipos, tamTip, clientes, tamCli);
            printf("ingrese id de la notebook: ");
            fflush(stdin);
            scanf("%d", &input);
            while(buscarNotebookId(notebooks, tamNots, input) == -1)
            {
                printf("Error id invalido\n");
                printf("ingrese id de la notebook: ");
                fflush(stdin);
                scanf("%d", &input);
            }
            lista[indice].idNotebook = input;
            mostrarServicios(servicios, tamServ);
            printf("ingrese id del servicio: ");
            fflush(stdin);
            scanf("%d", &input);
            while(!validarIdServicio(servicios, tamServ, input))
            {
                printf("Error id invalido\n");
                printf("ingrese id del servicio: ");
                fflush(stdin);
                scanf("%d", &input);
            }
            lista[indice].idServicio = input;

			cargarFecha(&lista[indice].fecha);
			lista[indice].id = *nextIdTrabajo;
			(*nextIdTrabajo)++;
			lista[indice].isEmpty = 0;

            printf(" Id       descripcion      fecha       notebook      marca      precio\n");
		    printf("-----------------------------------------------------------------------\n");
            mostrarTrabajo(lista[indice], servicios, tamServ, notebooks, tamNots, marcas, tamMar, clientes, tamCli);
            printf("alta exitosa\n");
            todoOk = 0;
		}
	}
	return todoOk;
}

int mostrarTrabajo(Trabajo trabajo, Servicio servicios[],int tamServ, Notebook notebooks[],int tamNots, Marca marcas[],int tamMar, Cliente clientes[], int tamCli)
{
	int todoOk = 0;
    int indice = buscarNotebookId(notebooks,tamNots,trabajo.idNotebook);
    int indiceServ = buscarServicioId(servicios,tamServ,trabajo.idServicio);
	int indiceCliente = buscarClienteId(clientes,tamCli,notebooks[indice].idCliente);
    char descMarca[20];
    cargarDescripcionMarca(marcas,tamMar,notebooks[indice].idMarca,descMarca);

    printf(" %d     %-20s   %02d/%02d/%d            %-20s  %-10s    %-10s   %.2f  \n",
            trabajo.id,
            servicios[indiceServ].descripcion,
            trabajo.fecha.dia,
            trabajo.fecha.mes,
            trabajo.fecha.anio,
            notebooks[indice].modelo,
            descMarca,
			clientes[indiceCliente].nombre,
            servicios[indiceServ].precio
            );

	return todoOk;
}

int mostrarTrabajos(Trabajo lista[], int tam, Servicio servicios[],int tamServ, Notebook notebooks[],int tamNots, Marca marcas[],int tamMar, Cliente clientes[], int tamCli)
{
	int todoOk = -1;

	if (lista != NULL && tam > 0)
	{
		printf(" Id       descripcion      fecha       notebook      marca     cliente     precio\n");
		printf("-----------------------------------------------------------------------\n");
		for (int i = 0; i < tam; i++)
		{
			if(!lista[i].isEmpty)
			{
				mostrarTrabajo(lista[i], servicios, tamServ, notebooks, tamNots, marcas, tamMar, clientes, tamCli);
			}
		}

		todoOk = 0;
	}

	return todoOk;
}

int validarIdTrabajo(Trabajo lista[], int tam, int id)
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

void hardcodearTrabajos(Trabajo lista[])
{
	lista[0].id = 30000;
	lista[0].idNotebook = 20000;
	lista[0].idServicio = 1000;
	lista[0].fecha.dia = 12;
	lista[0].fecha.mes = 12;
	lista[0].fecha.anio = 2012;
	lista[0].isEmpty = 0;
	
	lista[1].id = 30001;
	lista[1].idNotebook = 20001;
	lista[1].idServicio = 1001;
	lista[1].fecha.dia = 12;
	lista[1].fecha.mes = 10;
	lista[1].fecha.anio = 2012;
	lista[1].isEmpty = 0;
	
	lista[2].id = 30002;
	lista[2].idNotebook = 20000;
	lista[2].idServicio = 1003;
	lista[2].fecha.dia = 12;
	lista[2].fecha.mes = 12;
	lista[2].fecha.anio = 2002;
	lista[2].isEmpty = 0;
	
	lista[3].id = 30003;
	lista[3].idNotebook = 20000;
	lista[3].idServicio = 1001;
	lista[3].fecha.dia = 1;
	lista[3].fecha.mes = 12;
	lista[3].fecha.anio = 2012;
	lista[3].isEmpty = 0;
	
	lista[4].id = 30004;
	lista[4].idNotebook = 20000;
	lista[4].idServicio = 1003;
	lista[4].fecha.dia = 1;
	lista[4].fecha.mes = 12;
	lista[4].fecha.anio = 2012;
	lista[4].isEmpty = 0;
	
}
