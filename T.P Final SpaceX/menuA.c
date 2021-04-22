#include <stdio.h>
#include <stdlib.h>
#include "Astronautas.h"
#include "menuA.h"

//Menu principal de Astronautas.
//Pide que se seleccione una opcion.
//Alta - Baja - Modificacion - Consulta - Listado.
//Opcion para volver al menu principal.
void menuAstronautas()
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

            menuAltaAstronautas();
            break;

        case 2:

            menuBajaAstronautas();
            break;

        case 3:

            menuModificacionAstronautas();
            break;

        case 4:

            system("cls");
            ID = ingresarID();
            flag = buscarIDatronauta(ID);
            if(flag == 1)
            {
               imprimirAstronautaSeleccionado(ID);
            }else
            {
                printf("\nEl ID que ingreso no existe!!\n\n");
            }

            break;

        case 5:

            printf("\nListado de astronautas\n\n");
            mostrarAstronautas();
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
// Menu para modificar todos los datos de Astronautas, por separado o todos los atributos.
void menuModificacionAstronautas()
{
    int opcion, ID, flag;

    system("cls");
    do
    {
        printf("\nElija que quiere modificar\n\n");
        printf("\t1 - ID\n");
        printf("\t2 - Nombre\n");
        printf("\t3 - Apellido\n");
        printf("\t4 - Apodo\n");
        printf("\t5 - Edad\n");
        printf("\t6 - Nacionalidad\n");
        printf("\t7 - Especialidad\n");
        printf("\t8 - Horas de vuelo acumuladas\n");
        printf("\t9 - Misiones espaciales realizadas\n");
        printf("\t10 - Horas acumuladas en la E.E.I\n");
        printf("\t11 - Todos los atributos\n");

        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            system("cls");
            ID = ingresarID();
            flag = buscarIDatronauta(ID);
            if(flag == 1)
            {
                modificarIdAstro(ID);
            }
            else
            {
                printf("\nEl ID que ingreso no existe!!\n\n");
            }
            break;

        case 2:

            system("cls");
            ID = ingresarID();
            flag = buscarIDatronauta(ID);
            if(flag == 1)
            {
               modificarNombreAstro(ID);
            }else
            {
                printf("\nEl ID que ingreso no existe!!\n\n");
            }
            break;

        case 3:

            system("cls");
            ID = ingresarID();
            flag = buscarIDatronauta(ID);
            if(flag == 1)
            {
               modificarApellidoAstro(ID);
            }else
            {
                printf("\nEl ID que ingreso no existe!!\n\n");
            }
            break;

        case 4:

            system("cls");
            ID = ingresarID();
            flag = buscarIDatronauta(ID);
            if(flag == 1)
            {
               modificarApodoAstro(ID);
            }else
            {
                printf("\nEl ID que ingreso no existe!!\n\n");
            }
            break;

        case 5:

            system("cls");
            ID = ingresarID();
            flag = buscarIDatronauta(ID);
            if(flag == 1)
            {
               modificarEdadAstro(ID);
            }else
            {
                printf("\nEl ID que ingreso no existe!!\n\n");
            }
            break;

        case 6:

            system("cls");
            ID = ingresarID();
            flag = buscarIDatronauta(ID);
            if(flag == 1)
            {
                modificarNacionalidadAstro(ID);
            }
            else
            {
                printf("\nEl ID que ingreso no existe!!\n\n");
            }
            break;

        case 7:

            system("cls");
            ID = ingresarID();
            flag = buscarIDatronauta(ID);
            if(flag == 1)
            {
                modificarEspecialidadAstro(ID);
            }
            else
            {
                printf("\nEl ID que ingreso no existe!!\n\n");
            }
            break;

        case 8:

            system("cls");
            ID = ingresarID();
            flag = buscarIDatronauta(ID);
            if(flag == 1)
            {
                modificarHorasVueloAstro(ID);
            }
            else
            {
                printf("\nEl ID que ingreso no existe!!\n\n");
            }
            break;

        case 9:

            system("cls");
            ID = ingresarID();
            flag = buscarIDatronauta(ID);
            if(flag == 1)
            {
                modificarMisionesAstro(ID);
            }
            else
            {
                printf("\nEl ID que ingreso no existe!!\n\n");
            }
            break;

        case 10:
            system("cls");
            ID = ingresarID();
            flag = buscarIDatronauta(ID);
            if(flag == 1)
            {
                modificarHorasEeiAstro(ID);
            }
            else
            {
                printf("\nEl ID que ingreso no existe!!\n\n");
            }
            break;

        case 11:

            system("cls");
            ID = ingresarID();
            flag = buscarIDatronauta(ID);
            if(flag == 1)
            {
                modificarTodoAstro(ID);
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

    }while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 6 && opcion != 7 && opcion != 8 && opcion != 9 && opcion != 10 && opcion != 11);
}
//Menu para dar de Alta un astronauta.
//Pide seleccionar una opcion: alta de un astronauta retirado o agregar uno.
//Permite ver un ID antes de ingresarlo.
void menuAltaAstronautas()
{
    int opcion, ID, control;

    system("cls");
    do
    {
        printf("\nIngrese '1' para dar la alta a un astronauta retirado");
        printf("\nIngrese '2' para agregar un astronauta");
        printf("\nIngrese '3' si quiere ver el listado de astronautas");
        printf("\nIngrese '0' para volver al menu principal\n\n");
        printf("\t1 - Alta a astronauta retirado\n");
        printf("\t2 - Agregar astronauta (Automaticamente activo)\n");
        printf("\t3 - Ver listado (Nombre-Apellido, estado e ID)\n");
        printf("\t0 - Salir / volver al menu principal\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            ID = ingresarID();
            control = buscarIDatronauta(ID);
            if(control == 1)
            {
                system("cls");
                darAltaAstronauta(ID);
            }else
            {
                printf("\nIngreso un ID no valido\n\n");
            }
            break;

        case 2:

            agregarAstroAlta();
            break;

        case 3:

            system("cls");
            mostrarListaAltaBajaAstro();
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
//Menu para dar de baja  un astronauta.
//Pide seleccionar una opcion: baja de un astronauta activo.
//Permite ver un ID antes de ingresarlo.
void menuBajaAstronautas()
{
    int opcion, ID, control;

    system("cls");
    do
    {
        printf("\nIngrese '1' para dar de baja un astronauta activo\n");
        printf("Ingrese '2' para ver el listado de astronautas\n");
        printf("Ingrese '0' para volver al menu principal\n\n");
        printf("\t1 - Dar baja a astronauta activo\n");
        printf("\t2 - Ver listado (Nombre-Apellido, estado e ID)\n");
        printf("\t0 - Salir / volver al menu principal\n\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            ID = ingresarID();
            control = buscarIDatronauta(ID);
            if(control == 1)
            {
                system("cls");
                darBajaAstronauta(ID);
            }else
            {
                printf("\nIngreso un ID no valido\n\n");
            }
            break;

        case 2:

            system("cls");
            mostrarListaAltaBajaAstro();
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
