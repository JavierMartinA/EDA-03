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
    int indiceMenor;

    gettimeofday(&inicio, NULL);
    Orden = InitOrden(Ficha);

    // Código del Alumno del Algoritmo de ordenación por Selección
    //Comparamos por el título de la obra
    if (Campo == ORDEN_POR_TITULO)
    {
        /*El bucle hará N-1 iteraciones, consiguiendo un nuevo mínimo en cada una,
         y poniendolo al principio de los elementos aún no ordenados*/
        for (int i = 0; i < Estadisticas.NumeroFichas - 1; i++)
        {
            //Asigno como mínimo el primero de los elementos aún no ordenados
            min = Orden[i];
            //Asigno como indiceMenor el índice del primero de los elementos aún no ordenados
            indiceMenor = i;
            //Este bucle recorrerá desde el siguiente elemento al mínimo hasta el último de los elementos
            for (int j = i + 1; j < Estadisticas.NumeroFichas; j++)
            {
                /*Si la fichas mínima, es mayor a la ficha con la que la estoy comparando respecto al título de la obra,
                 la menor ficha es el nuevo mínimo*/
                if (strcmp(min->Obra, Orden[j]->Obra) > 0)
                {
                    //Cambio el mínimo y el indiceMenor por los de la ficha con la que estaba comparando
                    min = Orden[j];
                    indiceMenor = j;
                }
            }
            //Después de haber encontrado el mínimo entre los elementos aún no ordenados
            //En la posición del mínimo encontrado, se pone la primera ficha de los elementos aún no ordenados
            Orden[indiceMenor] = Orden[i];
            //En la posición de la primera ficha de los elementos aún no ordenados se pone el mínimo encontrado
            Orden[i] = min;
        }
    }
    //Ordenamos por autor
    else if (Campo == ORDEN_POR_AUTOR)
    {
        for (int i = 0; i < Estadisticas.NumeroFichas - 1; i++)
        {
            min = Orden[i];
            indiceMenor = i;
            for (int j = i + 1; j < Estadisticas.NumeroFichas; j++)
            {
                /*Si la fichas mínima, es mayor a la ficha con la que la estoy comparando respecto al apellido del autor,
                 la menor ficha es el nuevo mínimo*/
                if (strcmp(min->ApellAutor, Orden[j]->ApellAutor) > 0)
                {
                    indiceMenor = j;
                    min = Orden[j];
                }
                //Si la fichas mínima tiene el mismo apellido que la ficha con la que la estoy comparando, comparo los nombres de los autores
                else if (strcmp(min->ApellAutor, Orden[j]->ApellAutor) == 0)
                {

                    //Si alguno de los nombres de los autores está en null(vacio) lo ponemos como un string vacio
                    if (min->NomAutor == NULL)
                        min->NomAutor = "";
                    if (Orden[j]->NomAutor == NULL)
                        Orden[j]->NomAutor = "";

                    /*Si la fichas mínima, es mayor a la ficha con la que la estoy comparando respecto al nombre del autor,
                    la menor ficha es el nuevo mínimo*/
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
    //Cogemos el tiempo final
    gettimeofday(&fin, NULL);
    //Calculamos la diferencia entre tiempo inicial y final, y lo asignamos a la estadística correspondiente
    Estadisticas.TiempoSeleccion = DifTiempo(inicio, fin);

    return (Orden);
}