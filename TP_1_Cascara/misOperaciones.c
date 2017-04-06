#include <stdio.h>

float numero_A()
{
    float num;
    printf("ingrese numero: ");
    scanf("%f",&num);
    return num;
}
float numero_B()
{
    float num;
    printf("ingrese numero:");
    scanf("%f",&num);
    return num;
}

void sumar(float x, float y)
{
    float rdo;
    rdo = x+y;
    printf("la suma entre %.2f y %.2f es: %.2f \n",x,y,rdo);
}
void restar(float x, float y)
{
    float rdo;
    rdo = x-y;
    printf("la resta entre %.2f y %.2f es: %.2f\n", x,y,rdo);
}
void dividir(float x, float y)
{
    float rdo;
    if(y == 0)
    {
        printf("!!! ERROR EN LA DIVISION !!!. No se puede dividir por cero \n");
    }
    else
    {
        rdo =  x/y;
        printf("la division entre %.2f y %.2f es: %.2f \n", x,y,rdo);
    }
}

void multiplicar(float x, float y)
{
    float rdo;
    rdo = x*y;
    printf("multiplicar %.2f y %.2f da como resultado: %.2f \n", x, y, rdo);
}
void factoreo(int x)
{
    int fact = 1;
    for (int i = x; i > 1; i--)
    {
        fact = fact * i;
    }
    printf("el factorial de %d es %d \n", x,fact);
}
void operaciones(float x,float y)
{
    sumar(x,y);
    restar(x,y);
    dividir(x,y);
    multiplicar(x,y);
    factoreo(x);
}
