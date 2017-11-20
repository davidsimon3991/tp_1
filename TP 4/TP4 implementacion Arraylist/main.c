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
    int isEmpty_int;


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
