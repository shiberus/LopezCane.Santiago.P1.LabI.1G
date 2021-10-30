#include "Trabajo.h"

#ifndef INFORMES_H_
#define INFORMES_H_

/** \brief muestra todos los trabajos realizados a una notebook
 *  
 * \param lista[] Trabajo el array de Trabajos
 * \param tam int tamanio del array de Trabajos
 * \param servicios[] Servicio el array de Servicios
 * \param tamServ int tamanio del array de Servicios
 * \param notebooks[] Notebooks el array de Notebooks
 * \param tamNots int tamanio del array de Notebooks
 * \param marcas[] Marca el array de Marca
 * \param tamMar int tamanio del array de Marca
 * \param tipos[] Tipos el array de Tipos
 * \param tamTip int tamanio del array de Tipos
 * \param clientes[] Clientes el array de Clientes
 * \param tamCli int tamanio del array de Clientes
 * 
 * \return int -1 on error 0 on success
 **/ 
int mostrarTrabajosNotebook(Trabajo lista[], int tamTra, Servicio servicios[],int tamServ, Notebook notebooks[],int tamNots, Marca marcas[],int tamMar, Tipo tipos[], int tamTip, Cliente clientes[], int tamCli);

/** \brief informa la suma de los importes de todos los servicios para una notebook
 *  
 * \param lista[] Trabajo el array de Trabajos
 * \param tam int tamanio del array de Trabajos
 * \param servicios[] Servicio el array de Servicios
 * \param tamServ int tamanio del array de Servicios
 * \param notebooks[] Notebooks el array de Notebooks
 * \param tamNots int tamanio del array de Notebooks
 * \param marcas[] Marca el array de Marca
 * \param tamMar int tamanio del array de Marca
 * \param tipos[] Tipos el array de Tipos
 * \param tamTip int tamanio del array de Tipos
 * \param clientes[] Clientes el array de Clientes
 * \param tamCli int tamanio del array de Clientes
 * 
 * \return int -1 on error 0 on success
 **/ 
int informarSumaImporteServiciosDeNotebook(Trabajo trabajos[], int tamTra, Servicio servicios[],int tamServ, Notebook notebooks[],int tamNots, Marca marcas[],int tamMar, Tipo tipos[], int tamTip, Cliente clientes[], int tamCli);

/** \brief muestra todas las notebooks a las que se le realizo un servicio y la fecha
 *  
 * \param lista[] Trabajo el array de Trabajos
 * \param tam int tamanio del array de Trabajos
 * \param servicios[] Servicio el array de Servicios
 * \param tamServ int tamanio del array de Servicios
 * \param notebooks[] Notebooks el array de Notebooks
 * \param tamNots int tamanio del array de Notebooks
 * \param marcas[] Marca el array de Marca
 * \param tamMar int tamanio del array de Marca
 * \param tipos[] Tipos el array de Tipos
 * \param tamTip int tamanio del array de Tipos
 * \param clientes[] Clientes el array de Clientes
 * \param tamCli int tamanio del array de Clientes
 * 
 * \return int -1 on error 0 on success
 **/ 
int mostrarNotebooksServicio(Trabajo trabajos[], int tamTra, Servicio servicios[],int tamServ, Notebook notebooks[],int tamNots, Marca marcas[],int tamMar, Tipo tipos[], int tamTip, Cliente clientes[], int tamCli);


/** \brief muestra todos los servicios realizados en una fecha
 *  
 * \param servicios[] Servicio el array de Servicios
 * \param tamServ int tamanio del array de Servicios
 * \param trabajos[] Trabajo el array de Trabajos
 * \param tamTra int tamanio del array de Trabajos
 * 
 * \return int -1 on error 0 on success
 **/ 
int mostrarServiciosFecha(Servicio servicios[], int tamServ, Trabajo trabajos[], int tamTra);

/** \brief Interfaz para ver los informes
 *  
 * \param lista[] Trabajo el array de Trabajos
 * \param tam int tamanio del array de Trabajos
 * \param servicios[] Servicio el array de Servicios
 * \param tamServ int tamanio del array de Servicios
 * \param notebooks[] Notebooks el array de Notebooks
 * \param tamNots int tamanio del array de Notebooks
 * \param marcas[] Marca el array de Marca
 * \param tamMar int tamanio del array de Marca
 * \param tipos[] Tipos el array de Tipos
 * \param tamTip int tamanio del array de Tipos
 * \param clientes[] Clientes el array de Clientes
 * \param tamCli int tamanio del array de Clientes
 * 
 * \return int -1 on error 0 on success
 **/ 
int menuInformes(Trabajo trabajos[], int tamTra, Servicio servicios[],int tamServ, Notebook notebooks[],int tamNots, Marca marcas[],int tamMar, Tipo tipos[], int tamTip, Cliente clientes[], int tamCli);


#endif /* INFORMES_H_ */
