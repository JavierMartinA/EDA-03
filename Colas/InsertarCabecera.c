/*****************************************
 * Nombre: InsertarCabecera
 * Argumentos: COLA *Cola:      Puntero al TAD Cola
 *             void *Elemento:  Puntero al elemento a insertar
 * Descripción: Inserta el elemento dado en la cabecera de la Cola (primer elemento)
 * Reglas de uso: La Cola tiene que estar creada
 * Código de Retorno:  0 - Éxito
 *                    -1 - La Cola no está creada o no se pudo alocar espacio nuevo
 * Programador:
 *****************************************/

#include "Colas.h"

int InsertarCabecera(COLA *Cola, void *Elemento)
{

    // Código del Alumno
    NODO *qAux; //Creamos un puntero de tipo NODO

    qAux = malloc(sizeof(NODO)); //Reservamos memoria para el puntero

    if (qAux != NULL) //Comprobamos que se ha reservado la memoría correctamente
    {
        if (Cola != NULL) //Comprobamos que exista la cola
        {
            qAux->Elemento= Elemento; //Apuntamos el puntero elemento al elemento que queremos añadir
            qAux->Siguiente = Cola->Cabecera; //Apuntamos el puntero siguiente del nuevo nodo a la cabecera original, porque queremos añadir una nueva cabecera y sustituir la actual
            if (Cola->Cabecera == NULL || Cola->Cabecera->Siguiente == NULL) //Comprobamos si solo existe la cabecera, o si no existe la cabecera
            {
                Cola->Final = Cola->Cabecera; //En el caso de que solo exista la cabecera, la cabecera pasara a ser el final. En el caso de que la cola esté vacía la cabecera y el final apuntaran al mismo elemento
            }

            Cola->Cabecera = qAux; //Convertimos qAux en la nueva cabecera
            return (0); //Retornamos 0
        }

        free(qAux); //Liberamos el puntero qAux ya que no lo hemos podido insertar debido a que no existe la cola
        return (-1); //Como la cola no existe retornamos -1
    }

    free(qAux); //Liberamos el puntero qAux ya que no nos han dado memoria
    return(-1); //Si no se ha reservado la memoría correctamente retornamos -1
}