#include <stdio.h>
#include <stdlib.h>
#include "menuN.h"

//Menu principal de Naves.
//Pide que se seleccione una opcion.
//Alta - Baja - Modificacion - Consulta - Listado.
//Opcion para volver al menu principal.
void menuNaves()
{
    int opcion, ID, flag = 0;

    system("cls");

    do
    {
        printf("\nQue accion desea realizar:\n\n");
        printf("\t1 - Alta\n");
        printf("\t2 - Baja\n");
        printf("\t3 - Modificacion\n");
        printf("\t4 - Consulta (por ID)\n");
        printf("\t5 - Ver listado\n");
        printf("\t0 - Volver al menu principal / Salir\n");

        scanf("%d", &opcion);


        switch(opcion)
        {
        case 1:

            menuAltaNaves();
            break;

        case 2:

            menuBajaNaves();
            break;

        case 3:

            menuModificacionNaves();
            break;

        case 4:

            system("cls");
            ID = ingresarIDnave();
            flag = buscarIDnave(ID);
            if(flag == 1)
            {
               imprimirNaveSeleccionada(ID);
            }else
            {
                printf("\nEl ID que ingreso no existe!!\n\n");
            }

            break;

        case 5:

            printf("\nListado de Naves\n\n");
            mostrarNaves();
            break;

        case 0:

            break;

        default:

            system("cls");
            printf("\nUsted ingreso una opcion no valida\n\n");
            break;

        }

    }
    while(opcion != 0 && opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5);
}
// Menu para modificar todos los datos de la nave, por separado o todos los atributos.
void menuModificacionNaves()
{
    int opcion, ID, flag;

    system("cls");
    do
    {
        printf("\nElija que quiere modificar\n\n");
        printf("\t1 - ID\n");
        printf("\t2 - Tipo de nave\n");
        printf("\t3 - Cantidad de vuelos realizados\n");
        printf("\t4 - Horas de vuelo acumuladas\n");
        printf("\t5 - Estado\n");
        printf("\t6 - Todos los atributos\n");

        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            system("cls");
            ID = ingresarIDnave();
            flag = buscarIDnave(ID);
            if(flag == 1)
            {
                modificarIdNave(ID);
            }
            else
            {
                printf("\nEl ID que ingreso no existe!!\n\n");
            }
            break;

        case 2:

            system("cls");
            ID = ingresarIDnave();
            flag = buscarIDnave(ID);
            if(flag == 1)
            {
               modificarTipoNave(ID);
            }else
            {
                printf("\nEl ID que ingreso no existe!!\n\n");
            }
            break;

        case 3:

            system("cls");
            ID = ingresarIDnave();
            flag = buscarIDnave(ID);
            if(flag == 1)
            {
               modificarCntVuelos(ID);
            }else
            {
                printf("\nEl ID que ingreso no existe!!\n\n");
            }
            break;

        case 4:

            system("cls");
            ID = ingresarIDnave();
            flag = buscarIDnave(ID);
            if(flag == 1)
            {
               modificarHoras(ID);
            }else
            {
                printf("\nEl ID que ingreso no existe!!\n\n");
            }
            break;

        case 5:

            system("cls");
            ID = ingresarIDnave();
            flag = buscarIDnave(ID);
            if(flag == 1)
            {
               modificarEstado(ID);
            }else
            {
                printf("\nEl ID que ingreso no existe!!\n\n");
            }
            break;

        case 6:

            system("cls");
            ID = ingresarIDnave();
            flag = buscarIDnave(ID);
            if(flag == 1)
            {
                modificarTodoNave(ID);
            }
            else
            {
                printf("\nEl ID que ingreso no existe!!\n\n");
            }
            break;

        default:

            system("cls");
            printf("\nUsted ingreso una opcion no valida\n\n");
            break;
        }

    }while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 6);
}
//Menu para dar de Alta una Nave.
//Pide seleccionar una opcion: alta de una nave existente o agregar una.
//Permite ver un ID antes de ingresarlo.
void menuAltaNaves()
{
    int opcion, ID, control;

    system("cls");
    do
    {
        printf("\nIngrese '1' para dar de alta una nave existente");
        printf("\nIngrese '2' para agregar una nave");
        printf("\nIngrese '3' si quiere ver el listado de Naves\n");
        printf("Ingrese '0' para volver al menu principal\n\n");
        printf("\t1 - Dar de baja una nave\n");
        printf("\t2 - Agregar una nave\n");
        printf("\t3 - Ver listado (Tipo de nave, estado e ID)\n");
        printf("\t0 - Salir / volver al menu principal\n\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            system("cls");
            ID = ingresarIDnave();
            control = buscarIDnave(ID);
            if(control == 1)
            {
                darAltaNave(ID);
            }else
            {
                printf("\nIngreso un ID no valido\n\n");
            }
            break;

        case 2:

            agregarNaveAlta();
            break;

        case 3:

            system("cls");
            mostrarListaAltaBaja();
            printf("\n\nPresione ''Enter'' para volver al menu anterior\n\n");
            getch();system("cls");
            break;

        case 0:

            break;

        default:

            system("cls");
            printf("\nUsted ingreso una opcion no valida\n\n");
            break;
        }

    }while(opcion != 1 && opcion != 2 && opcion == 3 && opcion != 0);
}
//Menu para dar de baja  una Nave.
//Pide seleccionar una opcion: baja de una nave.
//Permite ver un ID antes de ingresarlo.
void menuBajaNaves()
{
    int opcion, ID, control;

    system("cls");
    do
    {
        printf("\nIngrese '1' si conoce el ID\n");
        printf("Ingrese '2' si quiere ver el listado de Naves\n");
        printf("Ingrese '0' para volver al menu principal\n\n");
        printf("\t1 - Dar baja\n");
        printf("\t2 - Ver listado (Tipo de nave, estado e ID)\n");
        printf("\t0 - Salir / volver al menu principal\n\n");

        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            system("cls");
            ID = ingresarIDnave();
            control = buscarIDnave(ID);
            if(control == 1)
            {
                darBajaNave(ID);
            }else
            {
                printf("\nIngreso un ID no valido\n\n");
            }
            break;

        case 2:

            system("cls");
            mostrarListaAltaBaja();
            printf("\n\nPresione ''Enter'' para volver al menu anterior\n\n");
            getch();system("cls");
            break;

        case 0:

            break;

        default:

            system("cls");
            printf("\nUsted ingreso una opcion no valida\n\n");
            break;
        }

    }while(opcion != 1 && opcion == 2 && opcion != 0);
}
