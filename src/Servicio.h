#include "Marca.h"
#include "Notebook.h"

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct {
	int id;
	char descripcion[21];
	float precio;
	int isEmpty;
} Servicio;

/** \brief Inicializa el array de Servicios
 *
 * \param lista[] Servicio el array a inicializar
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int initServicios(Servicio lista[], int len);

/** \brief Busca al menos un Servicio cargado en el array
 *
 * \param lista[] Servicio el array a buscar
 * \param tam int el tamanio del array
 * \return int (0) si no encuentra ninguno (1) si hay al menos uno
 *
 */
int buscarServicio(Servicio lista[], int tam);

/** \brief Busca el servicio correspondiente en el array de Servicios
 *
 * \param lista[] Servicio el array de Servicios
 * \param tam int tamanio del array de Servicios
 * \param id int el id a buscar
 * \return int el indice de servicio o -1 si no lo encuentra
 *
 */
int buscarServicioId(Servicio lista[], int len, int id);

/** \brief Busca la primer posicion libre en el array de Servicios
 *
 * \param lista[] Servicio el array de Servicios
 * \return int el indice de la primer posicion libre en el array
 *
 */
int buscarServicioLibre(Servicio lista[], int len);

/** \brief Carga en la primer posicion libre del array de Servicios uno nuevo
 *
 * \param lista[] Servicio el array de Servicios
 * \param tam int el tamanio del array
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int altaServicio(Servicio lista[], int tam);

/** \brief Muestra un Servicio en pantalla
 *
 * \param m Servicio una marca
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int mostrarServicio(Servicio m);

/** \brief Muestra todos los Servicios en pantalla
 *
 * \param lista[] Servicio el array de Servicios
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int mostrarServicios(Servicio lista[], int tam);

/** \brief Verifica que el id exista en el array de Servicios
 *
 * \param lista[] Servicio el array de Servicios
 * \param tam int el tamanio del array
 * \return int (0) si no existe (1) si existe
 *
 */
int validarIdServicio(Servicio lista[], int tam, int id);

/** \brief Carga la descripcion del Servicio en una variable
 *
 * \param lista[] Servicio el array de Servicios
 * \param tam int el tamanio del array
 * \param id int el id del Servicio
 * \param *descripcion char string de destino
 * \return int (0) si no existe (1) si existe
 *
 */
int cargarDescripcionServicio(Servicio lista[], int tam, int id, char *descripcion);


#endif /* SERVICIO_H_ */
