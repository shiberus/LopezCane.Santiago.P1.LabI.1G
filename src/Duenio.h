/*
 * Cliente.h
 *
 *  Created on: 29 oct. 2021
 *      Author: Dell
 */

#ifndef Cliente_H_
#define Cliente_H_

typedef struct {
	int id;
	char nombre[21];
	char sexo;
	int isEmpty;
} Cliente;

/** \brief Inicializa el array de Clientes
 *
 * \param lista[] Cliente el array a inicializar
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int initClientes(Cliente lista[], int len);

/** \brief Busca al menos un Cliente cargado en el array
 *
 * \param lista[] Cliente el array a buscar
 * \param tam int el tamanio del array
 * \return int (0) si no encuentra ninguno (1) si hay al menos uno
 *
 */
int buscarCliente(Cliente lista[], int tam);

/** \brief Busca el cliente correspondiente en el array de Cliente
 *
 * \param lista[] Cliente el array de Clientes
 * \param tam int tamanio del array de Clientes
 * \param id int el id a buscar
 * \return int el indice de cliente o -1 si no la encuentra
 *
 */
int buscarClienteId(Cliente lista[], int tam, int id);

/** \brief Busca la primer posicion libre en el array de Clientes
 *
 * \param lista[] Cliente el array de Clientes
 * \return int el indice de la primer posicion libre en el array
 *
 */
int buscarClienteLibre(Cliente lista[], int len);

/** \brief Carga en la primer posicion libre del array de Clientes uno nuevo
 *
 * \param lista[] Cliente el array de Clientes
 * \param tam int el tamanio del array
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int altaCliente(Cliente lista[], int tam);

/** \brief Muestra un Cliente en pantalla
 *
 * \param m Cliente una marca
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int mostrarCliente(Cliente m);

/** \brief Muestra todos los Clientes en pantalla
 *
 * \param lista[] Cliente el array de Clientes
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int mostrarClientes(Cliente lista[], int tam);

/** \brief Verifica que el id exista en el array de Clientes
 *
 * \param lista[] Cliente el array de Clientes
 * \param tam int el tamanio del array
 * \return int (0) si no existe (1) si existe
 *
 */
int validarIdCliente(Cliente lista[], int tam, int id);

/** \brief Carga el nombre del Cliente en una variable
 *
 * \param lista[] Cliente el array de Clientes
 * \param tam int el tamanio del array
 * \param id int el id del Cliente
 * \param *nombre char string de destino
 * \return int (0) si no existe (1) si existe
 *
 */
int cargarNombreCliente(Cliente lista[], int tam, int id, char *nombre);


#endif /* Cliente_H_ */
