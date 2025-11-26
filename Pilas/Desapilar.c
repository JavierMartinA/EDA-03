/*****************************************
 * Nombre: Desapilar
 * Argumentos: PILA *Pila:      Puntero al TAD Pila
 *             void **Elemento: Puntero de referencia al puntero del elemento que se desapila
 * Descripción: Desapila el primer elemento de la pila y guarda el puntero desapilado en *Elemento
 * Reglas de uso:
 * Código de Retorno: Nuevo Puntero al TAD Pila
 * Programador:
 *****************************************/

#include "Pilas.h"

PILA *Desapilar(PILA *Pila, void **Elemento)
{

    // Código del Alumno
    PILA *pAux; // Creo el puntero auxiliar
    if(!EsPilaVacia(Pila)) //Compruebo si la pila no está vacía
    {
        pAux = Pila; //Apunto el puntero auxiliar a la pila
        *Elemento = Pila->Elemento; //Copio al parámetro elemento, el elemento que hay en el primer nodo de la pila
        Pila = Pila->Siguiente; //Apunto la pila al siguiente nodo, convirtiéndolo en el nuevo primer nodo de la pila
        free(pAux); //Libero el antiguo primer nodo que contenia el elemento
    }

    return (Pila); //Devuelvo la pila
    
}