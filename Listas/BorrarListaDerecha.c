/*****************************************
 * Nombre: BorrarListaDerecha
 * Argumentos: LISTA *Lista:   Puntero al TAD Lista
 * Descripción: Borra un elemento de Lista a la derecha.
 * Reglas de uso:
 * Código de Retorno: Puntero al elemento que se ha borrado o NULL si no había elementos
 * Programador:
 *****************************************/

#include "Listas.h"

void *BorrarListaDerecha(LISTA *Lista)
{

    // Código del Alumno
    NODO *qAux, *l, *c; // Declaro el nodo auxiliar que voy a usar para guardar el nuevo elemento, el puntero anterior al nodo eliminado para luego conectar la lista, y el puntero para recorrer la lista

    void *Elemento; //Declaro el puntero elemento que será devuelto

    int contador = 0; //Declaro un contador para recorrer la lista

    if (!EsListaVacia(Lista)) //Si la lista no existe o no contiene elementos 
    {
        l = NULL; //Inicializo el puntero que conectará la lista a null
        c = Lista->Primero; //Inicializo el nodo para recorrer la lista al nodo inicial
        qAux = Lista->Primero; //Inicializo el nodo auxiliar

        while (c != NULL) //Mientras el nodo no apunté una más allá del nodo final, continúo el bucle
        {
            contador++; //Contador + 1
            c = c->Siguiente; //Apunto el puntero al siguiente nodo
        }

        if (contador == 1) //Si solo hay un elemento en la lista
        {
            Elemento = qAux->Elemento; //Copio el elemento del nodo al puntero que devolveré

            Lista->Primero = NULL; //Reseteo la lista 
            Lista->Ultimo = NULL;
        }
        else //Si hay más de un elemento en la lista
        {
            for (int i = 0; i < contador - 1; i++) //Recorrerá hasta el nodo anterior al que debo eliminar
            {
                //El puntero qAux acabará apuntando al nodo que debemos eliminar, y l apuntará al nodo anterior
                l = qAux; //Apunto el puntero l, al puntero auxiliar.
                qAux = qAux->Siguiente; //El puntero auxiliar apunta al siguiente elemento
            }

            Elemento = qAux->Elemento; //Copio el elemento del nodo que está apuntando mi puntero auxiliar

            l->Siguiente = NULL; //El anterior nodo debe apuntar a null, ya que ahora es el final de la lista
            Lista->Ultimo = l; //Apunta el ultimo de la lista al puntero l, que ahora es el nodo final
        }

        free(qAux); // Libero la memoria del puntero auxiliar, eliminando el nodo
        return (Elemento); //Devuelvo el elemento
    }
    
    return NULL; // Algo ha salido mal
}