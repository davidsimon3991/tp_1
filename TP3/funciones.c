#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
//todos los desarrollos de funciones

void iniciarEstados(ePelicula*pelicula,int tam)
{
     for(int i=0; i<tam; i++)
    {
        if(pelicula[i].estado==0)
        {
            pelicula[i].id=-1;
        }


    }
}
int buscarIndice(ePelicula pelicula[],int tam)
{
    int index=-1;
    int i;
    for( i=0; i < tam; i++)
        if(pelicula[i].estado==0)
        {
            index=i;
            break;
        }
    return index;
}

void alta(ePelicula pelicula[],int tam)
{
    int index;
    int id;
    char titulo[20],descripcion[1000];
    int encontro=0;
    index=buscarIndice(pelicula,tam);
    if(index!=-1)
    {
        printf("Ingrese id: ");
        scanf("%d", &id);
        for(int i=0; i<tam; i++)
        {
            if(id==pelicula[i].id)
            {
                encontro=1;
                break;
            }
        }
        if(!encontro)
        {
            pelicula[index].id=id;
            printf("\ningrese titulo: ");
            fflush(stdin);
            gets(titulo);
            strlwr(titulo);

            titulo[0] = toupper(titulo[0]);

            for(int i=0; i<strlen(titulo); i++)
            {
                if(titulo[i] ==' ')
                {
                    titulo[i+1] = toupper(titulo[i+1]);
                }
            }
            strcpy(pelicula[index].titulo,titulo);

            printf("Ingrese genero: ");
            fflush(stdin);
            gets(pelicula[index].genero);
            strupr(pelicula[index].genero);

            printf("Ingrese duracion(MIN): ");
            scanf("%d", &pelicula[index].duracion);
            pelicula[index].estado=1;

            printf("Ingrese descripcion:");
            fflush(stdin);
            gets(descripcion);
            strlwr(descripcion);
            descripcion[0] = toupper(descripcion[0]);

            for(int i=0; i<strlen(descripcion); i++)
            {
                if(descripcion[i] =='.')
                {
                    descripcion[i+1] = toupper(descripcion[i+1]);
                }
            }
            strcpy(pelicula[index].descripcion,descripcion);
            system("cls");
        }
        else
        {
            printf("Ya existe ese ID\n");
            getch();
        }
    }
    else
    {
        printf("No hay espacio\n");
        getch();
    }
}

void baja(ePelicula* pelicula,int tam)
{
    int id, flag=0,i;
    char opcion;
    printf("Ingrese ID a dar de baja: ");
    scanf("%d", &id);
    for(i=0; i<tam; i++)
    {
        if(id==pelicula[i].id)
        {
            printf("Datos de la pelicula:\n");

            mensaje((pelicula + i));

            printf("\nEliminar?(s/n): ");
            opcion=getche();
            if(opcion=='s')
            {
                pelicula[i].estado=0;
                pelicula[i].id=-1;
                printf("Eliminada\n");
            }
            else
            {
                printf("Cancelado\n");
            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("No se encuentra el ID\n");
        getch();
    }
}
void modificar(ePelicula* pelicula,int tam)
{
    int id;
    int duracion;
    int flag=0,i;
    char opcion;
    char titulo[20],genero[20];
    system("cls");
    printf("Ingrese ID a modificar: ");
    scanf("%d",& id);
    for( i=0; i<tam; i++)
    {
        if(id==pelicula[i].id)
        {
            printf("Datos de la pelicula:\n");

            mensaje((pelicula + i));

            printf("Ingrese titulo: ");
            fflush(stdin);
            gets(titulo);
            printf("Ingrese genero: ");
            fflush(stdin);
            gets(genero);
            printf("Ingrese duracion(MIN): ");
            scanf("%d", &duracion);

            printf("Modificar?(s/n) ");
            fflush(stdin);
            opcion=getche();
            if(opcion=='s')
            {
                strcpy(pelicula[i].titulo,titulo);
                strcpy(pelicula[i].genero,genero);
                pelicula[i].duracion=duracion;

                printf("Hecho\n");
            }
            else
            {
                printf("Cancelado\n");
            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("No se encuentra el ID\n");
        getch();
    }
}

void listar(ePelicula *pelicula,int tam)
{
    ePelicula auxP;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<100; j++)
        {
            if(strcmp(pelicula[i].titulo,pelicula[j].titulo)>0)
            {
                auxP=pelicula[i];
                pelicula[i]=pelicula[j];
                pelicula[j]=auxP;
            }
        }
    }

    printf("Datos de peliculas\n\n");
    for(int i=0; i<tam; i++)
    {
        if(pelicula[i].estado==1)
            mensaje((pelicula + i));

    }
    getch();
}
void mensaje(ePelicula* pelicula)
{
    printf("ID:%d\nTitulo:%s\nGenero:%s\nDuracion(min):%d\nDescripcion:%s\n\n", pelicula->id, pelicula->titulo, pelicula->genero,pelicula->duracion,pelicula->descripcion);
}

int guardar(ePelicula * x,int tam)
{
    FILE *f;
    f=fopen("bin.dat","wb");
    if(f == NULL)
    {
        return 1;
    }

    fwrite(x,sizeof(ePelicula),tam,f);

    fclose(f);

    return 0;
}

int cargar(ePelicula *x,int tam)
{
    int flag = 0;
    FILE *f;

    f=fopen("bin.dat", "rb");
    if(f==NULL)
    {
        f= fopen("bin.dat", "wb");
        if(f==NULL)
        {
            return 1;
        }

        flag=1;

    }

    if(flag ==0)
    {
        fread(x,sizeof(ePelicula),tam,f);
    }
    fclose(f);
    return 0;

}
void crearHtml(ePelicula *x,int tam)
{
    FILE *f;
    f=fopen("peliculas.txt", "w");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        fprintf(f,"Peliculas\n");
        fprintf(f,"ID  Titulo  Genero  Duracion \n");

        for(int i=0; i<tam; i++)
        {
            if(x[i].estado == 1)
            {
                fprintf(f,"%d\t\%s\t%s\t\%d\n", x[i].id, x[i].titulo, x[i].genero, x[i].duracion);
            }
        }
    }

    fclose(f);

    printf("Hecho\n");
    system("pause");
}




