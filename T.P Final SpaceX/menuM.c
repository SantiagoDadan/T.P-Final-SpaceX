#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Misiones.h"
#include "menuM.h"


//Menu principal de Misiones.
//Pide que se seleccione una opcion.
//Alta - Baja - Modificacion - Consulta - Listado.
//Opcion para volver al menu principal.
void MenuMisiones()
{
    int opcion, idBuscar, flag;

    system("cls");

    do
    {
        printf("\nQue accion desea realizar:\n\n");
        printf("\t1 - Alta\n");
        printf("\t2 - Baja\n");
        printf("\t3 - Modificacion\n");
        printf("\t4 - Consulta (por ID)\n");
        printf("\t5 - Ver listado\n");
        printf("\t0 - Volver al menu principal\n");

        scanf("%d", &opcion);


        switch(opcion)
        {
        case 1:
            system("cls");
            menuAltaMisiones();
            break;

        case 2:
            system("cls");
            menuBajaMisiones();// no me funciona , controlar!
            break;
        case 3:
            system("cls");
            menuModificacionesMisiones();
            break;

        case 4:
            system("cls");
            idBuscar = ingresarIDmision();
            flag = buscarIDmision(idBuscar);
            if(flag == 1)
            {
               consultaIDmision(idBuscar);
            }else
            {
                printf("\nEl ID ingresado no existe!!\n\n");
            }

            break;

        case 5:
            system("cls");
            mostrarMisiones();
            break;

        case 0:
            break;

        default:

            system("cls");
            printf("\nUsted ingreso una opcion no valida\n\n");
            break;

        }

    }  while(opcion != 0 && opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5);
}
//Menu para dar de Alta una Mision.
//Pide seleccionar una opcion: alta de una mision existente o agregar una.
//Permite ver un ID antes de ingresarlo.
void menuAltaMisiones()
{
    int opcion;
    int idBuscar;
    int flag;

    do
    {
        printf("\nIngrese '1' para dar de alta una mision cancelada\n");
        printf("Ingrese '2' para ingresar una nueva mision al sistema\n");
        printf("Ingrese '3' si desea ver el listado de misiones disponibles\n");
        printf("Ingrese '0' para volver al menu principal\n\n");
        printf("\t1 - Alta a mision cancelada\n");
        printf("\t2 - Agregar mision\n");
        printf("\t3 - Ver listado (ID, Destino, Cargamento)\n");
        printf("\t0 - Salir / volver al menu principal\n");
        scanf("%i", &opcion);

        switch (opcion)
        {
        case 1:

            idBuscar = ingresarIDmision();
            flag = buscarIDmision(idBuscar);
            if (flag == 1)
            {
                realizarAltaMision(idBuscar);
            }else
            {
                printf("\nEl ID ingresado no existe!!\n\n");
            }
            break;

        case 2:

            agregarMision();
            break;

        case 3:

            system("cls");
            mostrarListadosIDmision();
            printf("\nPresione ''enter'' para volver al menu anterior\n\n");
            getch();
            system("cls");
            break;

        case 0:

            break;

        default:
            printf("Opcion incorrecta, intente con otra.");
        }

    }
    while (opcion !=1 && opcion !=2 && opcion == 3 && opcion !=0);

}
//Menu para dar de baja  una Mision.
//Pide seleccionar una opcion.
//Permite ver un ID antes de ingresarlo.
void menuBajaMisiones()
{
    int opcion;
    int idBuscar, flag;

    do
    {
        printf("\nIngrese '1' si conoce el ID de la mision a dar de baja\n");
        printf("Ingrese '2' si desea ver el listado de misiones disponibles\n");
        printf("Ingrese '0' para volver al menu principal\n\n");
        printf("\t1 - Baja de mision\n");
        printf("\t2 - Ver el listado\n");
        printf("\t0 - Salir / volver al menu principal\n");
        scanf("%i", &opcion);

        switch (opcion)
        {
        case 1:
            idBuscar=ingresarIDmision();
            flag=buscarIDmision(idBuscar);
            if (flag == 1)
            {
                realizarBajaMision(idBuscar);
            }else
            {
                printf("\nEl ID ingresado no existe!!\n\n");
            }
            break;

        case 2:
            system("cls");
            mostrarListadosIDmision();
            printf("\nPresione ''enter'' para volver al menu anterior\n\n");
            getch();
            system("cls");
            break;

        case 0:
            break;

        default:
            printf("Opcion incorrecta, intente con otra.");
        }

    }
    while (opcion !=1 && opcion ==2 && opcion !=0);

}
// Menu principal para modificar.
void menuModificacionesMisiones()
{
    int opcion;
    int idBuscar, flag;
    system("cls");

    do
    {

        printf("\nIngrese '1' si conoce el ID de la mision a modificar\n");
        printf("Ingrese '2' si desea ver el listado de misiones disponibles\n");
        printf("Ingrese '3' para volver al menu principal\n\n");
        printf("\t1 - Ingresar ID\n");
        printf("\t2 - Ver el listado\n");
        printf("\t0 - Salir / volver al menu principal\n");
        scanf("%i", &opcion);

        switch (opcion)
        {
        case 1:

            system("cls");
            idBuscar=ingresarIDmision();
            flag=buscarIDmision(idBuscar);
            if (flag == 1)
            {
              menuOpModificaciones(idBuscar);
            }else
            {
                printf("\nEl ID ingresado no existe!!\n\n");
            }

            break;

        case 2:

            system("cls");
            mostrarListadosIDmision();
            printf("\nPresione ''enter'' para volver al menu anterior\n\n");
            getch();
            system("cls");
            break;

        case 3:
            break;

        default:

            system("cls");
            printf("\nUsted ingreso una opcion no valida\n\n");
            break;
        }
    }while (opcion !=1 && opcion !=3);


}
// Menu para modificar todos los datos de la mision, por separado o todos los atributos.
void menuOpModificaciones(int idBuscar)
{
    int opcion;

    do
    {
        system("cls");
        printf("\nModificar:\n\n");
        printf("\t1 - ID de la mision.\n");
        printf("\t2 - ID de la nave.\n");
        printf("\t3 - Estado.\n");
        printf("\t4 - Destino.\n");
        printf("\t5 - Cargamento.\n");
        printf("\t6 - Tripulantes.\n");
        printf("\t7 - Detalles de la mision.\n");
        printf("\t8 - Todos los atributos.\n");
        scanf("%i", &opcion);

        switch (opcion)
        {

        case 1:

            modificarIDMision(idBuscar);
            break;

        case 2:

            modificarNaveMision(idBuscar);
            break;

        case 3:

            modificarEstadoMision(idBuscar);
            break;

        case 4:

            modificarDestino(idBuscar);
            break;

        case 5:

            modificarCargamento(idBuscar);
            break;

        case 6:

            modificarTripulantes(idBuscar);
            break;

        case 7:

            modificarDetallesMision(idBuscar);
            break;

        case 8:

            modificarTodoMision(idBuscar);
            break;

        default:

            printf("Opcion incorrecta, intente con otra.");
            break;
        }

    }while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 6 && opcion != 7 && opcion != 8);

}
