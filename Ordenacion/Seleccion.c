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
    char *min;
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
            obraMenor = Orden[i];
            min = Orden[i]->Obra;
            indiceMenor = i;
            for (int j = i + 1; j < Estadisticas.NumeroFichas; j++)
            {
                comparador = Orden[j]->Obra;
                if (strcmp(min, comparador) > 0)
                {
                    obraMenor = Orden[j];
                    indiceMenor = j;
                    min = Orden[j]->Obra;
                }
            }
            Orden[indiceMenor] = Orden[i];
            Orden[i] = obraMenor;
        }
    }
    else if (Campo == ORDEN_POR_AUTOR)
    {
        for (int i = 0; i < Estadisticas.NumeroFichas - 1; i++)
        {
            obraMenor = Orden[i];
            min = Orden[i]->ApellAutor;
            indiceMenor = i;
            for (int j = i + 1; j < Estadisticas.NumeroFichas; j++)
            {
                comparador = Orden[j]->ApellAutor;
                if (strcmp(min, comparador) > 0)
                {
                    obraMenor = Orden[j];
                    indiceMenor = j;
                    min = Orden[j]->ApellAutor;
                }
                else if (strcmp(min, comparador) == 0)
                {
                    nombreMenor = obraMenor->NomAutor;
                    nombreComparador = Orden[j]->NomAutor;

                    // Comprobar NULLs para evitar errores de segmentación
                    if (nombreMenor == NULL)
                        nombreMenor = "";
                    if (nombreComparador == NULL)
                        nombreComparador = "";

                    if (strcmp(nombreMenor, nombreComparador) > 0)
                    {
                        obraMenor = Orden[j];
                        indiceMenor = j;
                    }
                }
            }
            Orden[indiceMenor] = Orden[i];
            Orden[i] = obraMenor;
        }
    }
    gettimeofday(&fin, NULL);
    Estadisticas.TiempoSeleccion = DifTiempo(inicio, fin);

    return (Orden);
}