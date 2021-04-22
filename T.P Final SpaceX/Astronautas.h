#ifndef ASTRONAUTAS_H_INCLUDED
#define ASTRONAUTAS_H_INCLUDED

typedef struct
{
    int ID;
    char nombre[30];
    char apellido[30];
    char apodo[30];
    int edad;
    char nacionalidad[30];
    char especialidad[30];
    int horasDeVuelo;
    int misiones;
    int horasEstacionEspacial;
    int estado;

}Astronautas;

Astronautas cargarAstronauta();
void cargarArchivoAstro();
void imprimirAstronauta(Astronautas lista);
void mostrarAstronautas();
int ingresarID();
int buscarIDatronauta(int);
int buscarApodoAstronauta(char*);
void imprimirAstronautaSeleccionado(int);
void darAltaAstronauta(int);
Astronautas cargarAstroAlta();
void agregarAstroAlta();
void darBajaAstronauta(int);
void listaAltaBajaAstro(Astronautas lista);
void mostrarListaAltaBajaAstro();
void modificarIdAstro(int);
void modificarNombreAstro(int);
void modificarApellidoAstro(int);
void modificarApodoAstro(int);
void modificarEdadAstro(int);
void modificarNacionalidadAstro(int);
void modificarEspecialidadAstro(int);
void modificarHorasVueloAstro(int);
void modificarMisionesAstro(int);
void modificarHorasEeiAstro(int);
void mostrarAstronautasActivos();
int comprobarEstadoAstro(int);

#endif // ASTRONAUTAS_H_INCLUDED
