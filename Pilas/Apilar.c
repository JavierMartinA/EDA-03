/*****************************************
 * Nombre: Apilar
 * Argumentos: PILA *Pila:      Puntero al TAD Pila
 *             void *Elemento:  Puntero al elemento a apilar
 * Descripción: Apila el elemento Elemento al comienzo de la Pila
 * Reglas de uso: 
 * Código de Retorno: Nuevo Puntero al TAD Pila
 * Programador:
 *****************************************/

#include "Pilas.h"

PILA *Apilar(PILA *Pila,void *Elemento)
{

    // Código del Alumno
    PILA *pAux; //Declaro el puntero auxiliar
    pAux = Pila; //Apunto el puntero al primer elemento de la pila
    Pila =(PILA*) malloc(sizeof(PILA)); //Pido memoria para el puntero Pila que apuntará al nuevo nodo
    //Compruebo que se me ha dado la memoria
    if (Pila != NULL)
    {
        Pila->Elemento = Elemento; //Copio el valor del elemento al puntero
        Pila->Siguiente = pAux; //Encadeno el nuevo nodo al que anteriormente era el primero
    }
    return (Pila); //Devuelvo la pila
}