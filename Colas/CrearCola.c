/*****************************************
 * Nombre: CrearCola
 * Argumentos: N/A
 * Descripción: Crea una cola sin elementos.
 * Reglas de uso: 
 * Código de Retorno: Puntero a la Cola creada (vacía)
 *                    NULL - No se ha podido alocar espacio nuevo
 * Programador:
 *****************************************/

#include "Colas.h"

COLA *CrearCola()
{
    
    // Código del Alumno
    COLA *c; //Declaro el puntero de la cola, que contendrá los punteros que apunten a la Cabecera y Final de la cola 

    c = (COLA *) malloc(sizeof(COLA)); //Pido memoria para el puntero de la cola

    if(c!=NULL) //Si me han dado memoria
    {
        //Inicializo los punteros cabecera y final
        c ->Cabecera = NULL;
        c ->Final = NULL;

        return(c); //Devuelvo la cola creada
    }
    
    //No me han dado memoria, por lo que devuelvo null
    return NULL;
}