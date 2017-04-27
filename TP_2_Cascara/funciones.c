#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

void  inicializarEstados (EPersona pers[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        pers[i].estado=0;
    }

}
int buscarExistente(EPersona p[],int tp,int auxDNI)
{
    int flag =0;
    int encuentro = -1;

    for(int i =0; i<tp; i++)
    {
        if(p[i].estado ==1 && auxDNI == p[i].dni)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        encuentro =0;
    }
    return encuentro;
}


void alta(EPersona persona[],int tam)
{
    int flag=0;
    char n[60];
    int existente;
    int idPer;

    for(int i=0; i<tam; i++)
    {
        if(persona[i].estado==0)
        {
            printf("ingrese DNI: ");
            scanf("%d",&persona[i].dni);
            idPer=persona[i].dni;

            existente = buscarExistente(persona, tam, idPer);


            if(existente == -1)
            {
                printf("\nYa existe una persona con ese DNI\n");

                system("pause");
            }
            else
            {

                printf("\ningrese nombre: ");
                fflush(stdin);
                gets(n);
                strlwr(n);
                n[0] = toupper(n[0]);

                for(int i = 0; i<60; i++)
                {
                    if(n[i]==' ')
                    {
                        n[i+1]= toupper(n[i+1]);
                    }
                }
                strcpy(persona[i].nombre,n);

                printf("ingrese edad: ");
                scanf("%d",&persona[i].edad);
                while(persona[i].edad < 0 || persona[i].edad > 102)
                {
                    printf("edad no valida. Ingrese entre 1 a 102:");
                    scanf("%d", & persona[i].edad);
                }
                persona[i].estado=1;

            }


            flag=1;
            break;
        }

    }
    if(flag==0)
    {
        printf("\nNo hay espacio.\n\n");
    }
    return;
}

void baja(EPersona persona[],int tam)
{
    int flag =0;
    int auxDNI;
    char rta;
    printf("ingrese el DNI de la persona a eliminar: ");
    scanf("%d",&auxDNI);

    for(int i =0; i<tam; i++)
    {
        if(persona[i].estado ==1 && auxDNI == persona[i].dni)
        {
            printf("\n\t[DATOS DE LA PERSONA]\n\tNombre:%s\tEdad:%d\tDNI:%d", persona[i].nombre, persona[i].edad, persona[i].dni);

            printf("Esta seguro de eliminarlo?(s/n): ");
            rta= getche();

            if(rta=='s')
            {
                persona[i].estado=0;
            }
            else
            {
                printf("Accion cancelada.\n");
            }

            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("persona inexistente\n");
    }

}

void ordenarXnombre(EPersona per[],int tam)
{
    char aux[20];
    int auxEdad;
    int auxDNI;
    for(int i=0; i<tam-1; i++)
    {
        for(int j = i+1; j<tam; j++)
        {
            if(per[i].estado==1 && per[j].estado==1)

            {
                if(strcmp(per[i].nombre,per[j].nombre)>0)
                {
                    strcpy(aux,per[i].nombre);
                    strcpy(per[i].nombre,per[j].nombre);
                    strcpy(per[j].nombre,aux);

                    auxEdad = per[i].edad;
                    per[i].edad = per[j].edad;
                    per[j].edad= auxEdad;

                    auxDNI = per[i].dni;
                    per[i].dni=per[j].dni;
                    per[j].dni=auxDNI;
                }
            }
        }

    }
    printf("\n\t\t[LISTA ORDENADA POR NOMBRES]\n");
    for(int i =0; i<tam; i++)
    {
        if(per[i].estado==1)
        {
            printf("\tNombre: %s \t\tEdad: %d\tDNI: %d\n", per[i].nombre, per[i].edad, per[i].dni);
        }
    }

}

void imprimir(EPersona pers[],int tam)
{
    int a=0;
    int b=0;
    int c=0;
    int max;
    int flag=0;

    printf("[EDADES ORGANIZADAS POR CRITERIO]\n");
    for(int i=0; i<tam; i++)
    {
        if(pers[i].estado==1)
        {
            if(pers[i].edad<18)
            {
                a++;
            }
            else if(pers[i].edad>35)
            {
                c++;
            }
            else
            {
                b++;
            }
        }
    }
    if(a>=b && a>=c)
    {
        max = a;
    }
    else if(b>=a && b>=c)
    {
        max = b;
    }
    else
    {
        max = c;
    }
    for(int i=max; i>0; i--)
    {
        if(i<= a)
        {
            printf("\t*");
        }
        if(i<= b)
        {
            flag=1;
            printf("\t\t*");
        }

            if(i<= c)
            {
                if(flag==0)
                {
                    printf("\t\t\t*");
                }
                if(flag==1)
                {
                    printf("\t\t*");
                }
            }


        printf("\n");

    }

    printf("\t<18\t19-35\t>35\n");


}


