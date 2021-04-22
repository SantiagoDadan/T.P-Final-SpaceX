#ifndef NAVES_H_INCLUDED
#define NAVES_H_INCLUDED

typedef struct
{
    int ID;
    char tipoNave[15];
    int cntVuelos;
    int horasAcumuladas;
    int estado;

}Naves;

Naves cargarNave();
void cargarArchivoNaves();
void imprimirNave(Naves lista);
void mostrarNaves();
int ingresarIDnave();
int buscarIDnave(int);
void imprimirNaveSeleccionada(int);
void darAltaNave(int);
void darBajaNave(int);
void listaAltaBaja(Naves lista);
void mostrarListaAltaBaja();
void modificarIdNave(int);
void modificarTipoNave(int);
void modificarCntVuelos(int);
void modificarHoras(int);
void modificarEstado(int);
void modificarTodoNave(int);
void agregarNaveAlta();

#endif // NAVES_H_INCLUDED
