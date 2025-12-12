/*****************************************
 * Nombre: BusquedaBinaria
 * Argumentos: LIBRO *Fichas:       Array de las fichas de libros
 * Descripción: Después de capturar los apellidos de un autor, busca las fichas de libros de ese autor,
 *              por el método de búsqueda binaria
 *              La comparación de los apellidos se hace en mayúsculas.
 *              Después se muestran los resultados en una pantalla de scroll.
 * Reglas de uso:
 * Código de Retorno: N/A
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "Busqueda.h"

void BusquedaBinaria(DISCO *Fichas)
{
    char *Autor;
    DISCO **Resultado = NULL;
    DISCO **Orden = NULL;
    int Hallados = 0;
    struct timeval inicio, fin;
    bool Encontrado;

    // Añadir aquí la definición del resto de variables usadas
    // Izquierda, derecha y medio, para extremos y pivote.
    // Y luego se usa izquierda y medio, para encontrar según están ordenados, el primero de los discos entre todos los que hay coincidentes
    int izquierda, derecha, medio;
    // Capacidad, para reservar memoria para resultados, reservando inicialmente para 10 discos
    int capacidad = 10;
    // Variables para los bucles for que sirven para pasar el apellido de los autores a minúscula
    // Es un bucle que sigue la misma lógica que el usado en BusquedaArbol
    int i;
    // Variable para guardar el nombre del autor de la ficha
    char AutorMedio[256];

    if ((Autor = LeerAutor()) == NULL)
        return;

    gettimeofday(&inicio, NULL);

    Orden = Quicksort(Fichas, ORDEN_POR_AUTOR);

    // Código del alumno del Algoritmo de Búsqueda Binaria
    /*La busqueda binaria se basa en coger la mitad entre todos los números de tu array y
    comparar si es el valor buscado.
    Si al comparar te sale que el valor buscado es mayor a tu medio, claramente haces el mismo
    proceso pero solo con los números a la derecha de tu medio, y buscas un nuevo medio
    Si al comparar te sale que el valor buscado es menor a tu medio, claramente haces el mismo
    proceso pero solo con los números a la izquierda de tu medio, y buscas un nuevo medio*/

    // Reservo memoria para Resultado, reservando memoria para 10 discos
    Resultado = (DISCO **)malloc(sizeof(DISCO *) * capacidad);

    // Si no se me ha dado memoria, simplemente termino el método
    if (Resultado == NULL)
    {
        return;
    }
    // Inicializo la variable booleana de encontrada a false
    Encontrado = false;
    // Inicializo izquierda y derecha, poniéndolos como los extremos de todos los discos
    izquierda = 0;
    derecha = Estadisticas.NumeroFichas - 1;

    // Bucle para buscar por busqueda binaria, hasta encontrar algún disco o encontrar que no existe ninguno (izquierda > derecha)
    while (!Encontrado && izquierda <= derecha)
    {
        // El medio será truncado, es decir si el medio sale 1.5, será 1
        medio = (int)((izquierda + derecha) / 2);

        // Pasar el nombre de los autores a minúscula
        for (i = 0; Orden[medio]->ApellAutor[i] != 0; i++)
        {
            AutorMedio[i] = Orden[medio]->ApellAutor[i];
            if (AutorMedio[i] < 'a') // Si alguna letra del autor está en mayúscula, sumarle 32(' ')
                AutorMedio[i] += ' ';
        }
        AutorMedio[i] = 0; // Poner fin al string después de escribir el apellido

        // Comparar el autor en el disco, respecto al autor tecleado por el usuario
        if (strcmp(AutorMedio, Autor) == 0) // Si es el buscado
        {
            Encontrado = true; // Pasar la variable booleana a true para acabar el bucle
        }
        else if (strcmp(AutorMedio, Autor) > 0) // Si el autor buscado está más a la izquierda
        {
            // La izquierda se queda igual, solo se cambia la derecha ya que el resultado está a la izquierda del antiguo medio
            derecha = medio - 1;
        }
        else // Si el autor buscado está más a la derecha
        {
            // La derecha se queda igual, solo se cambia la izquierda ya que el resultado está a la derecha del antiguo medio
            izquierda = medio + 1;
        }
    }
    // En este punto solo tendré un disco y tendré que comprobar los demás.
    // O quizá no tenga ningún disco, por lo que Encontrado = false, y no entraré al siguiente bucle
    if (Encontrado)
    {
        /*Mientras se haya encontrado un disco en el anterior while, se seguirán buscando discos a la izquierda del encontrado,
        para encontrar el primero de todos los discos compatibles, hasta encontrar uno no compatible o encontrar el límite del array*/
        while (medio > 0)
        {
            // Reutilizo la variable izquierda para ir buscando discos coincidentes a la izquierda del ya encontrado
            izquierda = medio - 1;
            AutorMedio[0] = 0; // Limpio la variable donde guardo los autores de las fichas
            // Pasar el apellido a minúsculas
            for (i = 0; Orden[izquierda]->ApellAutor[i] != 0; i++)
            {
                AutorMedio[i] = Orden[izquierda]->ApellAutor[i];
                if (AutorMedio[i] < 'a')
                    AutorMedio[i] += ' ';
            }
            AutorMedio[i] = 0; // Poner fin al string después de escribir el apellido

            // Si el de la izquierda también coincide
            if (strcmp(AutorMedio, Autor) == 0)
            {
                // Paso al siguiente a la izquierda
                medio--;
            }
            // Si el de la izquierda no coincide, ya he encontrado el primero de todos los discos compatibles, y salgo del while
            else
            {
                break;
            }
        }

        /*Hago otro bucle para insertar los discos compatibles al array Resultados, seguirá insertando
        hasta encontrar un disco no compatible, o llegar al límite del array*/
        while (medio < Estadisticas.NumeroFichas)
        {
            // Pasar el nombre de los autores a minúscula
            for (i = 0; Orden[medio]->ApellAutor[i] != 0; i++)
            {
                AutorMedio[i] = Orden[medio]->ApellAutor[i];
                if (AutorMedio[i] < 'a') // Si alguna letra del autor está en mayúscula, sumarle 32(' ')
                    AutorMedio[i] += ' ';
            }
            AutorMedio[i] = 0; // Poner fin al string después de escribir el apellido

            // Si el disco de esta iteración es compatible con el buscado, lo inserto al array
            if (strcmp(AutorMedio, Autor) == 0)
            {
                // Si ya he hallado los discos para los que tengo capacidad, aumento la capacidad del array Resultado
                if (Hallados == capacidad - 1)
                {
                    // Duplico la capacidad
                    capacidad *= 2;
                    // Busco nuevo espacio de memoria
                    Resultado = (DISCO **)realloc(Resultado, sizeof(DISCO *) * capacidad);
                    // Compruebo que se me haya dado memoria
                    if (Resultado == NULL)
                    {
                        return; // Si no se me ha dado memoria, termino el método
                    }
                }
                // Inserto el disco compatible al array Resultado
                Resultado[Hallados] = Orden[medio];
                // Aumento el número de discos hallados
                Hallados++;
                // Paso al siguiente disco a la derecha
                medio++;
            }
            /*Si el disco de esta iteración no es compatible, debo salir del while, debido a que
            ya he insertado todos los discos compatible en el array Resultado*/
            else
            {
                break;
            }
        }
    }

    // Libero el array de punteros que contenía las fichas ordenadas
    free(Orden);

    // Cogemos el tiempo final
    gettimeofday(&fin, NULL);
    // Calculamos la diferencia entre tiempo inicial y final, y lo asignamos a la estadística correspondiente
    Estadisticas.TiempoBusquedaBinaria = DifTiempo(inicio, fin);

    // Si no se han encontrado fichas que coincidan con el autor buscado, se muestra mensaje de error
    if (Encontrado == false)
    {
        VentanaError("No hay autores que cumplan el criterio");
        return;
    }

    // Se muestran las fichas encontradas
    Listado1(Resultado, Hallados, Fichas);
    // Se libera el array de punteros con las fichas encontradas
    free(Resultado);
    return;
}