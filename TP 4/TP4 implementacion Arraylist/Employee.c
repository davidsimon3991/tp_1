#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    if(strcmp(((Employee*)pEmployeeA)->lastName, ((Employee*)pEmployeeB)->lastName)>0)
    {
        return 1;
    }
    if(strcmp(((Employee*)pEmployeeA)->lastName, ((Employee*)pEmployeeB)->lastName)<0)
    {
        return -1;
    }
    return 0;
}

void employee_print(Employee* this)
{
    if(this!=NULL)
    {
        printf("%d\t%d\t%s,%s\n", this->id,this->isEmpty,this->lastName,this->name);
    }
}
void employee_printEmployees(ArrayList* listaEmpleados)
{
    int cont=0;
<<<<<<< HEAD
    printf("\nID    isEmpty\tFull name\n");
=======

>>>>>>> 16519056a874d9ff6db07831aa32c9324d00035b
    for(int i =0; i<listaEmpleados->size; i++)
    {
        if(cont % 250==0)
        {
            system("pause");
            printf("\nID    isEmpty\tFull name\n");
        }
        employee_print(listaEmpleados->pElements[i]);
        cont++;
    }
}
<<<<<<< HEAD

=======
void printFromWhere(ArrayList* listaEmpleados,int inicio,int fin)
{
    int cont=0;
    printf("\nID    isEmpty\tFull name\n");
    for(int i = inicio; i<fin; i++)
    {
        if(cont % 250==0)
        {
            system("pause");
            printf("\nID    isEmpty\tFull name\n");
        }
        employee_print(listaEmpleados->pElements[i]);
        cont++;
    }
}
>>>>>>> 16519056a874d9ff6db07831aa32c9324d00035b

Employee* employee_new(void)
{
    Employee* returnAux = NULL;

    returnAux = (Employee*) malloc(sizeof(Employee*));

    if(returnAux!=NULL)
    {
        returnAux->id=21214;
        strcpy(returnAux->name,"Empleado nombre");
        strcpy(returnAux->lastName,"Empleado apellido");
        returnAux->isEmpty=0;
    }

    return returnAux;

}
Employee* employee_new_withData(int id,char* nombre,char* apellido,int isEmpty)
{
    Employee* returnAux = NULL;

    returnAux = (Employee*) malloc(sizeof(Employee));

    if(returnAux!=NULL)
    {
        returnAux->id=id;
        strcpy(returnAux->name,nombre);
        strcpy(returnAux->lastName,apellido);
        returnAux->isEmpty=isEmpty;
    }

    return returnAux;
}
Employee* employee_alta(ArrayList* listaEmpleados)
{
    Employee* empleado = employee_new();
    int id;
    char apellido[51];
    char nombre[51];
    int isEmpty;
    if(empleado!=NULL)
    {
        printf("Ingrese id:");
        scanf("%d",&id);
        printf("Ingrese apellido:");
        fflush(stdin);
        gets(apellido);
        printf("Ingrese nombre:");
        fflush(stdin);
        gets(nombre);
        printf("Is empty? 1.Si / 0.No:");
        scanf("%d",&isEmpty);
        empleado = employee_new_withData(id,nombre,apellido,isEmpty);
        if(empleado!=NULL)
        {
            listaEmpleados->add(listaEmpleados,empleado);
            printf("Agregado");
        }
        else
        {
            printf("No se pudo agregar");
        }
    }

    return empleado;
}

void employee_delete(ArrayList* listaEmpleados)
{
    int intAux,index;
    int flag;
    char rta='N';

    printf("ingrese ID: ");
    scanf("%d",&intAux);
    if(buscarID(listaEmpleados,intAux)==1)
    {
        employee_print(listaEmpleados);
        printf("Desea eliminar ? Y/N");
        fflush(stdin);
        scanf("%c",&rta);
        rta=toupper(rta);
        if(rta=='Y')
        {
            index=employee_getId(listaEmpleados,intAux);
            if(index!=-1)
            {
                if(!listaEmpleados->remove(listaEmpleados,index))
                {
                    printf("Eliminado");
                }
            }
        }
        else
        {
            printf("Accion cancelada");
        }
    }
    else
    {
        printf("No se encuentra ese ID");
    }
    //this->isEmpty=1;
}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(ArrayList* listaEmpleados,int idAux)
{

    Employee* empleado;
    int returnAux=-1;
    int i;
    for(i=0;i<listaEmpleados->size;i++)
    {
        empleado=listaEmpleados->get(listaEmpleados,i);
        if(empleado->id==idAux)
        {
            returnAux=i;
            break;
        }
    }
    return returnAux;

}

int buscarID(ArrayList * listaEmpleados,int id)
{
    int returnAux=0;
    Employee * empleado;
    for(int i=0; i<listaEmpleados->size; i++)
    {
        empleado = listaEmpleados->get(listaEmpleados,i);
        if(empleado->id==id)
        {
            returnAux=1;
        }
    }

    return returnAux;
}

