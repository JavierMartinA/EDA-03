/*****************************************
 * Nombre: ConsultarCima
 * Argumentos: PILA *Pila:      Puntero al TAD Pila
 * Descripción: Devuelve el puntero al primer elemento de la Pila
 * Reglas de uso: 
 * Código de Retorno: Puntero al elemento Cima
 * Programador:
 *****************************************/

#include "Pilas.h"

void *ConsultarCima(PILA *Pila)
{

    // Código del Alumno
    if (!EsPilaVacia(Pila)){ //Compruebo si la no está vacía
        return (Pila->Elemento);//Devuelvo el primer elemento de la pila
    }
}