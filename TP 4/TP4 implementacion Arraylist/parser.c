#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile, ArrayList* pArrayListEmployee)
{
    int pudoParsear=0;
    Employee * empleado;
    pFile = fopen("data.csv", "r");
    char name[500], lastName[500], id[500],isEmpty[500];
    int cont =1;
    int isEmpty_int=0;

    if(pFile == NULL)
    {
        printf("\nNo se pudo abrir el archivo!!");
        exit(1);
    }
    while(!feof(pFile))
    {

        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, lastName,isEmpty);
        if(strcmp(isEmpty,"true")==0)
        {
            isEmpty_int=1;
        }
        empleado = employee_new_withData(atoi(id),name,lastName,isEmpty_int);
        if(!strcmp(name,"first_name")==0)
        {
            pArrayListEmployee->add(pArrayListEmployee, empleado);
            isEmpty_int=0;
            pudoParsear=1;
        }



    }
    fclose(pFile);
    return pudoParsear;
}
