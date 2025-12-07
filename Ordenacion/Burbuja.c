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
    DISCO aux;
    char *nombreMenor;
    char * nombreComparador;
    // Código del Alumno del método de ordenación de la Burbuja

    gettimeofday(&fin, NULL);
    Estadisticas.TiempoBurbuja = DifTiempo(inicio, fin);

    if (Campo == ORDEN_POR_AUTOR)
    {
        for (int i = 1; i <= Estadisticas.NumeroFichas - 1; i++)
        {
            // Coge los N-i primeros elementos y los compara cada uno de ellos con el inmediatamente posterior.
            for (int j = 0; j < Estadisticas.NumeroFichas - i; j++)
            {
                // si están desordenados se intercambian usando una variable auxiliar.
                if (strcmp(Ficha[j].ApellAutor,Ficha[j + 1].ApellAutor) > 0)
                {
                    aux = Ficha[j];
                    Ficha[j] = Ficha[j + 1];
                    Ficha[j + 1] = aux;
                }if (strcmp(Ficha[j].ApellAutor,Ficha[j + 1].ApellAutor) == 0)
                {
                    if (Ficha[j].NomAutor == NULL)
                        Ficha[j].NomAutor = "";
                    if (Ficha[j + 1].NomAutor == NULL)
                        Ficha[j + 1].NomAutor = "";

                    if(strcmp(Ficha[j].NomAutor, Ficha[j + 1].NomAutor) > 0)
                    {
                        aux = Ficha[j];
                        Ficha[j] = Ficha[j + 1];
                        Ficha[j + 1] = aux;
                    }
                }
            }
        }
    }
    else if(Campo == ORDEN_POR_TITULO)
    {
        for (int i = 1; i <= Estadisticas.NumeroFichas - 1; i++)
        {
            // Coge los N-i primeros elementos y los compara cada uno de ellos con el inmediatamente posterior.
            for (int j = 0; j < Estadisticas.NumeroFichas - i; j++)
            {
                // si están desordenados se intercambian usando una variable auxiliar.
                if (strcmp(Ficha[j].Obra,Ficha[j + 1].Obra) > 0)
                {
                    aux = Ficha[j];
                    Ficha[j] = Ficha[j + 1];
                    Ficha[j + 1] = aux;
                }
            }
        }
    }
    gettimeofday(&fin, NULL);
    Estadisticas.TiempoBurbuja = DifTiempo(inicio, fin);

    return (Orden);
}