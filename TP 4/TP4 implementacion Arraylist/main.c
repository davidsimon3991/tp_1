#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

#define TAM 3

/****************************************************
    Menu:
       1. Parse del archivo data.csv
       2. Listar Empleados
       3. Ordenar por nombre
       4. Agregar un elemento
       5. Eliminar un elemento
       6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    FILE *p;
    ArrayList * lista = al_newArrayList();
    int rta;
    int cont=0;
    Employee * e1;

    char nombre[50], apellido[50];
<<<<<<< HEAD
    int isEmpty_int;
=======
    int isEmpty_int, inicio,fin;
>>>>>>> 16519056a874d9ff6db07831aa32c9324d00035b


    int opcion;
    char seguir = 's';

    do
    {
        system("cls");
        printf("1.Parser de empleados\n2.Listar empleados\n3.Ordenar por nombre");
        printf("\n4.Agregar un elemento\n5.Eliminar un elemento\n6.Listar empleados (desde/hasta)");
        printf("\n0.Salir");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            rta = parserEmployee(p, lista);
            if(rta==1)
            {
                printf("\nSe parsearon los empleados");
            }
            else
            {
                printf("\nNo se pudo parsear");
            }
            break;
        case 2:
<<<<<<< HEAD
=======
            printf("\nID    isEmpty\tFull name\n");
>>>>>>> 16519056a874d9ff6db07831aa32c9324d00035b
            employee_printEmployees(lista);
            break;
        case 3:
            lista->sort(lista, employee_compare,1);
            break;
        case 4:
            employee_alta(lista);
            break;
        case 5:
            employee_delete(lista);
            break;
<<<<<<< HEAD
=======
        case 6:
            printf("ingrese valor inicial: ");
            scanf("%d",&inicio);
            printf("ingrese valor inicial: ");
            scanf("%d",&fin);
            printf("\nID    isEmpty\tFull name\n");
            printFromWhere(lista,inicio,fin);
            break;
>>>>>>> 16519056a874d9ff6db07831aa32c9324d00035b
        case 0:
            seguir='n';
            break;
        default:
            printf("\nOpcion invalida!");
        }
        system("pause");
    }
    while(seguir=='s');

    return 0;
}
