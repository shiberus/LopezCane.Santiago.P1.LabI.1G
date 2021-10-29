#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Util.h"
#include "Notebook.h"
#include "Tipo.h"
#include "Marca.h"


int initNotebooks(Notebook lista[], int len)
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

int buscarNotebook(Notebook lista[], int tam)
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

int buscarNotebookLibre(Notebook lista[], int tam)
{
	int res = -1;
	if (lista != NULL && tam > 0)
	{
        for (int i = 0; i < tam; i++)
        {
            if (lista[i].isEmpty)
            {
                res = i;
                break;
            }
        }
    }
	return res;
}

int buscarNotebookId(Notebook lista[], int tam, int id)
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

int altaNotebook(Notebook lista[], int tam, Marca marcas[], int tamMar, Tipo tipos[], int tamTip, int *nextId)
{
	int todoOk = -1;
	int indice,idTipo,idMarca;
	float precio;
    if (lista != NULL && marcas != NULL && tipos != NULL && tam > 0 && tamMar > 0 && tamTip > 0)
	{
        indice = buscarNotebookLibre(lista, tam);

        if(indice == -1)
        {
            printf("oh oh, parece que no queda espacio.");
        }
        else
        {
            printf("    *** Alta Notebook ***   \n");
            printf("-------------------------\n");
            if(ingresarString(lista[indice].modelo, "Ingrese modelo: ", 1, 20))
            {
                printf("oh oh, hubo un error.");
            }
            else
            {
                mostrarMarcas(marcas, tamMar);
                printf("ingrese id de la marca: ");
                fflush(stdin);
                scanf("%d", &idMarca);
                while(!validarIdMarca(marcas, tamMar, idMarca))
                {
                    printf("Error id invalido\n");
                    printf("ingrese id de la marca: ");
                    fflush(stdin);
                    scanf("%d", &idMarca);
                }
                lista[indice].idMarca = idMarca;

                mostrarTipos(tipos, tamTip);
                printf("ingrese id del tipo: ");
                fflush(stdin);
                scanf("%d", &idTipo);
                while(!validarIdTipo(tipos, tamTip, idTipo))
                {
                    printf("Error id invalido\n");
                    printf("ingrese id del tipo: ");
                    fflush(stdin);
                    scanf("%d", &idTipo);
                }
                lista[indice].idTipo = idTipo;

                printf("Ingrese precio: ");
                fflush(stdin);
                scanf("%f", &precio);
                while(precio < 1000 || precio > 200000)
                {
                    printf("Error. Ingrese precio (minimo %d y maximo %d): ", 1000, 200000);
                    fflush(stdin);
                    scanf("%f", &precio);
                }
                lista[indice].precio = precio;

                lista[indice].id = *nextId;
                (*nextId)++;
                lista[indice].isEmpty = 0;
                printf(" Id       modelo      marca      tipo \n");
                printf("-----------------------------\n");
                mostrarNotebook(lista[indice], marcas, tamMar, tipos, tamTip);
                printf("alta exitosa, presione enter para continuar.\n");
                fflush(stdin);
                getchar();
                todoOk = 0;
            }
        }
	}
	return todoOk;
}

int mostrarNotebook(Notebook m, Marca marcas[], int tamMar, Tipo tipos[], int tamTip)
{
	int todoOk = -1;
    char descripcionMarca[21];
    char descripcionTipo[21];

    if(marcas != NULL && tipos != NULL && tamMar != 0 && tamTip != 0)
    {
        cargarDescripcionMarca(marcas, tamMar, m.idMarca, descripcionMarca);
        cargarDescripcionTipo(tipos, tamTip, m.idTipo, descripcionTipo);
        printf("%6d  %10s %10s %10s %6d\n"
                ,m.id
                ,m.modelo
                ,descripcionMarca
                ,descripcionTipo
				,m.precio
                );
        todoOk = 0;
    }
	return todoOk;
}

int mostrarNotebooks(Notebook lista[], int tam, Marca marcas[], int tamMar, Tipo tipos[], int tamTip)
{
	int todoOk = -1;

	if (lista != NULL && marcas != NULL && tipos != NULL && tam > 0 && tamMar > 0 && tamTip > 0)
	{
		printf(" Id       modelo        marca        tipo      precio\n");
		printf("-----------------------------------------------------------------------\n");
		for (int i = 0; i < tam; i++)
		{
			if(!lista[i].isEmpty)
			{
				mostrarNotebook(lista[i], marcas, tamMar, tipos, tamTip);
			}
		}

		todoOk = 0;
	}

	return todoOk;
}

int modificarNotebook(Notebook lista[], int tam, Marca marcas[], int tamMar, Tipo tipos[], int tamTip)
{
    int todoOk = -1;
    int continuar = 1;
    char input;
    int id;
    int index;
    int idTipo;
    float precio;

    if (lista != NULL && marcas != NULL && tipos != NULL && tam > 0 && tamMar > 0 && tamTip > 0)
	{
        printf("   *** Modificar Notebook ***   \n");
        printf("------------------------------------\n");
        mostrarNotebooks(lista, tam, marcas, tamMar, tipos, tamTip);
        printf("Ingrese ID: \n");
        fflush(stdin);
        scanf("%d", &id);
        index = buscarNotebookId(lista, tam, id);
        while(continuar && (index == -1))
        {
            printf("ID invalido, desea continuar? S/N \n");
            fflush(stdin);
            scanf("%c", &input);
            input = toupper(input);
            while(input != 'S' && input != 'N')
            {
                printf("desea continuar? S/N \n");
                fflush(stdin);
                scanf("%c", &input);
                input = toupper(input);
            }
            if(input == 'N')
            {
                continuar = 0;
            }
            else
            {
                printf("Ingrese ID: \n");
                fflush(stdin);
                scanf("%d", &id);
                index = buscarNotebookId(lista, tam, id);
            }
        }

	    while (continuar)
        {
            printf(" Id       modelo        marca        tipo      precio\n");
            printf("-----------------------------------------------------------------------\n");
            mostrarNotebook(lista[index], marcas, tamMar, tipos, tamTip);
            printf(" A. modificar precio");
            printf(" B. modificar tipo\n");
            printf(" X. salir\n");
            printf(" Ingrese una opcion: ");
            fflush(stdin);
            input = getchar();
            input = toupper(input);

            switch(input)
            {
                case 'A':
                    printf("Ingrese precio: ");
                    fflush(stdin);
                    scanf("%f", &precio);
                    while(precio < 1000 || precio > 200000)
                    {
                        printf("Error. Ingrese precio (minimo %d y maximo %d): ", 1000, 200000);
                        fflush(stdin);
                        scanf("%f", &precio);
                    }
                    lista[index].precio = precio;
                    break;
                case 'B':
                    mostrarTipos(tipos, tamTip);
                    printf("ingrese id del tipo: ");
                    fflush(stdin);
                    scanf("%d", &idTipo);
                    while(!validarIdTipo(tipos, tamTip, idTipo))
                    {
                        printf("Error id invalido\n");
                        printf("ingrese id de la marca: ");
                        fflush(stdin);
                        scanf("%d", &idTipo);
                    }
                    lista[index].idTipo = idTipo;
                    break;
                case 'X':
                    continuar = 0;
                    break;
                default:
                    printf("Error: Opcion invalida, ingrese enter para continuar\n");
                    getchar();
                    break;
            }
        }
	}
	return todoOk;
}

int bajaNotebook(Notebook lista[], int tam, Marca marcas[], int tamMar, Tipo tipos[], int tamTip)
{
    int id,index;
    int continuar = 1;
    char input;
    int todoOk = -1;

    if (lista != NULL && marcas != NULL && tipos != NULL && tam > 0 && tamMar > 0 && tamTip > 0)
	{
        printf("   *** Baja Notebook ***   \n");
        printf("------------------------------------\n");
        mostrarNotebooks(lista, tam, marcas, tamMar, tipos, tamTip);
        printf("Ingrese ID: \n");
        fflush(stdin);
        scanf("%d", &id);
        index = buscarNotebookId(lista, tam, id);
        while(continuar && (index == -1))
        {
            printf("ID invalido, desea continuar? S/N \n");
            fflush(stdin);
            scanf("%c", &input);
            input = toupper(input);
            while(input != 'S' && input != 'N')
            {
                printf("desea continuar? S/N \n");
                fflush(stdin);
                scanf("%c", &input);
                input = toupper(input);
            }
            if(input == 'N')
            {
                continuar = 0;
            }
            else
            {
                printf("Ingrese ID: \n");
                fflush(stdin);
                scanf("%d", &id);
                index = buscarNotebookId(lista, tam, id);
            }
        }

        if(continuar)
        {
            printf(" Id       modelo        marca        tipo      precio\n");
            printf("-----------------------------------------------------------------------\n");
            mostrarNotebook(lista[index], marcas, tamMar, tipos, tamTip);
            printf("-----------------------------------------------------------------------\n");
            printf("Confirmar baja? S/N \n");
            fflush(stdin);
            scanf("%c", &input);
            input = toupper(input);
            while(input != 'S' && input != 'N')
            {
                printf("Confirmar baja? S/N \n");
                fflush(stdin);
                scanf("%c", &input);
                input = toupper(input);
            }
            if(input == 'N')
            {
                continuar = 0;
            }
            else
            {
                lista[index].isEmpty = 1;
                todoOk = 0;
                printf("baja exitosa, presione enter para continuar");
                getchar();
            }
        }
    }
    return todoOk;
}
