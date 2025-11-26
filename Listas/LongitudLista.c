/*****************************************
 * Nombre: LongitudLista
 * Argumentos: Lista *Lista:   Puntero al TAD Lista
 * Descripción: Calcula el número de elementos de Lista
 * Reglas de uso: 
 * Código de Retorno: el número de elementos de Lista
 * Programador:
 *****************************************/

#include "Listas.h"

int LongitudLista(LISTA *Lista)
{
    
    // Código del Alumno
    if(Lista==NULL) //Si la lista no existe
    {
        return 0; //Devuelvo 0
    }

    int longitud = 0; //Variable que lleva la cuenta del numero de elementos dentro de la lista

    NODO *aux = Lista->Primero; //Puntero tipo nodo para recorrer la lista, lo inicializamos al primer elemento

    //recorremos la lista y contamos cuantos elementos encuentra

    while(aux!=NULL) //Bucle que se mantendrá hasta haber recorrido toda la lista
    {
        longitud++; // por cada elemento que recorra longitud = longitud+1
        aux = aux->Siguiente; // apuntamos el puntero auxiliar al siguiente elemento
    }

    return longitud; //devolvemos el tamaño final de la lista

}