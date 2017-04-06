#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



int main()
{
    char seguir='s';
    int opcion=0;
    int flag_A =0;
    int flag_B =0;
    float numA;
    float numB;

    while(seguir=='s')
    {
        if(flag_A ==0)
        {
            printf("1- Ingresar 1er operando (A = X)\n");
        }
        else
        {
            printf("1- Ingresar 1er operando (A= %.2f)\n", numA);
        }
        if(flag_B ==0)
        {
            printf("2- Ingresar 2do operando (B = Y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%.2f)\n", numB);
        }

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
        scanf("%d",&opcion);


        switch(opcion)
        {
        case 1:
            numA = numero_A();
            flag_A = 1;
            break;
        case 2:
            numB = numero_B();
            flag_B =1;
            break;
        case 3:
            sumar(numA, numB);
            break;
        case 4:
            restar(numA, numB);
            break;
        case 5:
            dividir(numA,numB);
            break;
        case 6:
            multiplicar(numA,numB);
            break;
        case 7:
            factoreo(numA);
            break;
        case 8:
            operaciones(numA,numB);
            break;
        case 9:
            seguir = 'n';
            break;
        }
        system("pause");
        system("cls");


    }

    return 0;
}

