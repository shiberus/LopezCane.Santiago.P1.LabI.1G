#include "Tipo.h"
#include "Marca.h"
#include "Duenio.h"
#ifndef NOTEBOOK_H_
#define NOTEBOOK_H_

typedef struct {
	int id;
	char modelo[21];
	int idMarca;
	int idTipo;
	int idCliente;
	int precio;
	int isEmpty;
} Notebook;

/** \brief Inicializa el array de Notebooks
 *
 * \param lista[] Notebook el array a inicializar
 * \param len int el tamanio del array
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int initNotebooks(Notebook lista[], int len);

/** \brief Busca al menos una notebook cargada del array de Notebooks
 *
 * \param lista[] Notebook el array a buscar
 * \param tam int el tamanio del array
 * \return int (0) si no encuentra ninguna (1) si hay al menos una
 *
 */
int buscarNotebook(Notebook lista[], int tam);

/** \brief Busca la primer posicion libre en el array de Notebooks
 *
 * \param lista[] Notebook el array de Notebooks
 * \return int el indice de la primer posicion libre en el array
 *
 */
int buscarNotebookLibre(Notebook lista[], int len);

/** \brief Busca la notebook correspondiente en el array de Notebooks
 *
 * \param lista[] Notebook el array de Notebooks
 * \param tam int tamanio del array de Notebooks
 * \param id int el id a buscar
 * \return int el indice de notebook o -1 si no la encuentra
 *
 */
int buscarNotebookId(Notebook lista[], int len, int id);

/** \brief Carga en la primer posicion libre del array de Notebooks uno nuevo
 *
 * \param lista[] Notebook el array de Notebooks
 * \param tam int tamanio del array de Notebooks
 * \param marcas[] Marca el array de marcas
 * \param tam int tamanio del array de marcas
 * \param tipos[] Tipo el array de tipos
 * \param tam int tamanio del array de tipos
 * \param nextId int* puntero al suiguiente id a asignarse
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int altaNotebook(Notebook lista[], int tam, Marca marcas[], int tamMar, Tipo tipos[], int tamTip, Cliente clientes[], int tamCli, int *nextId);

/** \brief Muestra un tipo en pantalla
 *
 * \param m Notebook una marca
 * \param marcas[] Marca el array de marcas
 * \param tam int tamanio del array de marcas
 * \param tipos[] Tipo el array de tipos
 * \param tam int tamanio del array de tipos
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int mostrarNotebook(Notebook m, Marca marcas[], int tamMar, Tipo tipos[], int tamTip, Cliente clientes[], int tamCli);

/** \brief Muestra todos los tipos en pantalla
 *
 * \param lista[] Notebook el array de Notebooks
 * \param marcas[] Marca el array de marcas
 * \param tam int tamanio del array de marcas
 * \param tipos[] Tipo el array de tipos
 * \param tam int tamanio del array de tipos
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int mostrarNotebooks(Notebook lista[], int tam, Marca marcas[], int tamMar, Tipo tipos[], int tamTip, Cliente clientes[], int tamCli);

/** \brief Modifica precio y/o tipo de una notebook
 *
 * \param lista[] Notebook el array de Notebooks
 * \param tam int tamanio del array de Notebooks
 * \param marcas[] Marca el array de marcas
 * \param tam int tamanio del array de marcas
 * \param tipos[] Tipo el array de tipos
 * \param tam int tamanio del array de tipos
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int modificarNotebook(Notebook lista[], int tam, Marca marcas[], int tamMar, Tipo tipos[], int tamTip, Cliente clientes[], int tamCli);

/** \brief Elimina de forma logica una notebook del array
 *
 * \param lista[] Notebook el array de Notebooks
 * \param tam int tamanio del array de Notebooks
 * \param marcas[] Marca el array de marcas
 * \param tam int tamanio del array de marcas
 * \param tipos[] Tipo el array de tipos
 * \param tam int tamanio del array de tipos
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int bajaNotebook(Notebook lista[], int tam, Marca marcas[], int tamMar, Tipo tipos[], int tamTip, Cliente clientes[], int tamCli);

#endif /* NOTEBOOK_H_ */
