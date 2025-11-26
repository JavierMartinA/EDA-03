/*****************************************
 * Nombre: EsColaVacía
 * Argumentos: COLA *Cola:   Puntero al TAD Cola
 * Descripción: Devuelve 'true' si la Cola está vacía o 'false' si tiene elementos
 * Reglas de uso: 
 * Código de Retorno: true  - La Cola no tiene elementos
 *                    false - La Cola tiene elementos
 * Programador:
 *****************************************/

#include "Colas.h"

bool EsColaVacia(COLA *Cola)
{
    
    // Código del Alumno
    if(Cola == NULL || Cola->Cabecera == NULL) //Si la cola no existe o no contiene ningún elementp
    {
        return(true);//Retornamos true
    }

    //La cola tiene algún elemento
    return(false);//Retornamos false
    
}