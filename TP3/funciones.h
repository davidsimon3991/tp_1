#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define A 100
#define ESC 27
#define ARCH "./bin.dat"


// todos los prototipos de funciones
typedef struct
{
    int estado;
    int id;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[100];
    int puntaje;
    char linkImagen[50];
} ePelicula;

void iniciarEstados(ePelicula*,int);
int buscarIndice(ePelicula*,int);
/** \brief busca si hay espacio en el indice
 *
 * \param index devuelve el valor que tomara la estructura para guardarse
 * \return 1 si encontro 0 si no hay espacio
 *
 */


void alta(ePelicula*,int);
/** \brief dar de alta a una nueva pelicula para registrar
 *
 * \param index obtiene el valor de buscarIndice
 * \param id recibe el valor que se da de alta para la pelicula
 * \param encontro comprueba si ya existe el ID ingresado. -1 si encontro 0 si no encontro
 * \return
 *
 */
void baja(ePelicula*,int);
/** \brief dar de baja una pelicula en base a ID
 *
 * \param id recibe el valor que se da para la baja
 * \param flag determina si encontro igualdad de ID. 1 si encontro 0 si no encontro
 * \return
 *
 */

void modificar(ePelicula*,int);
/** \brief modificar una pelicula en base a ID
 *
 * \param id recibe el valor que se da para la modificacion
 * \param duracion obtiene el nuevo valor de duracion de la pelicula
 * \param flag determina si encontro igualdad de ID. 1 si encontro 0 si no encontro
 * \param opcion obtiene el caracter del teclado. 's' para aceptar la modificacion !='s' para cancelar
 * \param titulo obtiene el nuevo valor de titulo de la pelicula
 * \param genero obtiene el nuevo valor de genero de la pelicula
 * \return
 *
 */
void listar(ePelicula*,int);
/** \brief muestra una lista ordenada en memoria de todas las peliculas guardadas
 *
 * \param auxP se utiliza como auxiliar para el metodo de burbujeo
 * \return
 *
 */
void mensaje(ePelicula*);
/** \brief  muestra los datos de una pelicula
 *
 * \param f puntero que recorre la lista de peliculas
 * \return
 *
 */
int guardar(ePelicula *,int);
/** \brief guarda todos los registros realizados en memoria en un archivo binario
 *
 * \param f recorre la lista de peliculas
 * \return
 *
 */
int cargar(ePelicula *,int);
/** \brief carga un archivo binario que contiene las peliculas
 *
 * \param f recorre la lista de peliculas
 * \return
 *
 */
void crearHtml(ePelicula *,int);
/** \brief da formato html a un archivo que contiene las peliculas del archivo binario
 *
 * \param f recorre la lista de peliculas
 * \return
 *
 */


#endif // FUNCIONES_H_INCLUDED


