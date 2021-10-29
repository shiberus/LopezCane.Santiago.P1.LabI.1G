#ifndef MARCA_H_
#define MARCA_H_

typedef struct {
	int id;
	char descripcion[21];
	int isEmpty;
} Marca;

/** \brief Inicializa el array de Marcas
 *
 * \param lista[] Marca el array a inicializar
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int initMarcas(Marca lista[], int len);

/** \brief Busca al menos una Marca cargada del array de Marcas
 *
 * \param lista[] Marca el array a buscar
 * \param tam int el tamanio del array
 * \return int (0) si no encuentra ninguna (1) si hay al menos una
 *
 */
int buscarMarca(Marca lista[], int tam);

/** \brief Busca la primer posicion libre en el array de Marcas
 *
 * \param lista[] Marca el array de Marcas
 * \return int el indice de la primer posicion libre en el array
 *
 */
int buscarMarcaLibre(Marca lista[], int len);

/** \brief Carga en la primer posicion libre del array de Marcas una nueva
 *
 * \param lista[] Marca el array de Marcas
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int altaMarca(Marca lista[], int tam);

/** \brief Muestra una marca en pantalla
 *
 * \param m Marca una marca
 * \param tam int el tamanio del array
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int mostrarMarca(Marca m);

/** \brief Muestra todas las marcas en pantalla
 *
 * \param lista[] Marca el array de Marcas
 * \param tam int el tamanio del array
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int mostrarMarcas(Marca lista[], int tam);

/** \brief Verifica que el id exista en el array de Marcas
 *
 * \param lista[] Tipo el array de Marcas
 * \param tam int el tamanio del array
 * \return int (0) si no existe (1) si existe
 *
 */
int validarIdMarca(Marca lista[], int tam, int id);

/** \brief Carga la descripcion de la marca en una variable
 *
 * \param lista[] Marca el array de marcas
 * \param tam int el tamanio del array
 * \param id int el id de la marca
 * \param *descripcion char string de destino
 * \return int (0) si no existe (1) si existe
 *
 */
int cargarDescripcionMarca(Marca lista[], int tam, int id, char *descripcion);

#endif /* MARCA_H_ */
