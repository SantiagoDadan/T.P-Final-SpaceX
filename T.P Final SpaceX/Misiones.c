#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include <string.h>
#include "Misiones.h"
#include "Astronautas.h"
#include "Naves.h"

const char nombreMision[] = "Misiones.dat";
//Funcion que permite ingresar los datos de una mision y los retorna.
Misiones cargarMision()
{

    Misiones lista;
    int flag=0;

    printf("ID de la mision: \n\n");
    scanf("%i", &lista.ID);

    printf("ID nave: \n\n");
    scanf("%i", &lista.IDnave);

   do
    {
        printf("Seleccione estado de la mision\n");
        printf("\t1 - Lista \n");
        printf("\t2 - En vuelo \n");
        printf("\t3 - Retornada \n");
        printf("\t4 - Cancelada \n");
        printf("\t5 - Fallida \n\n");
        scanf("%i", &lista.estado);

        if(lista.estado !=1 && lista.estado !=2 && lista.estado !=3 && lista.estado !=4 && lista.estado !=5)
        {
            printf("\nOpcion incorrecta\n\n");
            flag = 1;

        } else
        {
            flag = 0;
        }

    } while (flag != 0);

    printf("Destino: \n\n");
    fflush(stdin);
    gets(&lista.destino);

    printf("Cargamento: \n\n");
    fflush(stdin);
    gets(&lista.cargamento);

    printf("Ingrese cantidad de tripulantes en la mision:\n\n");
    scanf("%i", &lista.cntTripulantes);
    while (lista.cntTripulantes >= 8 || lista.cntTripulantes <= 0)
    {
        printf("\nExcede el limite o es negativo, ingresar nuevamente  cantidad tripulantes:\n\n");
        scanf("%i", &lista.cntTripulantes);
    }

    for (int s=0; s<lista.cntTripulantes ; s++)
    {
        for(int j=0; j<1; j++)
        {
            printf("\nID tripulante %i:\n", s+1);
            scanf("%i", &lista.tripulante[s][j]);
        }
    }

    printf("\Detalles de la mision:\n\n");
    fflush(stdin);
    gets(&lista.detalles);

    return lista;
}
//Funcion hardcodeada para el uso del programador.
//Si no hay datos en el archivo, inicializa los valores. Si hay datos los ingresa al final del mismo.
//Se carga en el archivo 'Misones.dat' los datos ingresados.
// Le da la opcion al usuario de ingresar tantos datos como desee.
void cargarArchivoMisiones()
{
    Misiones lista;

    char control = 's';

    FILE * archi = fopen(nombreMision, "ab");

    if(archi != NULL)
    {
        while (control =='s' || control =='S')
        {
            lista = cargarMision();

            fwrite (&lista, sizeof(Misiones),1,archi);

            printf("Ingrese 's' para continuar o 'n' para salir");
            fflush(stdin);
            scanf("%c", &control);

        }
    fclose(archi);

    }

}
// Funcion para la modularizacion de los datos de la mision.
//Se usa por parametro el retorno de la funcion cargarMision.
void imprimirMision (Misiones lista)
{
    printf("\n----------------------------------");
    printf("\nMISION: %i \n", lista.ID);
    printf("ID Nave: %i \n", lista.IDnave);
    if (lista.estado == 1)
    {
        printf("Estado: Listo\n");
    }else if(lista.estado == 2)
    {
        printf("Estado: En vuelo\n");
    }else if (lista.estado == 3)
    {
        printf("Estado: Retornada\n");

    }else if(lista.estado == 4)
    {
        printf("Estado: Cancelada\n");
    }else
    {
       printf("Estado: Fallida\n");
    }

    printf("Destino: %s \n", lista.destino);
    printf("Cargamento: %s \n", lista.cargamento);
    for(int s = 0; s < lista.cntTripulantes; s++)
    {
        for(int j=0; j<1;j++)
        {
           printf("Tripulante %i : %i \n",s+1, lista.tripulante[s][j]);
        }
    }
    printf("Detalles: %s \n", lista.detalles);
    printf("\n----------------------------------\n");
}
//Funcion para mostrar por pantalla todos los datos cargados.
void mostrarMisiones()
{
    FILE* archi = fopen (nombreMision, "rb");

    Misiones lista;

    if(archi != NULL)
    {
        while(fread(&lista, sizeof(Misiones), 1, archi) > 0)
        {
            imprimirMision(lista);
        }

    fclose(archi);
    }

}
//Pide un ID por teclado.
//Verifica que el numero ingresado no sea menor a 1.
// Si es menor, debe volver a ingresar el ID.
int ingresarIDmision()
{
    int idBuscar;
    int flag = 0;

    do{
        printf("\nIngrese el ID de la mision: ");
        scanf("%i",&idBuscar);

        if(idBuscar <0)
            {
            printf("\nEl ID no es valido.");
        } else {
            flag = 1;
        }
    } while(flag == 0);

    return idBuscar;
}
// Verifica si el ID ingresado ya existe en el archivo Misiones.dat.
//El ID es pasado por parametro.
//Si el ID se encuentra en el archivo retorna 1.
int buscarIDmision (int idBuscar)
{
    int flag=0;

    FILE* archi = fopen (nombreMision, "rb");

    Misiones aux;

    if( archi != NULL)
    {
        while (!flag && fread(&aux, sizeof (Misiones), 1, archi) > 0)
        {
            if (aux.ID == idBuscar)
            {
                flag= 1;
            }
        }

        fclose(archi);
    }

    return flag;
}
//Muestra el listado de todas las misiones cargadas en el archivo.
void mostrarListadosIDmision()
{
    Misiones aux;

    FILE *archi = fopen (nombreMision,"rb");
    if(archi != NULL)
    {
        while(fread(&aux, sizeof (Misiones), 1, archi) > 0)
        {
            printf("\nID de la mision: %i\n",aux.ID);
            printf("Destino: %s\n",aux.destino);
            printf("Cargamento: %s\n",aux.cargamento);
            printf("\n\n");
        }
        fclose(archi);
    }

}
//Se encarga de generar el ALTA de una mision en el sistema.
//Recibe el ID por parametro.
//Permite al usuario cargar todos los datos de una mision que no se encuentra en el sistema.
//Si el ID ya se encuentra ingresado, pide que intente con otro.
//Si se agrega muestra mensaje de exito.
void realizarAltaMision(int idBuscar)
{
    Misiones lista;
    int flag = 0;

    FILE* archi = fopen(nombreMision, "r+b");

    if (archi != NULL)
    {
        while(!flag && fread(&lista, sizeof(Misiones), 1, archi) > 0)
        {
            if(lista.ID == idBuscar)
            {
                if(lista.estado == 4)
                {
                    lista.estado = 1;
                    fseek(archi, sizeof(Misiones)*(-1), SEEK_CUR);
                    fwrite(&lista, sizeof(Misiones), 1, archi);
                    system("cls");
                    printf("\nEstado modificado correctamente!!\n\n");
                    imprimirMision(lista);
                }else
                {
                    system("cls");
                    printf("\nEsta mision no se encuentra en estado ''cancelada''\n\n");
                }
                flag = 1;
            }
        }
        fclose(archi);
    }
}
// Funcion que carga en el archivo nombreMision, a la nueva mision ingresada por el usuario.
// El mismo se escribe al final del archivo.
void agregarMision()
{
    Misiones lista;
    int flag=0, control, ID;

    FILE* archi = fopen(nombreMision, "ab");

    if(archi != NULL)
    {
        system("cls");

        printf("ID de la mision: \n\n");
        scanf("%i", &lista.ID);

        system("cls");
        mostrarNaves();
        printf("Escoja el ID de las naves listadas anteriormente: \n\n");
        do
        {
            scanf("%i", &lista.IDnave);
            control = buscarIDnave(lista.IDnave);
            if(control != 1)
            {
                printf("\nIngreso un ID no valido, intente con otro\n\n");
            }
        }while(control != 1);

        do
        {
            printf("Seleccione estado de la mision\n");
            printf("\t1 - Lista \n");
            printf("\t2 - En vuelo \n");
            printf("\t3 - Retornada \n");
            printf("\t4 - Cancelada \n");
            printf("\t5 - Fallida \n\n");
            scanf("%i", &lista.estado);

            if(lista.estado !=1 && lista.estado !=2 && lista.estado !=3 && lista.estado !=4 && lista.estado !=5)
            {
                printf("\nOpcion incorrecta\n\n");
                flag = 1;

            }
            else
            {
                flag = 0;
            }

        }while (flag != 0);

        printf("Destino: \n\n");
        fflush(stdin);
        gets(&lista.destino);

        printf("Cargamento: \n\n");
        fflush(stdin);
        gets(&lista.cargamento);

        printf("Ingrese cantidad de tripulantes en la mision:\n\n");
        scanf("%i", &lista.cntTripulantes);
        while (lista.cntTripulantes >= 8 || lista.cntTripulantes <= 0)
        {
            printf("\nExcede el limite o es negativo, ingresar nuevamente  cantidad tripulantes:\n\n");
            scanf("%i", &lista.cntTripulantes);
        }

        system("cls");

        mostrarAstronautasActivos();
        for(int s = 0; s < lista.cntTripulantes; s++)
        {
            for(int j = 0; j < 1; j++)
            {
                printf("\nIngrese el ID del tripulante Nro %d\n\n", s+1);
                scanf("%i", &ID);
                flag = comprobarEstadoAstro(ID);

                if(flag == 1)
                {
                    lista.tripulante[s][j] = ID;
                }
                else
                {
                    printf("\nIngreso un ID no valido o el astronauta se encuentra retirado\n\n");
                    s--;
                }
            }
        }

        printf("\Detalles de la mision:\n\n");
        fflush(stdin);
        gets(&lista.detalles);

        fwrite(&lista, sizeof(Misiones), 1, archi);

        printf("\nMision cargada correctamente!!\n");
        imprimirMision(lista);
        fclose(archi);
    }
}
//Se encarga de generar la BAJA de una mision en el sistema.
//Recibe el ID por parametro.
//Si el estado de la mision es lista, la da de baja.
//Si se da de baja la mision, se imprime un mensaje de exito. De lo contrario se informa por pantalla que no se puede dar de baja.
void realizarBajaMision(int idBuscar)
{
    int flag = 0;
    Misiones aux;

    FILE * archi = fopen(nombreMision,"r+b");
    if(archi != NULL)
    {
        while (!flag && fread(&aux, sizeof (Misiones), 1, archi) > 0)
        {
            if (aux.ID == idBuscar)
            {
                if(aux.estado == 1)
                {
                   aux.estado = 4;
                   fseek(archi, sizeof(Misiones)*(-1), SEEK_CUR);
                   fwrite(&aux,sizeof(Misiones),1,archi);
                   system("cls");
                   printf("\nBaja exitosa!!\n\n");
                   imprimirMision(aux);
                   flag = 1;

                }else
                {
                    printf("\nEsta mision no se encuentra en estado 1 (lista para despegar)\n\n");
                }
            }
        }
        fclose(archi);
    }
}
//Funcion para modificar el estado de la mision.
//Recibe por parametro el ID ingresado.
//Si se modifica, imprimi un mensaje de exito.
void modificarEstadoMision(int idBuscar)
{
    Misiones aux;
    int opcion, flag = 0;

    FILE * archi = fopen(nombreMision,"r+b");

    if(archi != NULL)
    {
        while (!flag && fread(&aux, sizeof (Misiones), 1, archi) > 0)
        {
            if (aux.ID == idBuscar)
            {
                fseek(archi, sizeof(Misiones)*(-1), SEEK_CUR);

                if (aux.estado == 1)
                {
                    aux.estado = 2;
                    fwrite(&aux,sizeof(Misiones),1,archi);
                    printf("Modificada");

                }else if(aux.estado == 2)
                {

                    printf("1-En vuelo a Retornada\n");
                    printf("2-En vuelo a Fallida\n\n");
                    scanf("%i", &opcion);

                    switch (opcion)
                    {
                    case 1:

                        aux.estado = 3;
                        fwrite(&aux,sizeof(Misiones),1,archi);
                        printf("Modificada");
                        break;

                    case 2:

                        aux.estado = 5;
                        fwrite(&aux,sizeof(Misiones),1,archi);
                        printf("Modificada");
                        break;
                    }
                }
                flag = 1;
                fclose(archi);
            }
        }
    }
}
//Funcion para modificar el destino de la mision.
//Recibe por parametro el ID ingresado.
//Si no se modifica, imprimi un mensaje informando el error.
void modificarDestino(int idBuscar)
{

    Misiones aux;
    char nuevoDestino [30];
    int flag = 0;

    FILE * archi = fopen(nombreMision, "r+b");
    if(archi !=NULL)
    {
        while(!flag && fread(&aux, sizeof(Misiones),1,archi)>0)
    {
        if(aux.ID == idBuscar)
            {
            printf("\nIngrese el nuevo destino de la mision: ");
            fflush(stdin);
            gets(nuevoDestino);

            strcpy(aux.destino,nuevoDestino);
            fseek(archi, sizeof(Misiones)*(-1), SEEK_CUR);
            fwrite(&aux, sizeof(Misiones), 1, archi);
            flag = 1;
            }
    }
    fclose(archi);
    }
    if(flag != 1)
    {
        printf("No se pudo modificar.");
    }

}
//Funcion para modificar el cargamento de la mision.
//Recibe por parametro el ID ingresado.
//Si no se modifica, imprimi un mensaje informando el error.
void modificarCargamento(int idBuscar)
{

    Misiones aux;
    char nuevoCargamento[30];
    int flag = 0;
    FILE * archi = fopen(nombreMision, "r+b");
    if(archi != NULL)
    {
    while(!flag && fread(&aux, sizeof(Misiones),1,archi)>0)
    {
        if(aux.ID == idBuscar)
            {
            printf("\nIngrese el nuevo cargamento de la mision: ");
            fflush(stdin);
            gets(nuevoCargamento);

            strcpy(aux.cargamento,nuevoCargamento);
            fseek(archi, sizeof(Misiones)*(-1), SEEK_CUR);
            fwrite(&aux, sizeof(Misiones), 1, archi);
            flag = 1;
        }
    }
    }
    fclose(archi);

}
//Funcion para mostrar por pantalla al astronauta que tiene asignado el ID.
//El ID se recibe por parametro.
//Si el ID se encuentra en el archivo, lo imprime.
void consultaIDmision(int idBuscar)
{
    int flag = 0;

    FILE* archi = fopen(nombreMision, "rb");

    Misiones aux;

    if (archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Misiones), 1, archi) > 0)
        {
            if(aux.ID == idBuscar)
            {
                fseek(archi, sizeof(Misiones)*-1, SEEK_CUR);
                imprimirMision(aux);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para modificar todos los atributos de la mision.
//Recibe por parametro el ID ingresado.
//Si el ID se encuentra en el archivo, pide ingresar todos los atributos y los modifica.
//Si se modifica, imprimi un mensaje de exito.
void modificarTodoMision(int idBuscar)
{
    Misiones lista;
    int flag = 0;

    FILE* archi = fopen(nombreMision, "r+b");

    if (archi != NULL)
    {
        while(!flag && fread(&lista, sizeof(Misiones), 1, archi) > 0)
        {
            if(lista.ID == idBuscar)
            {
                lista = cargarMision();
                fseek(archi, sizeof(Misiones)* -1, SEEK_CUR);
                fwrite(&lista, sizeof (Misiones),1,archi);
                printf("\nMision modificada correctamente en el sistema!!\n\n");
                imprimirMision(lista);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para modificar el detalle de la mision.
//Recibe por parametro el ID ingresado.
//Si el ID se encuentra en el archivo, pide ingresar un nuevo detalle y lo modifica.
//Si no se modifica, imprimi un mensaje informando el error.
void modificarDetallesMision(int idBuscar)
{
    Misiones lista;
    int flag = 0;

    FILE* archi = fopen(nombreMision, "r+b");

    if (archi != NULL)
    {
        while(!flag && fread(&lista, sizeof(Misiones), 1, archi) > 0)
        {
            if(lista.ID == idBuscar)
            {
                printf("\nIngrese los nuevos detalles:\n\n");
                fflush(stdin);
                gets(&lista.detalles);

                fseek(archi, sizeof(Misiones)* -1, SEEK_CUR);
                fwrite(&lista, sizeof (Misiones),1,archi);
                printf("\nDetalles modificados correctamente en el sistema!!\n\n");
                imprimirMision(lista);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para mostrar por pantalla al astronauta que tiene asignado el ID.
//El ID se recibe por parametro.
//Si el ID se encuentra en el archivo, lo imprime.
void modificarIDMision(int idBuscar)
{
    Misiones lista;
    int flag = 0;

    FILE* archi = fopen(nombreMision, "r+b");

    if (archi != NULL)
    {
        while(!flag && fread(&lista, sizeof(Misiones), 1, archi) > 0)
        {
            if(lista.ID == idBuscar)
            {
                printf("\nIngrese el nuevo ID:\n\n");
                scanf("%i", &lista.ID);

                fseek(archi, sizeof(Misiones)* -1, SEEK_CUR);
                fwrite(&lista, sizeof (Misiones),1,archi);
                printf("\nID modificado correctamente en el sistema!!\n\n");
                imprimirMision(lista);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para modificar los tripulantes de la mision.
//Recibe por parametro el ID.
//Utiliza funcion de astronautas para verificar los id activos en el sistema.
void modificarTripulantes(int idBuscar)
{
    Misiones lista;
    int ID, flag, control = 0;

    FILE* archi = fopen(nombreMision, "r+b");

    if(archi != NULL)
    {
        while(!control && fread(&lista, sizeof(Misiones), 1, archi) > 0)
        {
            if(lista.ID == idBuscar)
            {
                printf("\nIngrese una nueva cantidad de tripulantes:\n\n");
                scanf("%i", &lista.cntTripulantes);

                while (lista.cntTripulantes >= 8)
                {
                    printf("\nExcede el limite, ingresar nuevamente  cantidad tripulantes:\n\n");
                    scanf("%i", &lista.cntTripulantes);
                }
                system("cls");

                mostrarAstronautasActivos();
                for(int s = 0; s < lista.cntTripulantes; s++)
                {
                    for(int j = 0; j < 1; j++)
                    {
                        printf("\nIngrese el ID del tripulante Nro %d\n\n", s+1);
                        scanf("%i", &ID);
                        flag = comprobarEstadoAstro(ID);

                        if(flag == 1)
                        {
                            lista.tripulante[s][j] = ID;
                        }else
                        {
                            printf("\nIngreso un ID no valido o el astronauta se encuentra retirado\n\n");
                            s--;
                        }
                    }
                }
                fseek(archi, sizeof(Misiones)*(-1), SEEK_CUR);
                fwrite(&lista, sizeof(Misiones), 1, archi);
                system("cls");
                printf("\nTripulantes cambiados correctamente!!\n\n");
                imprimirMision(lista);
                control = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para modificar la nave de la mision.
//Recibe por parametro el ID.
//Utiliza funcion de naves para verificar los id correspondan a una nave registrada.
void modificarNaveMision(int idBuscar)
{
    Misiones lista;
    int flag, control = 0;

    FILE* archi = fopen(nombreMision, "r+b");

    if (archi != NULL)
    {
        while(!control && fread(&lista, sizeof(Misiones), 1, archi) > 0)
        {
            if(lista.ID == idBuscar)
            {
                system("cls");
                mostrarNaves();
                printf("\nIngrese el nuevo ID de la nave que desea\n\n");
                do
                {
                    scanf("%i", &lista.IDnave);
                    control = buscarIDnave(lista.IDnave);
                    if(control != 1)
                    {
                        printf("\nIngreso un ID no valido, intente con otro\n\n");
                    }
                }while(control != 1);

                fseek(archi, sizeof(Misiones)* -1, SEEK_CUR);
                fwrite(&lista, sizeof (Misiones),1,archi);
                system("cls");
                printf("\nID de la nave modificado correctamente en el sistema!!\n\n");
                imprimirMision(lista);
                control = 1;
            }
        }
        fclose(archi);
    }
}
