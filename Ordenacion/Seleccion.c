/*****************************************
 * Nombre: Seleccion
 * Argumentos: LIBRO *Ficha:       Array de las fichas de libros
 *             int campo:          Campo por el que hacer la ordenación (Título o Autor)
 * Descripción: Ordena el array de fichas de libros en un doble puntero a las fichas de Libros,
 *              por lo que el movimient de datos se reduce al cambio de punteros.
 *              Se usa el algoritmo de ordenación de Selección.
 * Reglas de uso:
 * Código de Retorno: LIBRO **: Doble puntero ordenado por el criterio pedido a las fichas de libros.
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "../Discoteca.h"

DISCO **Seleccion(DISCO *Ficha, int Campo)
{
    DISCO **Orden;
    struct timeval inicio, fin;

    // Añade aquí la definición del resto de variables necesarias
    DISCO *min;
    char *comparador;
    int indiceMenor;
    DISCO *obraMenor;
    char *nombreMenor;
    char * nombreComparador;

    gettimeofday(&inicio, NULL);
    Orden = InitOrden(Ficha);

    // Código del Alumno del Algoritmo de ordenación por Selección
    if (Campo == ORDEN_POR_TITULO)
    {
        for (int i = 0; i < Estadisticas.NumeroFichas - 1; i++)
        {
            min = Orden[i];
            indiceMenor = i;
            for (int j = i + 1; j < Estadisticas.NumeroFichas; j++)
            {
                if (strcmp(min->Obra, Orden[j]->Obra) > 0)
                {
                    min = Orden[j];
                    indiceMenor = j;
                }
            }
            Orden[indiceMenor] = Orden[i];
            Orden[i] = min;
        }
    }
    else if (Campo == ORDEN_POR_AUTOR)
    {
        for (int i = 0; i < Estadisticas.NumeroFichas - 1; i++)
        {
            min = Orden[i];
            indiceMenor = i;
            for (int j = i + 1; j < Estadisticas.NumeroFichas; j++)
            {
                if (strcmp(min->ApellAutor, Orden[j]->ApellAutor) > 0)
                {
                    indiceMenor = j;
                    min = Orden[j];
                }
                else if (strcmp(min->ApellAutor, Orden[j]->ApellAutor) == 0)
                {

                    // Comprobar NULLs para evitar errores de segmentación
                    if (min->NomAutor == NULL)
                        min->NomAutor = "";
                    if (Orden[j]->NomAutor == NULL)
                        Orden[j]->NomAutor = "";

                    if (strcmp(min->NomAutor, Orden[j]->NomAutor) > 0)
                    {
                        min = Orden[j];
                        indiceMenor = j;
                    }
                }
            }
            Orden[indiceMenor] = Orden[i];
            Orden[i] = min;
        }
    }
    gettimeofday(&fin, NULL);
    Estadisticas.TiempoSeleccion = DifTiempo(inicio, fin);

    return (Orden);
}