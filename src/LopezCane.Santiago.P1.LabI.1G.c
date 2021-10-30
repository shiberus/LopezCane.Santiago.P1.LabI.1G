#include <stdio.h>
#include <stdlib.h>
#include "Notebook.h"
#include "Marca.h"
#include "Tipo.h"
#include "Servicio.h"
#include "Trabajo.h"
#include "Fecha.h"
#include "Duenio.h"
#include "Informes.h"
#define TAM 500

int main(void) {
	setbuf(stdout, NULL);
	int continuar = 1;
	char opcion;

	int nextId = 20000;
	int nextIdTrabajo = 10000;

	Notebook notebooks[TAM];
	initNotebooks(notebooks, TAM);
	Trabajo trabajos[TAM];
	initTrabajos(trabajos, TAM);

	hardcodearTrabajos(trabajos);

	Marca marcas[4] = {{1000,"Compaq",0}, {1001,"Asus",0}, {1002,"Acer",0}, {1003,"HP",0}};
	Tipo tipos[4] = {{1000,"Gamer",0}, {1001,"Disenio",0}, {1002,"Ultrabook",0}, {1003,"Normalita",0}};
	Servicio servicios[4] = {{1000,"Bateria",2250,0}, {1001,"Display",10300,0}, {1002,"Mantenimiento",4400,0}, {1003,"Fuente",5600,0}};
	Cliente clientes[4] = {{1000,"Emilio",'M',0}, {1001,"Brenda",'F',0}, {1002,"Maximiliano",'M',0}, {1003,"Alex",'X',0}};

	while (continuar)
	{
		printf("   *** ABM Notebooks ***   \n");
		printf(" A. alta notebook\n");
		printf(" B. modificar notebook\n");
		printf(" C. baja notebook\n");
		printf(" D. listar notebooks\n");
		printf(" E. listar marcas\n");
		printf(" F. listar tipos\n");
		printf(" G. listar servicios\n");
		printf(" H. alta trabajo\n");
		printf(" I. listar trabajos\n");
		printf(" J. Informes\n");
		printf(" X. salir\n");
		printf(" Ingrese una opcion: ");
		fflush(stdin);
		opcion = getchar();

		switch (opcion)
		{
		case 'A':
			altaNotebook(notebooks, TAM, marcas, 4, tipos, 4, clientes, 4, &nextId);
			break;
		case 'B':
			if(buscarNotebook(notebooks,TAM))
			{
				modificarNotebook(notebooks, TAM, marcas, 4, tipos, 4, clientes, 4);
			}
			else
			{
				printf("Error: ninguna notebook cargada, ingrese enter para continuar\n");
				getchar();
			}
			break;

		case 'C':
			if(buscarNotebook(notebooks,TAM))
			{
				bajaNotebook(notebooks,TAM, marcas, 4, tipos, 4, clientes, 4);
			}
			else
			{
				printf("Error: ninguna notebook cargada, ingrese enter para continuar\n");
				getchar();
			}
			break;

		case 'D':
			if(buscarNotebook(notebooks,TAM))
			{
				mostrarNotebooks(notebooks, TAM, marcas, 4, tipos, 4, clientes, 4);
			}
			else
			{
				printf("Error: ninguna notebook cargada, ingrese enter para continuar\n");
				getchar();
			}
			break;

		case 'E':
			if(buscarMarca(marcas,4))
			{
				mostrarMarcas(marcas, 4);
			}
			else
			{
				printf("Error: ninguna marca cargada, ingrese enter para continuar\n");
				getchar();
			}
			break;

		case 'F':
			if(buscarTipo(tipos,4))
			{
				mostrarTipos(tipos, 4);
			}
			else
			{
				printf("Error: ningun tipo cargado, ingrese enter para continuar\n");
				getchar();
			}
			break;
		case 'G':
			if(buscarServicio(servicios,4))
			{
				mostrarServicios(servicios, 4);
			}
			else
			{
				printf("Error: ningun servicio cargado, ingrese enter para continuar\n");
				getchar();
			}
			break;
		case 'H':
			if(buscarServicio(servicios,4)
				&& buscarNotebook(notebooks, TAM))
			{
				altaTrabajo(trabajos,TAM,marcas,4,tipos,4,servicios,4,notebooks,TAM,clientes,4,&nextIdTrabajo);
			}
			else
			{
				printf("Error: ningun servicio/notebook cargado, ingrese enter para continuar\n");
				getchar();
			}
			break;
		case 'I':
			if(buscarTrabajo(trabajos,TAM))
			{
				mostrarTrabajos(trabajos,TAM, servicios,4,notebooks,TAM,marcas,4,clientes,4);
			}
			else
			{
				printf("Error: ningun trabajo cargado, ingrese enter para continuar\n");
				getchar();
			}
			break;
		case 'J':
			if(buscarTrabajo(trabajos,TAM)
			&& buscarNotebook(notebooks,TAM))
			{
				menuInformes(trabajos,TAM,servicios,4,notebooks,TAM,marcas,4,tipos,4,clientes,4);
			}
			else
			{
				printf("Error: ningun servicio cargado, ingrese enter para continuar\n");
				getchar();
			}
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


	return EXIT_SUCCESS;
}
