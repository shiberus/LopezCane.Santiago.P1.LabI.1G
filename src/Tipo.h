#ifndef TIPO_H_
#define TIPO_H_

typedef struct {
	int id;
	char descripcion[21];
	int isEmpty;
} Tipo;

/** \brief Inicializa el array de Tipos
 *
 * \param lista[] Tipo el array a inicializar
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int initTipos(Tipo lista[], int len);

/** \brief Busca al menos un tipo cargado en el array
 *
 * \param lista[] Tipo el array a buscar
 * \param tam int el tamanio del array
 * \return int (0) si no encuentra ninguno (1) si hay al menos uno
 *
 */
int buscarTipo(Tipo lista[], int tam);

/** \brief Busca la primer posicion libre en el array de Tipos
 *
 * \param lista[] Tipo el array de Tipos
 * \return int el indice de la primer posicion libre en el array
 *
 */
int buscarTipoLibre(Tipo lista[], int len);

/** \brief Carga en la primer posicion libre del array de Tipos uno nuevo
 *
 * \param lista[] Tipo el array de Tipos
 * \param tam int el tamanio del array
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int altaTipo(Tipo lista[], int tam);

/** \brief Muestra un tipo en pantalla
 *
 * \param m Tipo una marca
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int mostrarTipo(Tipo m);

/** \brief Muestra todos los tipos en pantalla
 *
 * \param lista[] Tipo el array de Tipos
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int mostrarTipos(Tipo lista[], int tam);

/** \brief Verifica que el id exista en el array de Tipos
 *
 * \param lista[] Tipo el array de Tipos
 * \param tam int el tamanio del array
 * \return int (0) si no existe (1) si existe
 *
 */
int validarIdTipo(Tipo lista[], int tam, int id);

/** \brief Carga la descripcion del tipo en una variable
 *
 * \param lista[] Tipo el array de Tipos
 * \param tam int el tamanio del array
 * \param id int el id del tipo
 * \param *descripcion char string de destino
 * \return int (0) si no existe (1) si existe
 *
 */
int cargarDescripcionTipo(Tipo lista[], int tam, int id, char *descripcion);

#endif /* TIPO_H_ */
