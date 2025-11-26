/*****************************************
 * Nombre: Encolar
 * Argumentos: COLA *Cola:      Puntero al TAD Cola
 *             void *Elemento:  Puntero al Elemento a insertar
 * Descripción: Se inserta el elemento dado al final de la cola.
 *              Se aloca el espacio que sea necesario
 * Reglas de uso: La cola debe estar creada
 * Código de Retorno:  0 - Éxito
 *                    -1 - La Cola no está creada o no se pudo alocar espacio nuevo
 * Programador:
 *****************************************/

#include "Colas.h"

int Encolar(COLA *Cola, void *Elemento)
{

    // Código del Alumno
    if (Cola != NULL) //Comprobar que la cola existe
    {
        NODO *qAux; //Creamos un puntero de tipo NODO
        qAux = Cola->Final; //Apuntado el puntero auxiliar al nodo al final de la cola
        Cola->Final = (NODO*) malloc(sizeof(NODO)); //Pedimos memoria para el nuevo nodo

        //Creación de nuevo nodo final
        Cola->Final->Elemento= Elemento; //Apuntamos el puntero elemento al elemento que queremos añadir
        Cola->Final->Siguiente = NULL; //Inicializamos el puntero siguiente como null, ya que el nuevo elemento se va a poner al final de la cola, porque las cosas se añaden por el final en las colas, su puntero siguiente no apunta a nada
        if (Cola->Cabecera == NULL) //Si la pila no contiene elementos
        {
            Cola->Cabecera = Cola->Final; //El elemento se coloca en la cabecera
        }
        else
        {
            qAux->Siguiente = Cola->Final; //Si ya hay más elemento en la cola, el nuevo elemento se coloca al final
        }

        return (0); //Todo ha salido bien
    }

    return (-1); //La cola no existia, por lo tanto retornamos -1


}