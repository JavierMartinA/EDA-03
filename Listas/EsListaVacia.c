/*****************************************
 * Nombre: EsListaVacia
 * Argumentos: Lista *Lista:   Puntero al TAD Lista
 * Descripción: Comprueba si la Lista está vacía o tiene elementos
 * Reglas de uso:
 * Código de Retorno: true  - La lista está vacía
 *                    false - La lista tiene elementos
 * Programador:
 *****************************************/

#include "Listas.h"

bool EsListaVacia(LISTA *Lista)
{

    // Código del Alumno
    if (Lista == NULL || Lista->Primero == NULL) //Comprobamos si existe la lista y si tiene elementos
    {
        return TRUE; // devuelve un TRUE si la está vacía o no existe
    }
    return FALSE; // Si los punteros de lista tienen un valor distinto de null, quiere decir que existen elementos dentro
}