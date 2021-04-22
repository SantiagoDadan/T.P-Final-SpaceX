#include <stdio.h>
#include <stdlib.h>
#include "Inicio.h"

//En el main llamamos a la funciones que se encuentra en el inicio.
int main()
{
    char control = 's', opcion;

    carga1();

    while(control == 's' || control == 'S')
    {
        pantallaInicio();
        opcion = Menu();

        if(opcion != 0)
        {
            printf("\nIngrese ''s'' para volver al menu principal o ''n'' para salir\n\n");
            fflush(stdin);
            scanf("%c", &control);

            system("cls");
        }else
        {
            break;
        }
    }

    return 0;
}

