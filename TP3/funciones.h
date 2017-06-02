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
}ePelicula;

int buscarIndice(ePelicula*);

void alta(ePelicula*);
void baja(ePelicula*);
void modificar(ePelicula*);

void listar(ePelicula*);
void mensaje(ePelicula*);
int guardar(ePelicula *);
int cargar(ePelicula *);
void crearHtml(ePelicula *);






#endif // FUNCIONES_H_INCLUDED


