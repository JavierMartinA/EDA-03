/*****************************************
 * Nombre: Inserción
 * Argumentos: LIBRO *Ficha:       Array de las fichas de libros
 *             int campo:          Campo por el que hacer la ordenación (Título o Autor)
 * Descripción: Ordena el array de fichas de libros en un doble puntero a las fichas de Libros,
 *              por lo que el movimient de datos se reduce al cambio de punteros.
 *              Se usa el algoritmo de ordenación de Inserción.
 * Reglas de uso: 
 * Código de Retorno: LIBRO **: Doble puntero ordenado por el criterio pedido a las fichas de libros.
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "../Discoteca.h"

DISCO **Insercion(DISCO *Ficha,int Campo)
{
    DISCO **Orden;
    struct timeval inicio, fin;
    
    //Añade aquí la definición del resto de variables necesarias

    gettimeofday(&inicio,NULL);
    Orden=InitOrden(Ficha);

    DISCO* aux;
    char *nombreMenor;
    char * nombreComparador;

    //Código del Alumno del Algoritmo de ordenación por Inserción
    
    //gettimeofday(&fin,NULL);
    //Estadisticas.TiempoInsercion=DifTiempo(inicio,fin);

    if (Campo == ORDEN_POR_AUTOR)
    {
        // Bucle externo: comienza desde el segundo elemento (i = 1)
        for (int i = 1; i < Estadisticas.NumeroFichas; i++)
        {
            // Almacenar el elemento actual que se insertará en la secuencia ordenada
            aux = Orden[i]; 
            int j = i - 1; // Iniciar la comparación con el elemento inmediatamente anterior

            // Bucle interno: Mueve los elementos de la matriz ordenada (de 0 a i-1) 
            //que son mayores que la clave a una posición por delante de su posición actual.
            while (j >= 0)
            {
                int comparison = strcmp(Orden[j]->ApellAutor, aux->ApellAutor);

                //Si el elemento en la parte ordenada (Ficha[j]) es MAYOR
                //que el apellido de la clave (aux.ApellAutor), desplazar Ficha[j] a la derecha.
                if (comparison > 0)
                {
                    Orden[j + 1] = Orden[j];
                    j--;
                }
                // si los apellidos son IGUALES (empate), verifique el nombre.
                else if (comparison == 0)
                {
                    // Comprobación de seguridad para NULL NomAutor antes de strcmp
                    if (Orden[j]->NomAutor == NULL) Orden[j]->NomAutor = "";
                    if (aux->NomAutor == NULL) aux->NomAutor = "";
                
                    // Si el elemento en el primer nombre de la parte ordenada es MAYOR, desplácelo a la derecha.
                    if (strcmp(Orden[j]->NomAutor, aux->NomAutor) > 0)
                    {
                        Orden[j + 1] = Orden[j];
                        j--;
                    }
                    // Si los apellidos son iguales Y los nombres NO son mayores (es decir, menores o iguales),
                    // la clave está en su lugar correcto con respecto a Ficha[j]. No se desplaza.
                    else
                    {
                        break;
                    }
                }
                //Si el elemento en el apellido de la parte ordenada es MENOS, la clave está en su lugar correcto con respecto a Ficha[j]. Deje de desplazarse.
                else // comparison < 0
                {
                    break;
                }
            }
            //Colocar el elemento adonde pertenece
            Orden[j + 1] = aux;
        }
    }
    // ---
    else if(Campo == ORDEN_POR_TITULO)
    {
        // Bucle externo: comienza desde el segundo elemento (i = 1)
        for (int i = 1; i < Estadisticas.NumeroFichas; i++)
        {
            // Almacena el elemento actual que se insertará
            aux = Orden[i];
            int j = i - 1; 

            // Bucle interno: mover los elementos que son mayores que la clave una posición hacia adelante.
            while (j >= 0 && strcmp(Orden[j]->Obra, aux->Obra) > 0)
            {
                Orden[j + 1] = Orden[j];
                j--;
            }
            // Inserte la llave en su posición correcta
            Orden[j + 1] = aux;
        }
    }
    gettimeofday(&fin,NULL);
    Estadisticas.TiempoInsercion=DifTiempo(inicio,fin);

    return(Orden);
}