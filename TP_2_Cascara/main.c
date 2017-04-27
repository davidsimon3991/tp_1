#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAM 20

//me falta validar y arreglar los errorres

int main()
{
    char seguir='s';
    int opcion=0;

    EPersona pers[TAM];
    inicializarEstados(pers,TAM);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        printf("Ingrese opcion: ");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            alta(pers,TAM);
            break;
        case 2:
            baja(pers,TAM);
            break;
        case 3:
            ordenarXnombre(pers,TAM);
            break;
        case 4:
            imprimir(pers,TAM);
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("\nOpcion invalida.\n");
            break;
        }
        system("pause");
        system("cls");

    }

    return 0;
}


