/*****************************************
 * Nombre: Burbuja
 * Argumentos: LIBRO *Ficha:       Array de las fichas de libros
 *             int campo:          Campo por el que hacer la ordenación (Título o Autor)
 * Descripción: Ordena el array de fichas de libros en un doble puntero a las fichas de Libros,
 *              por lo que el movimient de datos se reduce al cambio de punteros.
 *              Se usa el algoritmo de ordenación de la burbuja.
 * Reglas de uso:
 * Código de Retorno: LIBRO **: Doble puntero ordenado por el criterio pedido a las fichas de libros.
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "../Discoteca.h"

DISCO **Burbuja(DISCO *Ficha, int Campo)
{
    DISCO **Orden;
    struct timeval inicio, fin;

    // Añade aquí la definición del resto de variables necesarias

    gettimeofday(&inicio, NULL);
    Orden = InitOrden(Ficha);
    DISCO *aux;
    char *nombreMenor;
    char * nombreComparador;
    // Código del Alumno del método de ordenación de la Burbuja

    if (Campo == ORDEN_POR_AUTOR)
    {
        for (int i = 1; i <= Estadisticas.NumeroFichas - 1; i++)
        {
            // Cogemos los N-i primeros elementos y los compara cada uno de ellos con el inmediatamente posterior.
            for (int j = 0; j < Estadisticas.NumeroFichas - i; j++)
            {
                // si están desordenados se intercambian usando una variable auxiliar.
                if (strcmp(Orden[j]->ApellAutor,Orden[j + 1]->ApellAutor) > 0)
                {
                    aux = Orden[j];
                    Orden[j] = Orden[j + 1];
                    Orden[j + 1] = aux;
                }if (strcmp(Orden[j]->ApellAutor,Orden[j + 1]->ApellAutor) == 0) //Si los apellidos son iguales, comparamps por el nombre del autor
                {
                    if (Orden[j]->NomAutor == NULL)
                        Orden[j]->NomAutor = "";
                    if (Orden[j + 1]->NomAutor == NULL)
                        Orden[j + 1]->NomAutor = "";

                    if(strcmp(Orden[j]->NomAutor, Orden[j + 1]->NomAutor) > 0)
                    {
                        aux = Orden[j];
                        Orden[j] = Orden[j + 1];
                        Orden[j + 1] = aux;
                    }
                }
            }
        }
    }
    else if(Campo == ORDEN_POR_TITULO)
    {
        for (int i = 1; i <= Estadisticas.NumeroFichas - 1; i++)
        {
            // Cogemos los N-i primeros elementos y los compara cada uno de ellos con el inmediatamente posterior.
            for (int j = 0; j < Estadisticas.NumeroFichas - i; j++)
            {
                // si están desordenados se intercambian usando una variable auxiliar.
                if (strcmp(Orden[j]->Obra,Orden[j + 1]->Obra) > 0)
                {
                    aux = Orden[j];
                    Orden[j] = Orden[j + 1];
                    Orden[j + 1] = aux;
                }
            }
        }
    }
    gettimeofday(&fin, NULL);
    Estadisticas.TiempoBurbuja = DifTiempo(inicio, fin);

    return (Orden);
}