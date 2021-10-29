/*
 * Util.h
 *
 *  Created on: 22 oct. 2021
 *      Author: Dell
 */

#ifndef UTIL_H_
#define UTIL_H_

#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED


/** \brief Pide al usuario un string con un minimo y maximo de caracteres
 *
 * \param destino char* string donde se guarda el input
 * \param mensaje char* mensaje que se le muestra al usuario
 * \param min int minimo de caracteres
 * \param max int maximo de caracteres
 * \return int (0) todo Ok (-1) error
 *
 */
int ingresarString(char *destino, char *mensaje, int min, int max);


/** \brief Valida que un string solo contenga letras y espacios
 *
 * \param str[] char el string a ser evaluado
 * \return int (0) si es valido (-1) si es invalido
 *
 */
int validarLetras(char *str);

#endif // UTIL_H_INCLUDED

#endif /* UTIL_H_ */
