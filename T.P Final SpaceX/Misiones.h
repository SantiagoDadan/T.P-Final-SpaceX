#ifndef MISIONES_H_INCLUDED
#define MISIONES_H_INCLUDED

typedef struct
{
    int ID;
    int IDnave;
    int estado;
    char destino[30];
    char cargamento[30];
    int cntTripulantes;
    int tripulante[8][1];
    char detalles [100];

}Misiones;

Misiones cargarMision();
void cargarArchivoMisiones();
void imprimirMision (Misiones lista);
void mostrarMisiones();
int ingresarIDmision();
int buscarIDmision (int);
void mostrarListadosIDmision ();
void realizarAltaMision(int);
void realizarBajaMision(int);
void consultaIDmision (int);
void modificarEstadoMision(int);
void modificarDestino(int);
void modificarCargamento(int);
void modificarTodoMision(int);
void modificarDetallesMision(int);
void modificarIDMision(int);
void modificarTripulantes(int);
void modificarNaveMision(int);

#endif // MISIONES_H_INCLUDED
