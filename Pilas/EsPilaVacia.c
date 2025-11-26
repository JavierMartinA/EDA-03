/*****************************************
 * Nombre: EsPilaVacia
 * Argumentos: PILA *Pila:      Puntero al TAD Pila
 * Descripción: Comprueba si la Pila está vacía
 * Reglas de uso: 
 * Código de Retorno: true  - La Pila está vacía
 *                    false - La Pila tiene elementos
 * Programador:
 *****************************************/

#include "Pilas.h"

bool EsPilaVacia(PILA *Pila)
{

    // Código del Alumno
    //Si la Pila no apunta a ningún nodo, y por lo tanto no tiene ningún elemento 
    if (Pila == NULL) 
    {
        return (true); //Devuelvo true
    }

    //Si la Pila apunta a algo
    return (false); //Devuelvo false
    
}