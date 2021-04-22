#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Naves.h"

const char nombreNave[] = "Naves.dat";

//Funcion que permite ingresar los datos de una nave y los retorna.
Naves cargarNave()
{
    Naves lista;
    int opcion, flag;

    printf("\nCargue los datos de la nave:\n\n");

    do
    {
       lista.ID = ingresarIDnave();

       flag = buscarIDnave(lista.ID);

       if(flag == 1)
       {
           printf("\nEl ID ingresado ya existe, intente con uno diferente\n\n");
       }

    }while(flag != 0);

    do
    {
        printf("\nSeleccione el tipo de nave:\n\n");
        printf("\t1 - Starship\n");
        printf("\t2 - Falcon 9\n");
        printf("\t3 - Falcon Heavy\n\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            strcpy(lista.tipoNave, "Starship");
            break;

        case 2:
            strcpy(lista.tipoNave, "Falcon 9");
            break;

        case 3:
            strcpy(lista.tipoNave, "Falcon Heavy");
            break;

        default:
            printf("\nIngreso una opcion no valida\n\n");
            break;
        }

    }while(opcion != 1 && opcion != 2 && opcion != 3);

    printf("\nCantidad de vuelos realizados:\n\n");
    scanf("%d", &lista.cntVuelos);

    printf("\nHoras de vuelo acumuladas\n\n");
    scanf("%d", &lista.horasAcumuladas);

    do
    {
        printf("Estado (1-Mantenimiento/2-Lista para su uso/3-En mision/4-De baja)\n\n");
        scanf("%d", &lista.estado);

        if(lista.estado != 1 && lista.estado != 2 && lista.estado != 3 && lista.estado != 4)
        {
            printf("\nIngreso una opcion no valida, intentelo nuevamente\n\n");
            flag = 1;
        }else
        {
            flag = 0;
        }

    }while(flag != 0);

    return lista;
}
//Funcion hardcodeada para el uso del programador.
//Si no hay datos en el archivo, inicializa los valores. Si hay datos los ingresa al final del mismo.
//Se carga en el archivo 'Naves' los datos ingresados.
// Le da la opcion al usuario de ingresar tantos datos como desee.
void cargarArchivoNaves()
{
    Naves lista;

    char control = 's';

    FILE* archi = fopen(nombreNave, "ab");

    if(archi != NULL)
    {
        while(control == 's' || control == 'S')
        {
           lista = cargarNave();

           fwrite(&lista, sizeof(Naves), 1, archi);

           printf("\nIngrese 's' para continuar o 'n' para salir\n\n");
           fflush(stdin);
           scanf("%c", &control);
        }
        fclose(archi);
    }
}
// Funcion para la modularizacion de los datos de la nave.
//Se usa por parametro el retorno de la funcion cargaNave.
void imprimirNave(Naves lista)
{
    printf("\n----------------------------------");
    printf("\nID: %d\n", lista.ID);
    printf("Nave: %s\n", lista.tipoNave);
    printf("Vuelos realizados: %d\n", lista.cntVuelos);
    printf("Horas de vuelo acumuladas: %d\n", lista.horasAcumuladas);

    if(lista.estado == 1)
    {
        printf("Estado: En mantenimiento\n");
    }else if(lista.estado == 2)
    {
        printf("Estado: Lista para su uso\n");
    }else if(lista.estado == 3)
    {
        printf("Estado: Actualmente en mision\n");
    }else
    {
        printf("Estado: De baja\n");
    }

    printf("\n----------------------------------\n");
}
//Funcion para mostrar por pantalla todos los datos cargados.
void mostrarNaves()
{
    FILE* archi = fopen(nombreNave, "rb");

    Naves lista;

    if(archi != NULL)
    {
        while(fread(&lista, sizeof(Naves), 1, archi) > 0)
        {
            imprimirNave(lista);

        }
        fclose(archi);
    }
}
//Pide un ID por teclado.
//Verifica que el numero ingresado no sea menor a 1.
// Si es menor, debe volver a ingresar el ID.
int ingresarIDnave()
{
    int ID;
    do
    {
        printf("\nIngrese un ID:   ");
        scanf("%d", &ID);
        if(ID < 1)
        {
            printf("\nIngreso un ID no valido\n\n");
        }
    }
    while(ID < 1);

    return ID;
}
// Verifica si el ID ingresado ya existe en el archivo Naves.
//El ID es pasado por parametro.
//Si el ID se encuentra en el archivo retorna 1.
int buscarIDnave(int ID)
{
    int flag = 0;

    FILE* archi = fopen(nombreNave, "rb");

    Naves aux;

    if(archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Naves), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                flag = 1;
            }
        }
        fclose(archi);
    }

    return flag;
}
//Funcion para mostrar por pantalla a la nave que tiene asignado el ID.
//El ID se recibe por parametro.
//Si el ID se encuentra en el archivo, lo imprime.
void imprimirNaveSeleccionada(int ID)
{
    int flag = 0;

    FILE* archi = fopen(nombreNave, "rb");
    Naves aux;
    if (archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Naves), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                fseek(archi, sizeof(Naves)*-1, SEEK_CUR);
                imprimirNave(aux);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Se encarga de generar el ALTA de una nave en el sistema.
//Recibe el ID por parametro.
// Si la nave se encuentra en mantenimiento o de baja, cambia su estado a lista para su uso.
// Si la nave se encuentra lista , lo informa por pantalla.
//Si se agrega muestra mensaje de exito.
void darAltaNave(int ID)
{
    int flag = 0;

    FILE* archi = fopen(nombreNave, "r+b");
    Naves aux;

    if (archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Naves), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                if(aux.estado == 1 || aux.estado == 4)
                {
                    aux.estado = 2;
                    fseek(archi, sizeof(Naves)*-1, SEEK_CUR);
                    fwrite(&aux, sizeof(Naves), 1, archi);
                    printf("\nEstado cambiado correctamente!!\n\n");
                    imprimirNave(aux);

                }else if(aux.estado == 2)
                {
                    printf("\nEsta nave ya se encuentra lista para su uso\n\n");

                }else
                {
                    printf("\nEsta nave se encuentra actualmente en mision\n\n");
                }
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Se encarga de generar el ALTA de una nave en el sistema.
//Recibe el ID por parametro.
//Permite al usuario cargar todos los datos de una nave que no se encuentra en el sistema.
//Si el ID ya se encuentra ingresado, pide que intente con otro.
//Si se agrega muestra mensaje de exito.
void agregarNaveAlta()
{
    Naves lista;

    FILE* archi = fopen(nombreNave, "ab");

    if(archi != NULL)
    {
        lista = cargarNave();

        fwrite(&lista, sizeof(Naves), 1, archi);
        system("cls");
        printf("\nNave agregada correctamente!!\n\n");
        imprimirNave(lista);
    }
    fclose(archi);
}
// Funcion da de baja una Nave que se encuentre en estado mantenimiento o lista.
//Recibe id por parametro.
void darBajaNave(int ID)
{
    int flag = 0;

    FILE* archi = fopen(nombreNave, "r+b");
    Naves aux;

    if (archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Naves), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                if(aux.estado == 1 || aux.estado == 2)
                {
                    aux.estado = 4;
                    fseek(archi, sizeof(Naves)*-1, SEEK_CUR);
                    fwrite(&aux, sizeof(Naves), 1, archi);
                    printf("\nEstado cambiado correctamente!!\n\n");
                    imprimirNave(aux);

                }else if(aux.estado == 4)
                {
                    printf("\nEsta nave ya se encuentra de baja\n\n");

                }else
                {
                    printf("\nEsta nave se encuentra actualmente en mision\n\n");
                }
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para modularizar la lista de alta y baja de una nave.
//Recibe por parametro los datos del astronauta.
void listaAltaBaja(Naves lista)
{
    printf("\n-----------------------------\n");
    printf("Nave:  %s\n", lista.tipoNave);
    if(lista.estado == 1)
    {
        printf("Estado: En mantenimiento\n");
    }else if(lista.estado == 2)
    {
        printf("Estado: Lista para su uso\n");
    }else if(lista.estado == 3)
    {
        printf("Estado: Actualmente en mision\n");
    }else
    {
        printf("Estado: De baja\n");
    }
    printf("ID:  %d", lista.ID);
    printf("\n-----------------------------\n");
}
//Muestra por pantalla la lista alta o baja de naves.
void mostrarListaAltaBaja()
{
    FILE* archi = fopen(nombreNave, "rb");

    Naves lista;

    if(archi != NULL)
    {
        while(fread(&lista, sizeof(Naves), 1, archi) > 0)
        {
            listaAltaBaja(lista);

        }
        fclose(archi);
    }
}
//Funcion para modificar el ID.
//Recibe por parametro el ID ingresado.
//Si se modifica, imprimi un mensaje de exito.
void modificarIdNave(int ID)
{
    int flag = 0, control = 0, nuevo;

    Naves aux;

    FILE* archi = fopen(nombreNave, "r+b");

    if(archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Naves), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                do
                {
                    printf("\nIngrese un nuevo ID\n\n");
                    scanf("%d", &nuevo);

                    control = buscarIDnave(nuevo);

                    if(control == 1)
                    {
                        printf("\nEl ID ingresado ya existe, intente con uno diferente\n\n");
                    }
                }while(control != 0);

                aux.ID = nuevo;
                fseek(archi, sizeof(Naves)*-1, SEEK_CUR);
                fwrite(&aux, sizeof(Naves), 1, archi);
                system("cls");
                printf("\nID cambiado correctamente!!\n\n");
                imprimirNave(aux);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para modificar el tipo de la nave.
//Recibe por parametro el ID ingresado.
//Si se modifica, imprimi un mensaje de exito.
void modificarTipoNave(int ID)
{
    int flag = 0, opcion;
    Naves aux;

    FILE* archi = fopen(nombreNave, "r+b");

    if(archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Naves), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                printf("\nSelecciones un nuevo tipo de nave:\n\n");
                do
                {
                    printf("\n\t1 - Starship\n");
                    printf("\t2 - Falcon 9\n");
                    printf("\t3 - Falcon Heavy\n\n");
                    scanf("%d", &opcion);

                    switch(opcion)
                    {
                    case 1:
                        strcpy(aux.tipoNave, "Starship");
                        break;

                    case 2:
                        strcpy(aux.tipoNave, "Falcon 9");
                        break;

                    case 3:
                        strcpy(aux.tipoNave, "Falcon Heavy");
                        break;

                    default:
                        printf("\nIngreso una opcion no valida\n\n");
                        break;
                    }
                }while(opcion != 1 && opcion != 2 && opcion != 3);

                fseek(archi, sizeof(Naves)*-1, SEEK_CUR);
                fwrite(&aux, sizeof(Naves), 1, archi);
                system("cls");
                printf("\nTipo de nave cambiado correctamente!!\n\n");
                imprimirNave(aux);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para modificar la cantidad de vuelos de la nave.
//Recibe por parametro el ID ingresado.
//Verifica si la cantidad de vuelos no sea negativa.
//Si se modifica, imprimi un mensaje de exito.
void modificarCntVuelos(int ID)
{
    int flag = 0, nuevo;
    Naves aux;

    FILE* archi = fopen(nombreNave, "r+b");

    if(archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Naves), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                do
                {
                    printf("\nIngrese una nueva cantidad de vuelos realizados\n\n");
                    scanf("%d", &nuevo);
                    if(nuevo < 0)
                    {
                        printf("\nIngreso una cantidad negativa\n\n");
                    }
                }while(nuevo < 0);
                aux.cntVuelos = nuevo;
                fseek(archi, sizeof(Naves)*-1, SEEK_CUR);
                fwrite(&aux, sizeof(Naves), 1, archi);
                system("cls");
                printf("\nCantidad de misiones cambiadas correctamente!!\n\n");
                imprimirNave(aux);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para modificar las horas de vuelo de la nave.
//Recibe por parametro el ID ingresado.
//Verifica si la cantidad de vuelos no sea negativa.
//Si se modifica, imprimi un mensaje de exito.
void modificarHoras(int ID)
{
    int flag = 0, nuevo;
    Naves aux;

    FILE* archi = fopen(nombreNave, "r+b");

    if(archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Naves), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                do
                {
                    printf("\nIngrese una nueva cantidad de horas de vuelo acumuladas\n\n");
                    scanf("%d", &nuevo);
                    if(nuevo < 0)
                    {
                        printf("\nIngreso una cantidad negativa\n\n");
                    }
                }while(nuevo < 0);
                aux.horasAcumuladas = nuevo;
                fseek(archi, sizeof(Naves)*-1, SEEK_CUR);
                fwrite(&aux, sizeof(Naves), 1, archi);
                system("cls");
                printf("\nCantidad de horas cambiadas correctamente!!\n\n");
                imprimirNave(aux);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para modificar el estado de la nave.
//Recibe por parametro el ID ingresado.
//Si se modifica, imprimi un mensaje de exito.
void modificarEstado(int ID)
{
    int flag = 0, nuevo;
    Naves aux;

    FILE* archi = fopen(nombreNave, "r+b");

    if(archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Naves), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                do
                {
                    printf("\nEscoja un nuevo Estado (1-Mantenimiento/2-Lista para su uso/3-En mision/4-De baja)\n\n");
                    scanf("%d", &aux.estado);

                    if(aux.estado != 1 && aux.estado != 2 && aux.estado != 3 && aux.estado != 4)
                    {
                        printf("\nIngreso una opcion no valida, intentelo nuevamente\n\n");
                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                    }
                }while(aux.estado != 1 && aux.estado != 2 && aux.estado != 3 && aux.estado != 4);
                fseek(archi, sizeof(Naves)*-1, SEEK_CUR);
                fwrite(&aux, sizeof(Naves), 1, archi);
                system("cls");
                printf("\nEstado cambiado correctamente!!\n\n");
                imprimirNave(aux);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para modificar todos los atributos de la nave.
//Recibe por parametro el ID ingresado.
//Si se modifica, imprimi un mensaje de exito.
void modificarTodoNave(int ID)
{
    int flag = 0;
    Naves aux;

    FILE* archi = fopen(nombreNave, "r+b");

    if(archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Naves), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                printf("\nNuevos datos\n\n");
                aux = cargarNave();
                fseek(archi, sizeof(Naves)*-1, SEEK_CUR);
                fwrite(&aux, sizeof(Naves), 1, archi);
                system("cls");
                printf("\nDatos modificados correctamente!!\n\n");
                imprimirNave(aux);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
