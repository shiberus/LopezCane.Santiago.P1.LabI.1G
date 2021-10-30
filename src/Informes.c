#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Util.h"
#include "informes.h"

int mostrarNotebooksTipo(Notebook notebooks[],int tamNots, Marca marcas[],int tamMar, Tipo tipos[], int tamTip, Cliente clientes[], int tamCli)
{
    int todoOk = -1;
    int input;
    mostrarTipos(tipos, tamTip);
    printf("ingrese id del tipo: ");
    fflush(stdin);
    scanf("%d", &input);
    while(!validarIdTipo(tipos, tamTip, input))
    {
        printf("Error id invalido\n");
        printf("ingrese id del tipo: ");
        fflush(stdin);
        scanf("%d", &input);
    }

    for (int i = 0; i < tamNots; i++)
    {
        if(!notebooks[i].isEmpty && notebooks[i].idTipo == input)
        {
            mostrarNotebook(notebooks[i], marcas, tamMar, tipos, tamTip, clientes, tamCli);
        }
    }

    todoOk = 0;
    return todoOk;
}

int mostrarNotebooksMarca(Notebook notebooks[],int tamNots, Marca marcas[],int tamMar, Tipo tipos[], int tamTip, Cliente clientes[], int tamCli)
{
    int todoOk = -1;
    int input;
    mostrarMarcas(marcas, tamMar);
    printf("ingrese id de la marca: ");
    fflush(stdin);
    scanf("%d", &input);
    while(!validarIdMarca(marcas, tamMar, input))
    {
        printf("Error id invalido\n");
        printf("ingrese id de la marca: ");
        fflush(stdin);
        scanf("%d", &input);
    }

    for (int i = 0; i < tamNots; i++)
    {
        if(!notebooks[i].isEmpty && notebooks[i].idMarca == input)
        {
            mostrarNotebook(notebooks[i], marcas, tamMar, tipos, tamTip, clientes, tamCli);
        }
    }

    todoOk = 0;
    return todoOk;
}

int mostrarNotebooksMasBaratas(Notebook notebooks[],int tamNots, Marca marcas[],int tamMar, Tipo tipos[], int tamTip, Cliente clientes[], int tamCli)
{
    int todoOk = -1;
    int precioMasBarato;

    for (int i = 0; i < tamNots; i++)
    {
        if(!notebooks[i].isEmpty)
        {
           if(i == 0)
           {
               precioMasBarato = notebooks[i].precio;
           }
           if(precioMasBarato > notebooks[i].precio)
           {
                precioMasBarato = notebooks[i].precio;
           }
        }
    }

    for (int i = 0; i < tamNots; i++)
    {
        if(!notebooks[i].isEmpty && notebooks[i].precio == precioMasBarato)
        {
            mostrarNotebook(notebooks[i], marcas, tamMar, tipos, tamTip, clientes, tamCli);
        }
    }

    todoOk = 0;
    return todoOk;
}

int contarNotebookTipoMarca(Notebook notebooks[],int tamNots, Marca marcas[],int tamMar, Tipo tipos[], int tamTip, Cliente clientes[], int tamCli)
{
    int todoOk = -1;
    int inputTipo,inputMarca;
    int contador = 0;
    mostrarTipos(tipos, tamTip);
    printf("ingrese id de la marca: ");
    fflush(stdin);
    scanf("%d", &inputTipo);
    while(!validarIdTipo(tipos, tamTip, inputTipo))
    {
        printf("Error id invalido\n");
        printf("ingrese id de la marca: ");
        fflush(stdin);
        scanf("%d", &inputTipo);
    }

    mostrarMarcas(marcas, tamMar);
    printf("ingrese id de la marca: ");
    fflush(stdin);
    scanf("%d", &inputMarca);
    while(!validarIdMarca(marcas, tamMar, inputMarca))
    {
        printf("Error id invalido\n");
        printf("ingrese id de la marca: ");
        fflush(stdin);
        scanf("%d", &inputMarca);
    }

    for (int i = 0; i < tamNots; i++)
    {
        if(!notebooks[i].isEmpty && notebooks[i].idTipo == inputTipo && notebooks[i].idMarca == inputMarca)
        {
            contador++;
        }
    }

    printf("El total de notebooks para las marca y tipo seleccionados es de: %d\n", contador);
    printf("ingrese enter para continuar\n");
    getchar();

    todoOk = 0;
    return todoOk;
}

int mostrarTrabajosNotebook(Trabajo trabajos[], int tam, Servicio servicios[],int tamServ, Notebook notebooks[],int tamNots, Marca marcas[],int tamMar, Tipo tipos[], int tamTip, Cliente clientes[], int tamCli)
{
    int todoOk = -1;
    int input;
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

    for (int i = 0; i < tam; i++)
    {
        if(!trabajos[i].isEmpty && trabajos[i].idNotebook == input)
        {
            mostrarTrabajo(trabajos[i],servicios,tamServ,notebooks,tamNots,marcas,tamMar,clientes, tamCli);
        }
    }

    todoOk = 0;
    return todoOk;
}

int informarSumaImporteServiciosDeNotebook(Trabajo trabajos[], int tam, Servicio servicios[],int tamServ, Notebook notebooks[],int tamNots, Marca marcas[],int tamMar, Tipo tipos[], int tamTip, Cliente clientes[], int tamCli)
{
    int todoOk = -1;
    int input, indiceServ;
    int acumuladorImporte = 0;

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

    for (int i = 0; i < tam; i++)
    {
        if(!trabajos[i].isEmpty && trabajos[i].idNotebook == input)
        {
            indiceServ = buscarServicioId(servicios,tamServ,trabajos[i].idServicio);
            acumuladorImporte += servicios[indiceServ].precio;
        }
    }

    printf("El total de importes para la notebook seleccionada es de: $%d\n", acumuladorImporte);
    printf("ingrese enter para continuar\n");
    getchar();

    todoOk = 0;
    return todoOk;
}

int mostrarNotebooksServicio(Trabajo trabajos[], int tam, Servicio servicios[],int tamServ, Notebook notebooks[],int tamNots, Marca marcas[],int tamMar, Tipo tipos[], int tamTip, Cliente clientes[], int tamCli)
{
    int todoOk = -1;
    int input, indiceNotebook;

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

    printf(" fecha   Id       modelo      marca      tipo   cliente  precio\n");
    printf("----------------------------------------------------------------\n");
    for (int i = 0; i < tam; i++)
    {
        if(!trabajos[i].isEmpty && trabajos[i].idServicio == input)
        {
            indiceNotebook = buscarNotebookId(notebooks, tamNots, trabajos[i].idNotebook);
            printf("%02d/%02d/%d  ",trabajos[i].fecha.dia,trabajos[i].fecha.mes,trabajos[i].fecha.anio);
            mostrarNotebook(notebooks[indiceNotebook],marcas, tamMar, tipos, tamTip, clientes, tamCli);
        }
    }

    printf("ingrese enter para continuar\n");
    getchar();


    todoOk = 0;
    return todoOk;
}

int mostrarServiciosFecha(Servicio servicios[], int tamServ, Trabajo trabajos[], int tamTra)
{
    Fecha inputFecha;
    int indiceServicio;
    int mostrar[tamServ];
    int todoOk = -1;

    for (int i = 0; i < tamServ; i++)
    {
        mostrar[i] = 0;
    }
    

    cargarFecha(&inputFecha);

    for (int i = 0; i < tamTra; i++)
    {
        if(!trabajos[i].isEmpty)
        {
            if(trabajos[i].fecha.dia == inputFecha.dia
            && trabajos[i].fecha.mes == inputFecha.mes
            && trabajos[i].fecha.anio == inputFecha.anio)
            {
                indiceServicio = buscarServicioId(servicios, tamServ, trabajos[i].idServicio);
                mostrar[indiceServicio] = 1;
            }
        }
    }

    for (int i = 0; i < tamServ; i++)
    {
        if(mostrar[i])
        {
            mostrarServicio(servicios[i]);
        }
    }

    printf("ingrese enter para continuar\n");
    getchar();

    todoOk = 0;
    return todoOk;
}

int menuInformes(Trabajo trabajos[], int tamTra, Servicio servicios[],int tamServ, Notebook notebooks[],int tamNots, Marca marcas[],int tamMar, Tipo tipos[], int tamTip, Cliente clientes[], int tamCli)
{
    int continuar = 1;
	char opcion;
    int todoOk = -1;

    while (continuar)
	{
		printf("   *** Informes ***   \n");
		printf(" A. mostrar los trabajos a una notebook\n");
		printf(" B. e informar la suma de los importes de los services se le hicieron a una notebook.\n");
		printf(" C. mostrar las notebooks a las que se realizó un servicio y la fecha.\n");
		printf(" D. mostrar todos los servicios realizados en una fecha.\n");
		printf(" E. mostrar las notebooks de un tipo.\n");
		printf(" F. mostrar las notebooks de una marca.\n");
		printf(" G. Informar la o las notebooks más baratas.\n");
		printf(" H. Elegir un tipo y una marca y contar cuantas notebooks hay de ese tipo y esa marca.\n");
		printf(" X. salir\n");
		printf(" Ingrese una opcion: ");
		fflush(stdin);
		opcion = getchar();

        switch (opcion)
        {
        case 'A':
            mostrarTrabajosNotebook(trabajos,tamTra,servicios, tamServ,notebooks,tamNots,marcas, tamMar, tipos, tamTip, clientes, tamCli);
            break;
        case 'B':
            informarSumaImporteServiciosDeNotebook(trabajos,tamTra,servicios, tamServ,notebooks,tamNots,marcas, tamMar, tipos, tamTip, clientes, tamCli);
            break;
        case 'C':
            mostrarNotebooksServicio(trabajos,tamTra,servicios, tamServ,notebooks,tamNots,marcas, tamMar, tipos, tamTip, clientes, tamCli);
            break;
        case 'D':
            mostrarServiciosFecha(servicios, tamServ,trabajos,tamTra);
            break;
        case 'E':
            mostrarNotebooksTipo(notebooks,tamNots,marcas, tamMar, tipos, tamTip, clientes,tamCli);
            break;
        case 'F':
            mostrarNotebooksMarca(notebooks,tamNots,marcas, tamMar, tipos, tamTip, clientes,tamCli);
            break;
        case 'G':
            mostrarNotebooksMasBaratas(notebooks,tamNots,marcas, tamMar, tipos, tamTip, clientes,tamCli);
            break;
        case 'H':
            contarNotebookTipoMarca(notebooks,tamNots,marcas, tamMar, tipos, tamTip, clientes,tamCli);
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
    todoOk = 0;
    return todoOk;
}
