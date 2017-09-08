#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 100




int main()
{

    ePelicula peliculas[TAM];
    int opcion;
    char seguir ='s';
    char guardado;

    if(cargar(peliculas,TAM))
    {
        printf("No se pudo abrir el fichero");
    }
    else
    {
        printf("Se cargaron las peliculas con exito\n");
        iniciarEstados(peliculas,TAM);
    }

    system("pause");
    do
    {
        printf("1.Agregar pelicula.\n2.Borra pelicula.\n3.Modificar pelicula.\n");
        printf("4.Generar pagina web.\n5.Guardar todo.\n6.Listar.\n7.Salir\nIngrese opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            alta(peliculas,TAM);
            break;
        case 2:
            baja(peliculas,TAM);
            break;
        case 3:
            modificar(peliculas,TAM);
            break;
        case 4:
            crearHtml(peliculas,TAM);
            break;
        case 5:
            printf("\nguardar? S/N:");
            guardado=tolower(getche());
            if(guardado == 's')
            {
                if(guardar(peliculas,TAM))
                {
                    printf("\nNo se pudo guardar\n");
                }
                else
                {
                    printf("\nGuardado\n");
                }
            }
            break;
        case 6:
            listar(peliculas,TAM);
            break;
        case 7:
            seguir='n';
            break;
        default:
            printf("\nError. Opcion invalida.");
        }
        system("pause");
        system("cls");
    }
    while(seguir=='s');
    return 0;
}

