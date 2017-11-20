#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{

    char nombre[50];
    int edad;
    int estado;
    int dni;

} EPersona;

void inicializarEstados(EPersona[],int);
/** \brief recorre todos los elementos EPersona e inicializa la variable estado a 0
 *
 * \param pers obtiene los datos de EPersona
 * \param tam obtiene el tamaño de los usuarios como EPersona
 *
 */
int buscarExistente(EPersona [],int, int);
/** \brief recorre todos los elementos EPersona para comparar sus dni con el que se ingreso en la alta
 *
 * \param p obtiene los parametros de EPersona
 * \param tp obtiene el tamaño de usuarios como EPersona
 * \param auxDNI recibe el valor ingresado en EPersona.dni
 * \return
 *
 */
void alta(EPersona[],int);
/** \brief se agrega una persona como EPersona
 *
 * \param persona obtiene los parametros del struct EPersona
 * \param tam recibe el valor de la cantidad de personas disponibles a ingresar
 * \param flag para comprobar si se pudo dar alta o no hay espacio disponible
 * \param n recibe el nombre ingresado en el string persona.nombre
 * \param existente determina si ya existe un dni ingresado previamente
 * \param idPer toma el valor de persona.dni
 * \return
 *
 */

void baja(EPersona[],int);
/** \brief se suprime una persona en base a su dni
 *
 * \param persona recibe los datos del struct EPersona
 * \param tam recibe la cantidad de personas disponibles
 * \param flag determina si se encontro a persona por su dni
 * \param auxDNI recibe el parametro de busqueda
 * \param rta recibe la opcion elegida por el usuario
 * \return
 *
 */
void ordenarXnombre(EPersona[],int);
/** \brief se ordena en una lista a todos las personas ingresadas alfabeticamente
 *
 * \param per obtiene los datos del struct EPersona
 * \param tam obtiene el tamaño de usuarios disponibles
 * \param aux guarda el valor de persona.nombre
 * \param auxEdad guarda el valor de persona.edad
 * \param auxDNI guarda el valor de persona.dni
 * \return
 *
 */
void imprimir(EPersona[],int);
/** \brief realiza un grafico representativo de las edades de las personas ingresadas
 *
 * \param a contador de edades menores a 19 anios
 * \param b contador de edades entre 19 y 35 anios
 * \param c contador de edades mayores a 36
 * \param max obtiene el contador que tiene mas edades
 * \param flag determina si la condicion es verdadera
 * \return
 *
 */

#endif // FUNCIONES_H_INCLUDED
