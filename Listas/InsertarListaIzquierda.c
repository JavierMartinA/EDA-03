/*****************************************
 * Nombre: InsertarListaIzquierda
 * Argumentos: Lista *Lista:    Puntero al TAD Lista
 *             void *Elemento:  Puntero al elemento a insertar
 * Descripción: Inserta el elemento Elemento en Lista por la Izquierda
 * Reglas de uso:
 * Código de Retorno:  0 - Éxito
 *                    -1 - La lista no está creada o no se ha podido alocar memoria nueva
 * Programador:
 *****************************************/

#include "Listas.h"

int InsertarListaIzquierda(LISTA *Lista, void *Elemento)
{

    // Código del Alumno
    if (Lista != NULL) //Si la lista existe
    {
        NODO *qAux; // Declaro el nodo auxiliar que voy a usar para mantener la lista
        qAux = Lista->Primero; //Apunto el puntero auxiliar al primer nodo de la lista
        Lista->Primero = (NODO *)malloc(sizeof(NODO)); //Pido memoria para un nuevo nodo, que será el nuevo primer nodo de la lista

        if (Lista->Primero != NULL) //Si me han dado la memoria
        {
            Lista->Primero->Elemento = Elemento; // Asigno valor al puntero elemento del nuevo primer nodo de la lista
            Lista->Primero->Siguiente = qAux;    // Inicializo el puntero que apuntará al siguiente nodo, es decir, apuntará al antiguo primer nodo
            
            //Hecho para el caso de tener en pantalla la última obra
            //En caso de la última obra, habría hecho un BorrarListaIzquierda, causando que ambos punteros de la lista fueran nulos
            //Para no dejar colgado el puntero final con valor null, le apunto al nuevo nodo
            if (Lista->Ultimo == NULL) 
            {
                Lista->Ultimo = Lista->Primero;
            }

            
            return (0); // Todo ha salido bien
        }
    }
    return (-1); // Algo ha salido mal
}