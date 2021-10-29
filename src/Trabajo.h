#include "Fecha.h"
#include "Marca.h"
#include "Notebook.h"
#include "Servicio.h"
#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct {
	int id;
	int idNotebook;
	int idServicio;
	Fecha fecha;
	int isEmpty;
} Trabajo;

/** \brief Inicializa el array de Trabajos
 *
 * \param lista[] Trabajo el array a inicializar
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int initTrabajos(Trabajo lista[], int len);

/** \brief Busca al menos un Trabajo cargado en el array
 *
 * \param lista[] Trabajo el array a buscar
 * \param tam int el tamanio del array
 * \return int (0) si no encuentra ninguno (1) si hay al menos uno
 *
 */
int buscarTrabajo(Trabajo lista[], int tam);

/** \brief Busca la primer posicion libre en el array de Trabajos
 *
 * \param lista[] Trabajo el array de Trabajos
 * \return int el indice de la primer posicion libre en el array
 *
 */
int buscarTrabajoLibre(Trabajo lista[], int len);

/** \brief Carga en la primer posicion libre del array de Trabajos uno nuevo
 *
 * \param lista[] Trabajo el array de Trabajos
 * \param tam int el tamanio del array
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int altaTrabajo(Trabajo lista[], int tam, Marca marcas[], int tamMar, Tipo tipos[], int tamTip, Servicio servicios[],int tamServ, Notebook notebooks[],int tamNots, int *nextIdTrabajo);

/** \brief Muestra un Trabajo en pantalla
 *
 * \param m Trabajo una marca
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int mostrarTrabajo(Trabajo trabajo, Servicio servicios[],int tamServ, Notebook notebooks[],int tamNots, Marca marcas[],int tamMar);

/** \brief Muestra todos los Trabajos en pantalla
 *
 * \param lista[] Trabajo el array de Trabajos
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int mostrarTrabajos(Trabajo lista[], int tam, Servicio servicios[],int tamServ, Notebook notebooks[],int tamNots, Marca marcas[],int tamMar);

/** \brief Verifica que el id exista en el array de Trabajos
 *
 * \param lista[] Trabajo el array de Trabajos
 * \param tam int el tamanio del array
 * \return int (0) si no existe (1) si existe
 *
 */
int validarIdTrabajo(Trabajo lista[], int tam, int id);


#endif /* TRABAJO_H_ */
