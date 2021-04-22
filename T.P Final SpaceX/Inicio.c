#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include <conio.h>
#include <time.h>
#include "Inicio.h"
#include "menuA.h"
#include "menuN.h"
#include "menuM.h"

//Presentacion del programa
void carga1()
{
    int i;

    gotoxy(53, 17); printf("Cargando");

    for(i = 0; i < 13; i++)
    {

        gotoxy(40+(i*3), 15); printf("|"); Sleep(110);
    }
    system("cls");

    return 0;
}
//Pantalla de inicio SpaceX
void pantallaInicio()
{
    int i;

    time_t tiempoahora;
    time(&tiempoahora);
    struct tm *mitiempo = localtime(&tiempoahora);

    printf("Fecha:  %d/%d/%d", mitiempo->tm_mday, mitiempo->tm_mon+1, mitiempo->tm_year+1900);
    printf("\nHora:   %d:%d", mitiempo->tm_hour, mitiempo->tm_min);

    color(9);printf("\n\n\t\t\t       ssssss  ppppp.  aaa  -.-.-.  ccccc  eeeeee -.-  xx      xx");
    printf("\n\t\t\t       ssssss  pp  'p    aa  .-.-. cccccc  ee'    .-.-  xx    xx");
    printf("\n\t\t\t       ss      pp  .p    .aa  -.-. cc'            -.-.-  xx  xx ");
    printf("\n\t\t\t       sssss.  ppppp'  aaaaaa  .-. cc      eeeeee .-.-.-  .xx.  ");
    printf("\n\t\t\t       'sssss  pp  -.-.-.  'aa  .- cc      ee'    -.-.-.  .xx.  ");
    printf("\n\t\t\t           ss  pp  .-.-.-.   aa    cc.     ee     .-.-.  xx  xx ");
    printf("\n\t\t\t       ssssss  pp  -.-.-.-.   aa   cccccc  ee.    -.-.  xx    xx");
    printf("\n\t\t\t       ssssss  pp  .-.-.-.-.   aa   ccccc  eeeeee .-.  xx      xx \n\n ");color(15);

    for(i = 0; i < 120; i++)
    {
       color(128);gotoxy(i, 13);printf("_");
    }
    color(15);

    return 0;
}
//Imprime el menu principal del programa, y pide que se seleccione una opcion
int Menu()
{
    int opcion;

    do
    {
    printf("\n\nEscoja una opcion:");
    printf("\n\n\t1 - Astronautas\n");
    printf("\t2 - Naves\n");
    printf("\t3 - Misiones\n");
    printf("\t0 - Salir\n");

    scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            menuAstronautas();
            break;

        case 2:

            menuNaves();
            break;

        case 3:
            MenuMisiones();
            break;

        case 0:

            break;

        default:

            system("cls");
            printf("\nUsted ingreso una opcion no valida\n\n");
            break;
        }
    }
    while(opcion != 0 && opcion != 1 && opcion != 2 && opcion != 3);

    return opcion;
}
