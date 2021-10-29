#ifndef FECHA_H_
#define FECHA_H_

typedef struct {
	int dia;
	int mes;
	int anio;
} Fecha;

/** \brief Ingresa y valida una fecha
 *
 * \param *fecha Fecha puntero a la fecha a cargar
 * \return int (0) si no hay error (-1) si hay error
 *
 */
int cargarFecha(Fecha *fecha);

#endif /* FECHA_H_ */
