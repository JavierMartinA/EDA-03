/*****************************************
 * Nombre: BorrarListaIzquierda
 * Argumentos: LISTA *Lista:   Puntero al TAD Lista
 * Descripción: Borra un elemento de Lista a la izquierda.
 * Reglas de uso: 
 * Código de Retorno: Puntero al elemento que se ha borrado o NULL si no había elementos
 * Programador:
 *****************************************/

#include "Listas.h"

void *BorrarListaIzquierda(LISTA *Lista)
{
    //Codigo del alumno
    void *Elemento; //Declaro el puntero elemento que será devuelto
    // Comprobar si la lista existe o está vacía
    if (EsListaVacia(Lista) || Lista->Primero == NULL) {
        return (NULL); //Si se cumple condición, retorno null
    }

    // Declaramos el puntero tipo nodo al primer elemento de las listas
    NODO *qAux = Lista->Primero; //Este puntero almacena los datos del primer elemento

    Elemento = qAux->Elemento; ////Copio el elemento del nodo al puntero que devolveré
    // El primer elemento de la lista pasa a ser el siguiente de qAux que es el antiguo primer elemento
    Lista->Primero = qAux->Siguiente;

    // Si la lista quedó vacía, el puntero Ultimo también debe ser NULL
    if (Lista->Primero == NULL) {
        Lista->Ultimo = NULL;
    }

    // Libero la memoria del nodo
    free(qAux);

    return (Elemento); //Devuelo el elemento
}
