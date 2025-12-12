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
    //Ordenamos por autor
    if (Campo == ORDEN_POR_AUTOR)
    {
        //Bucle que empezará en la segunda ficha, y acabará en la última
        for (int i = 1; i < Estadisticas.NumeroFichas; i++)
        {
            // Almacenar el elemento actual que se insertará en la secuencia ordenada
            aux = Orden[i]; 
            int j = i - 1; // Se empieza a comparar con el elemento anterior

            /* El bucle mueve los elementos de la parte ordenada (de 0 a i-1) que son mayores
            que la variable auxiliar a una posición por delante de su posición actual, y pone la 
            ficha auxiliar donde le corresponde en la parte ordenada*/
            while (j >= 0 && strcmp(Orden[j]->ApellAutor, aux->ApellAutor)>=0)
            {
                //Asigno a una variable la comparación de ambas fichas
                int comparison = strcmp(Orden[j]->ApellAutor, aux->ApellAutor);

                /*Si el elemento en la parte ordenada (Ficha[j]) es MAYOR
                que el apellido de la variable auxiliar, desplazar Ficha[j] a la derecha.*/
                if (comparison > 0)
                {
                    Orden[j + 1] = Orden[j];
                    //Reducir j, para seguir comparando el auxiliar con otra ficha de la parte ordenada
                    j--;
                }
                // Si los apellidos son IGUALES, verificamos el nombre del autor.
                else if (comparison == 0)
                {
                    //Si alguno de los nombres de los autores está en null(vacio) lo ponemos como un string vacio
                    if (Orden[j]->NomAutor == NULL) Orden[j]->NomAutor = "";
                    if (aux->NomAutor == NULL) aux->NomAutor = "";
                
                    // Si el elemento en el primer nombre de la parte ordenada es MAYOR, lo desplazamos a la derecha.
                    if (strcmp(Orden[j]->NomAutor, aux->NomAutor) > 0)
                    {
                        Orden[j + 1] = Orden[j];
                        //Reducir j, para seguir comparando el auxiliar con otra ficha de la parte ordenada
                        j--;
                    }
                    /* Si los apellidos son iguales Y los nombres no son mayores (es decir, menores o iguales),
                    la clave está en su lugar correcto con respecto a Ficha[j]. No se desplaza*/
                    else
                    {
                        //Se rompe el while
                        break;
                    }
                }
            }
            //Si el elemento en el apellido de la parte ordenada es MENOS, la clave está en su lugar correcto con respecto a Ficha[j]. Deja de desplazarse.
            //Colocar el elemento adonde pertenece
            Orden[j + 1] = aux;
        }
    }
    // Ordenamos según el título de la obra
    else if(Campo == ORDEN_POR_TITULO)
    {
        //Bucle que empezará en la segunda ficha, y acabará en la última
        for (int i = 1; i < Estadisticas.NumeroFichas; i++)
        {
            // Almacenar el elemento actual que se insertará en la secuencia ordenada
            aux = Orden[i]; 
            int j = i - 1; // Se empieza a comparar con el elemento anterior 

            // Mover los elementos que son mayores que la ficha auxiliar a una posición hacia adelante
            while (j >= 0 && strcmp(Orden[j]->Obra, aux->Obra) > 0)
            {
                Orden[j + 1] = Orden[j];
                j--;
            }
            // Insertar la ficha auxiliar en su posición correcta
            Orden[j + 1] = aux;
        }
    }
    //Cogemos el tiempo final
    gettimeofday(&fin,NULL);
    //Calculamos la diferencia entre tiempo inicial y final, y lo asignamos a la estadística correspondiente
    Estadisticas.TiempoInsercion=DifTiempo(inicio,fin);

    return(Orden);
}