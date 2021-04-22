#include <stdio.h>
#include <stdlib.h>
#include "Astronautas.h"

const char nombre[] = "Astronautas.dat";

//Funcion que permite ingresar los datos de un Astronauta y los retorna.
Astronautas cargarAstronauta()
{
    Astronautas lista;
    int flag = 0;

    printf("\nCargue los datos del astronauta\n\n");

    do
    {
       lista.ID = ingresarID();

       flag = buscarIDatronauta(lista.ID);

       if(flag == 1)
       {
           printf("\nEl ID ingresado ya existe, intente con uno diferente\n\n");
       }

    }while(flag != 0);

    printf("\nNombre:  ");
    fflush(stdin);
    gets(&lista.nombre);

    printf("\nApellido:  ");
    fflush(stdin);
    gets(&lista.apellido);

    do
    {
        printf("\nApodo:  ");
        gets(&lista.apodo);

        flag = buscarApodoAstronauta(lista.apodo);

        if(flag == 1)
        {
            printf("\nEl apodo ingresado ya existe, intente con uno diferente\n\n");
        }

    }while(flag != 0);

    printf("\nEdad:  ");
    scanf("%d", &lista.edad);

    printf("\nNacionalidad:  ");
    fflush(stdin);
    gets(&lista.nacionalidad);

    printf("\nEspecialidad:  ");
    fflush(stdin);
    gets(&lista.especialidad);

    printf("\nHoras de vuelo acumuladas:  ");
    scanf("%d", &lista.horasDeVuelo);

    printf("\nCantidad de misiones espaciales realizadas:  ");
    scanf("%d", &lista.misiones);

    printf("\nHoras acumuladas en la E.E.i:  ");
    scanf("%d", &lista.horasEstacionEspacial);

    do
    {
        printf("\nEstado (1-activo / 2-retirado):  ");
        scanf("%d", &lista.estado);

        if(lista.estado != 1 && lista.estado != 2)
        {
            printf("\nIngrese una opcion no valida, intentelo nuevamente\n\n");
        }

    }while(lista.estado != 1 && lista.estado != 2);

    return lista;
}
//Funcion hardcodeada para el uso del programador.
//Si no hay datos en el archivo, inicializa los valores. Si hay datos los ingresa al final del mismo.
//Se carga en el archivo 'nombre' los datos ingresados.
// Le da la opcion al usuario de ingresar tantos datos como desee.
void cargarArchivoAstro()
{
    Astronautas lista;

    char control = 's';

    FILE* archi = fopen(nombre, "ab");

    if(archi != NULL)
    {
        while(control == 's' || control == 'S')
        {
           lista = cargarAstronauta();

           fwrite(&lista, sizeof(Astronautas), 1, archi);

           printf("\nIngrese 's' para continuar o 'n' para salir\n\n");
           fflush(stdin);
           scanf("%c", &control);
        }
        fclose(archi);
    }
}
// Funcion para la modularizacion de los datos del Astronauta.
//Se usa por parametro el retorno de la funcion cargaAstronauta.
void imprimirAstronauta(Astronautas lista)
{
    printf("\n----------------------------------");
    printf("\nID: %d\n", lista.ID);
    printf("Nombre: %s\n", lista.nombre);
    printf("Apellido: %s\n", lista.apellido);
    printf("Apodo: %s\n", lista.apodo);
    printf("Edad: %d\n", lista.edad);
    printf("Nacionalidad: %s\n", lista.nacionalidad);
    printf("Especialidad: %s\n", lista.especialidad);
    printf("Horas de vuelo: %d\n", lista.horasDeVuelo);
    printf("Misiones realizadas: %d\n", lista.misiones);
    printf("Horas en la E.E.I: %d\n", lista.horasEstacionEspacial);

    if(lista.estado == 1)
    {
        printf("Estado: Activo");
    }else
    {
        printf("Estado: Retirado");
    }
     printf("\n----------------------------------\n");
}
//Funcion para mostrar por pantalla todos los datos cargados.
void mostrarAstronautas()
{
    FILE* archi = fopen(nombre, "rb");

    Astronautas lista;

    if(archi != NULL)
    {
        while(fread(&lista, sizeof(Astronautas), 1, archi) > 0)
        {
            imprimirAstronauta(lista);

        }
        fclose(archi);
    }
}
//Pide un ID por teclado.
//Verifica que el numero ingresado no sea menor a 1.
// Si es menor, debe volver a ingresar el ID.
int ingresarID()
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
//Verifica si el ID ingresado ya existe en el archivo nombre.
//El ID es pasado por parametro.
//Si el ID se encuentra en el archivo retorna 1.
int buscarIDatronauta(int ID)
{
    int flag = 0;

    FILE* archi = fopen(nombre, "rb");

    Astronautas aux;

    if(archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Astronautas), 1, archi) > 0)
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
//Funcion para verificar que el apodo existe.
//Recibe el apodo a buscar por parametro.
//retorna 1 si existe o 0 si no existe.
int buscarApodoAstronauta(char apodo[])
{
    int flag = 0;

    FILE* archi = fopen(nombre, "rb");

    Astronautas aux;

    if(archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Astronautas), 1, archi) > 0)
        {
            if(strcmpi(aux.apodo, apodo) == 0)
            {
                flag = 1;
            }
        }
        fclose(archi);
    }

    return flag;
}
//Funcion para mostrar por pantalla al astronauta que tiene asignado el ID.
//El ID se recibe por parametro.
//Si el ID se encuentra en el archivo, lo imprime.
void imprimirAstronautaSeleccionado(int ID)
{
    int flag = 0;

    FILE* archi = fopen(nombre, "rb");
    Astronautas aux;
    if (archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Astronautas), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                fseek(archi, sizeof(Astronautas)*-1, SEEK_CUR);
                imprimirAstronauta(aux);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Se encarga de generar el ALTA de un astronauta en el sistema.
//Recibe el ID por parametro.
// Si el astronauta se encuentra retirado, cambia su estado a activo.
// Si el astronauta se encuentra activo , lo informa por pantalla.
void darAltaAstronauta(int ID)
{
    int flag = 0;

    FILE* archi = fopen(nombre, "r+b");
    Astronautas aux;

    if (archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Astronautas), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                if(aux.estado == 2)
                {
                    aux.estado = 1;
                    fseek(archi, sizeof(Astronautas)*-1, SEEK_CUR);
                    fwrite(&aux, sizeof(Astronautas), 1, archi);
                    printf("\nEstado cambiado correctamente!!\n\n");
                    imprimirAstronauta(aux);
                    flag = 1;

                }else
                {
                    printf("\nEste astronauta ya se encuentra activo\n\n");
                    flag = 1;
                }

            }
        }
        fclose(archi);
    }
}
//Se encarga de generar el ALTA de un astronauta en el sistema.
//Recibe el ID por parametro.
//Permite al usuario cargar todos los datos de un astronauta que no se encuentra en el sistema.
//Si el ID ya se encuentra ingresado, pide que intente con otro.
Astronautas cargarAstroAlta()
{
    Astronautas lista;
    int flag = 0;

    printf("\nCargue los datos del astronauta\n\n");

    do
    {
       lista.ID = ingresarID();

       flag = buscarIDatronauta(lista.ID);

       if(flag == 1)
       {
           printf("\nEl ID ingresado ya existe, intente con uno diferente\n\n");
       }

    }while(flag != 0);

    printf("\nNombre:  ");
    fflush(stdin);
    gets(&lista.nombre);

    printf("\nApellido:  ");
    fflush(stdin);
    gets(&lista.apellido);

    do
    {
        printf("\nApodo:  ");
        gets(&lista.apodo);

        flag = buscarApodoAstronauta(lista.apodo);

        if(flag == 1)
        {
            printf("\nEl apodo ingresado ya existe, intente con uno diferente\n\n");
        }

    }while(flag != 0);

    printf("\nEdad:  ");
    scanf("%d", &lista.edad);

    printf("\nNacionalidad:  ");
    fflush(stdin);
    gets(&lista.nacionalidad);

    printf("\nEspecialidad:  ");
    fflush(stdin);
    gets(&lista.especialidad);

    printf("\nHoras de vuelo acumuladas:  ");
    scanf("%d", &lista.horasDeVuelo);

    printf("\nCantidad de misiones espaciales realizadas:  ");
    scanf("%d", &lista.misiones);

    printf("\nHoras acumuladas en la E.E.i:  ");
    scanf("%d", &lista.horasEstacionEspacial);

    lista.estado = 1;

    return lista;
}
// Funcion que carga en el archivo nombre, al nuevo astronauta ingresado por el usuario.
// El mismo se escribe al final del archivo.
void agregarAstroAlta()
{
    Astronautas lista;

    FILE* archi = fopen(nombre, "ab");

    if(archi != NULL)
    {
        lista = cargarAstroAlta();

        fwrite(&lista, sizeof(Astronautas), 1, archi);
        system("cls");
        printf("\nAstronauta agregada correctamente!!\n\n");
        imprimirAstronauta(lista);
    }
    fclose(archi);
}
//Se encarga de generar la BAJA de un astronauta en el sistema, solicita el ID.
//Si el astronauta  se encuentra retirado, muestra un mensaje informando la situacion.
//Recibe por parametro al ID.
//Si se da de baja el astronauta, se imprime un mensaje de exito.
void darBajaAstronauta(int ID)
{
    int flag = 0;

    FILE* archi = fopen(nombre, "r+b");
    Astronautas aux;

    if (archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Astronautas), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                if(aux.estado == 1)
                {
                    aux.estado = 2;
                    fseek(archi, sizeof(Astronautas)*-1, SEEK_CUR);
                    fwrite(&aux, sizeof(Astronautas), 1, archi);
                    printf("\nEstado cambiado correctamente!!\n\n");
                    imprimirAstronauta(aux);
                    flag = 1;

                }else
                {
                    printf("\nEste astronauta ya se encuentra retirado\n\n");
                    flag = 1;
                }

            }
        }
        fclose(archi);
    }
}
//Funcion para modularizar la lista de alta y baja de un astronauta.
//Recibe por parametro los datos del astronauta.
void listaAltaBajaAstro(Astronautas lista)
{
    printf("\n------------------------------------\n");
    printf("%s  %s\n", lista.nombre, lista.apellido);
    if(lista.estado == 1)
    {
        printf("Estado: Activo\n");
    }else
    {
        printf("Estado: Retirado\n");
    }
    printf("ID:  %d", lista.ID);
    printf("\n------------------------------------\n");
}
//Muestra por pantalla la lista alta o baja de astronautas.
void mostrarListaAltaBajaAstro()
{
    FILE* archi = fopen(nombre, "rb");

    Astronautas lista;

    if(archi != NULL)
    {
        while(fread(&lista, sizeof(Astronautas), 1, archi) > 0)
        {
            listaAltaBajaAstro(lista);

        }
        fclose(archi);
    }
}
//Funcion para modificar el ID.
//Recibe por parametro el ID a buscar.
//Si se modifica, imprimi un mensaje de exito.
void modificarIdAstro(int ID)
{
    int flag = 0, control = 0, nuevo;

    Astronautas aux;

    FILE* archi = fopen(nombre, "r+b");

    if(archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Astronautas), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                do
                {
                    printf("\nIngrese un nuevo ID\n\n");
                    scanf("%d", &nuevo);

                    control = buscarIDatronauta(nuevo);

                    if(control == 1)
                    {
                        printf("\nEl ID ingresado ya existe, intente con uno diferente\n\n");
                    }
                }while(control != 0);

                aux.ID = nuevo;
                fseek(archi, sizeof(Astronautas)*-1, SEEK_CUR);
                fwrite(&aux, sizeof(Astronautas), 1, archi);
                system("cls");
                printf("\nID cambiado correctamente!!\n\n");
                imprimirAstronauta(aux);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para modificar el nombre del astronauta.
//Recibe por parametro el ID ingresado.
//Si se modifica, imprimi un mensaje de exito.
void modificarNombreAstro(int ID)
{
    int flag = 0;
    char nuevo[30];
    Astronautas aux;

    FILE* archi = fopen(nombre, "r+b");

    if(archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Astronautas), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                printf("\nIngrese un nuevo nombre\n\n");
                fflush(stdin);
                gets(&nuevo);

                strcpy(aux.nombre, nuevo);
                fseek(archi, sizeof(Astronautas)*-1, SEEK_CUR);
                fwrite(&aux, sizeof(Astronautas), 1, archi);
                system("cls");
                printf("\nNombre cambiado correctamente!!\n\n");
                imprimirAstronauta(aux);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para modificar el apellido del astronauta.
//Recibe por parametro el ID ingresado.
//Si se modifica, imprimi un mensaje de exito.
void modificarApellidoAstro(int ID)
{
    int flag = 0;
    char nuevo[30];
    Astronautas aux;

    FILE* archi = fopen(nombre, "r+b");

    if(archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Astronautas), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                printf("\nIngrese un nuevo apellido\n\n");
                fflush(stdin);
                gets(&nuevo);

                strcpy(aux.apellido, nuevo);
                fseek(archi, sizeof(Astronautas)*-1, SEEK_CUR);
                fwrite(&aux, sizeof(Astronautas), 1, archi);
                system("cls");
                printf("\nApellido cambiado correctamente!!\n\n");
                imprimirAstronauta(aux);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para modificar el apodo del astronauta.
//Recibe por parametro el ID ingresado.
//Si se modifica, imprimi un mensaje de exito.
void modificarApodoAstro(int ID)
{
    int flag = 0, control = 0;
    char nuevo[30];
    Astronautas aux;

    FILE* archi = fopen(nombre, "r+b");

    if(archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Astronautas), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                do
                {
                    printf("\nIngrese un nuevo apodo\n\n");
                    fflush(stdin);
                    gets(&nuevo);
                    control = buscarApodoAstronauta(nuevo);
                    if(control == 1)
                    {
                        printf("\nEl apodo ingresado ya existe, intente con uno diferente\n\n");
                    }
                }while(control != 0);
                strcpy(aux.apodo, nuevo);
                fseek(archi, sizeof(Astronautas)*-1, SEEK_CUR);
                fwrite(&aux, sizeof(Astronautas), 1, archi);
                system("cls");
                printf("\nApodo cambiado correctamente!!\n\n");
                imprimirAstronauta(aux);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para modificar la edad del astronauta.
//Recibe por parametro el ID ingresado.
//Si se modifica, imprimi un mensaje de exito.
void modificarEdadAstro(int ID)
{
    int flag = 0, nuevo;
    Astronautas aux;

    FILE* archi = fopen(nombre, "r+b");

    if(archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Astronautas), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                printf("\nIngrese una nueva edad\n\n");

                scanf("%d", &nuevo);

                aux.edad = nuevo;
                fseek(archi, sizeof(Astronautas)*-1, SEEK_CUR);
                fwrite(&aux, sizeof(Astronautas), 1, archi);
                system("cls");
                printf("\nEdad cambiada correctamente!!\n\n");
                imprimirAstronauta(aux);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para modificar la nacionalidad del astronauta.
//Recibe por parametro el ID ingresado.
//Si se modifica, imprimi un mensaje de exito.
void modificarNacionalidadAstro(int ID)
{
    int flag = 0;
    char nuevo[30];
    Astronautas aux;

    FILE* archi = fopen(nombre, "r+b");

    if(archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Astronautas), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                printf("\nIngrese una nueva nacionalidad\n\n");
                fflush(stdin);
                gets(&nuevo);

                strcpy(aux.nacionalidad, nuevo);
                fseek(archi, sizeof(Astronautas)*-1, SEEK_CUR);
                fwrite(&aux, sizeof(Astronautas), 1, archi);
                system("cls");
                printf("\nNacionalidad cambiada correctamente!!\n\n");
                imprimirAstronauta(aux);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para modificar la especialidad del astronauta.
//Recibe por parametro el ID ingresado.
//Si se modifica, imprimi un mensaje de exito.
void modificarEspecialidadAstro(int ID)
{
    int flag = 0;
    char nuevo[30];
    Astronautas aux;

    FILE* archi = fopen(nombre, "r+b");

    if(archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Astronautas), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                printf("\nIngrese una nueva especialidad\n\n");
                fflush(stdin);
                gets(&nuevo);

                strcpy(aux.especialidad, nuevo);
                fseek(archi, sizeof(Astronautas)*-1, SEEK_CUR);
                fwrite(&aux, sizeof(Astronautas), 1, archi);
                system("cls");
                printf("\nEspecialidad cambiada correctamente!!\n\n");
                imprimirAstronauta(aux);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para modificar las horas de vuelo del astronauta.
//Recibe por parametro el ID ingresado.
//Si se modifica, imprimi un mensaje de exito.
void modificarHorasVueloAstro(int ID)
{
    int flag = 0, nuevo;
    Astronautas aux;

    FILE* archi = fopen(nombre, "r+b");

    if(archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Astronautas), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                printf("\nIngrese una nueva cantidad de horas\n\n");
                scanf("%d", &nuevo);

                aux.horasDeVuelo = nuevo;
                fseek(archi, sizeof(Astronautas)*-1, SEEK_CUR);
                fwrite(&aux, sizeof(Astronautas), 1, archi);
                system("cls");
                printf("\nHoras cambiadas correctamente!!\n\n");
                imprimirAstronauta(aux);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para modificar la cantidad de misiones del astronauta.
//Recibe por parametro el ID ingresado.
//Si se modifica, imprimi un mensaje de exito.
void modificarMisionesAstro(int ID)
{
    int flag = 0, nuevo;
    Astronautas aux;

    FILE* archi = fopen(nombre, "r+b");

    if(archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Astronautas), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                printf("\nIngrese una nueva cantidad de misiones realizadas\n\n");
                scanf("%d", &nuevo);

                aux.misiones = nuevo;
                fseek(archi, sizeof(Astronautas)*-1, SEEK_CUR);
                fwrite(&aux, sizeof(Astronautas), 1, archi);
                system("cls");
                printf("\nCantidad de misiones cambiadas correctamente!!\n\n");
                imprimirAstronauta(aux);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para modificar las horas en la EEI del astronauta.
//Recibe por parametro el ID ingresado.
//Si se modifica, imprimi un mensaje de exito.
void modificarHorasEeiAstro(int ID)
{
    int flag = 0, nuevo;
    Astronautas aux;

    FILE* archi = fopen(nombre, "r+b");

    if(archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Astronautas), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                printf("\nIngrese una nueva cantidad de horas acumuladas en la E.E.I\n\n");
                scanf("%d", &nuevo);

                aux.horasEstacionEspacial = nuevo;
                fseek(archi, sizeof(Astronautas)*-1, SEEK_CUR);
                fwrite(&aux, sizeof(Astronautas), 1, archi);
                system("cls");
                printf("\nCantidad de horas cambiadas correctamente!!\n\n");
                imprimirAstronauta(aux);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion para modificar todos los atributos astronauta.
//Recibe por parametro el ID ingresado.
//Si se modifica, imprimi un mensaje de exito.
void modificarTodoAstro(int ID)
{
    int flag = 0, nuevo;
    Astronautas aux;

    FILE* archi = fopen(nombre, "r+b");

    if(archi != NULL)
    {
        while(!flag && fread(&aux, sizeof(Astronautas), 1, archi) > 0)
        {
            if(aux.ID == ID)
            {
                printf("\nNuevos datos\n\n");
                aux = cargarAstronauta();
                fseek(archi, sizeof(Astronautas)*-1, SEEK_CUR);
                fwrite(&aux, sizeof(Astronautas), 1, archi);
                system("cls");
                printf("\nDatos modificados correctamente!!\n\n");
                imprimirAstronauta(aux);
                flag = 1;
            }
        }
        fclose(archi);
    }
}
//Funcion que muestra los astronautas activos registrados.
// Si esta activo los muestra por pantalla.
void mostrarAstronautasActivos()
{
    FILE* archi = fopen(nombre, "rb");

    Astronautas lista;

    if(archi != NULL)
    {
        while(fread(&lista, sizeof(Astronautas), 1, archi) > 0)
        {
            if(lista.estado == 1)
            {
                printf("\n---------------------------\n");
                printf("ID:  %d\n", lista.ID);
                printf("%s  %s\n", lista.nombre, lista.apellido);
                printf("---------------------------\n");

            }
        }
        fclose(archi);
    }
}
//Funcion que comprueba si el astronauta se encuentra activo.
//Recibe por parametro el ID.
//Devuelve 1 si su estado se encuentra activo.
int comprobarEstadoAstro(int ID)
{
    int flag = 0;

    FILE* archi = fopen(nombre, "rb");

    Astronautas lista;

    if(archi != NULL)
    {
        while(fread(&lista, sizeof(Astronautas), 1, archi) > 0)
        {
            if(lista.ID == ID)
            {
                if(lista.estado == 1)
                {
                    flag = 1;
                }
            }
        }
        fclose(archi);
    }

    return flag;
}
