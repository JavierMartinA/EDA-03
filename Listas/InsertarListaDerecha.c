/*****************************************
 * Nombre: InsertarListaDerecha
 * Argumentos: Lista *Lista:    Puntero al TAD Lista
 *             void *Elemento:  Puntero al elemento a insertar
 * Descripción: Inserta el elemento Elemento en Lista por la Derecha
 * Reglas de uso:
 * Código de Retorno:  0 - Éxito
 *                    -1 - La lista no está creada o no se ha podido alocar memoria nueva
 * Programador:
 *****************************************/

#include "Listas.h"

int InsertarListaDerecha(LISTA *Lista, void *Elemento)
{

    // Código del Alumno
    if (Lista != NULL) //Si la lista existe
    {
        NODO *qAux;//Declaro el nodo auxiliar que voy a usar para guardar el nuevo elemento
        qAux = Lista->Ultimo; //Apunto el puntero auxiliar al último nodo de la lista
        Lista->Ultimo = (NODO*) malloc(sizeof(NODO)); //Creo un nuevo último nodo de la lista, pidiendo memoria

       
        if (Lista->Ultimo != NULL) //Si me han dado espacio
        {
                Lista->Ultimo->Elemento = Elemento; // Asigno valor al puntero elemento del nuevo nodo
                Lista->Ultimo->Siguiente = NULL;    // Inicializo el puntero del nuevo nodo que apuntará a null, ya que por el momento es el final de la lista


                if (Lista->Primero == NULL) //Si la lista no contiene ningún elemento
                {
                    Lista->Primero = Lista->Ultimo; //La cabecera y final de la lista apuntarán al mismo nodo
                }
                else //Si la lista contiene algún elemento
                {
                    qAux->Siguiente = Lista->Ultimo; //El anterior final de la lista apuntará al nuevo nodo que es el nuevo final
                }

                return (0); // Todo ha salido bien
        }
    }
    return (-1); // Algo ha salido mal
}