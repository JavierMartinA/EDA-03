/*****************************************
 * Nombre: InitOrden
 * Argumentos: LIBRO *Fichas:   Array de libros
 * Descripción: Genera un array con los punteros a los libros ordenados por
 *              su orden numérico, es decir, el mismo orden el que están en
 *              en array de libros Fichas.
 * Reglas de uso: Hay que alocar el espacio para el array de punteros
 * Código de Retorno: Puntero al array de punteros a los libros ordenados (LIBROS **)
 * Programador:
 *****************************************/

#include "../Discoteca.h"

DISCO **InitOrden(DISCO *Fichas)
{
    
    // Código del alumno
    DISCO **InitOrden; //Creo el array de punteros
    //Reservo memoria para el doble puntero, que tendrá espacio para un puntero a Disco multiplicado por el número de fichas
    InitOrden = (DISCO**) malloc(Estadisticas.NumeroFichas*sizeof(DISCO*)); 
    if (InitOrden !=NULL)
    {
        for (int i = 0; i < Estadisticas.NumeroFichas; i++)
        {
            InitOrden[i] = &(Fichas[i]);
        }
        return (InitOrden);
    }
    VentanaError("No hay espacio");
    
}