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
    // Izquierda, derecha y medio, para extremos y pivote
    // Medio2 para cuando ya he encontrado un disco, y tengo que mirar si hay más por la izquierda
    int izquierda, derecha, medio;
    // Capacidad, para reservar memoria para resultados, reservando inicialmente para 10 discos
    int capacidad = 10;
    // Variables para los bucles for que sirven para pasar el apellido de los autores a minúscula
    // Es un bucle que sigue la misma lógica que el usado en BusquedaArbol
    int i, j;
    // Valores booleanos para buscar por la izquierda y la derecha, después de haber encotrado un disco
    bool HayIzq = true;
    bool HayDer = true;
    // Valor booleano, para salir del segundo while
    bool Encontrado2 = false;
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

    //Si no se me ha dado memoria, simplemente termino el método
    if (Resultado == NULL){
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
        for (j = 0; Orden[medio]->ApellAutor[j] != 0; j++)
        {
            AutorMedio[j] = Orden[medio]->ApellAutor[j];
            if (AutorMedio[j] < 'a') // Si alguna letra del autor está en mayúscula, sumarle 32(' ')
                AutorMedio[j] += ' ';
        }
        AutorMedio[j] = 0; // Poner fin al string después de escribir el apellido

        // Comparar el autor en el disco, respecto al autor tecleado por el usuario
        if (strcmp(AutorMedio, Autor) == 0) // Si es el buscado
        {
            Resultado[Hallados] = Orden[medio]; // Guardar el disco en resultados
            Hallados++;                         // Aumentar en 1, el número de discos hallados

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
    // Medio 2 es utilizado para mirar a la izquierda del disco que había encontrado, por lo que lo paso al anterior disco del ya encontrado
    int medio2 = medio - 1;
    // Medio es utilizado para mirar a la derecha del disco ya encontrado, por lo que lo paso al siguiente disco
    medio++;

    /*Mientras se haya encontrado un disco en el anterior while, se sigan encontrando discos compatibles a los laterales
    y no esté ya fuera de los límites del array de discos*/
    while (!Encontrado2 && Encontrado && (medio2 >= 0 && medio < Estadisticas.NumeroFichas))
    {
        // Si ya he hallado los discos para los que tengo capacidad, aumento la capacidad del array Resultado
        if (Hallados == capacidad - 1)
        {
            // Duplico la capacidad
            capacidad *= 2;
            // Busco nuevo espacio de memoria
            Resultado = (DISCO **)realloc(Resultado, sizeof(DISCO *) * capacidad);
        }
        // Compruebo que se me haya dado memoria
        if (Resultado != NULL)
        {
            // Comprobar izquierda
            if (HayIzq) // Entra si el anterior disco por la izquierda había sido compatible
            {
                AutorMedio[0] = 0; // Limpio la variable donde guardo los autores de las fichas
                // Pasar el apellido a minúsculas
                for (i = 0; Orden[medio2]->ApellAutor[i] != 0; i++)
                {
                    AutorMedio[i] = Orden[medio2]->ApellAutor[i];
                    if (AutorMedio[i] < 'a')
                        AutorMedio[i] += ' ';
                }
                AutorMedio[i] = 0; // Poner fin al string después de escribir el apellido

                // Si el de la izquierda también coincide
                if (strcmp(AutorMedio, Autor) == 0)
                {
                    // Hay izquierda, por lo que el bool de hayIzq sigue en true
                    Resultado[Hallados] = Orden[medio2]; // Guardo el disco en el array
                    Hallados++;                          // Aumento el número de discos hallados
                    medio2--;                            // Paso al anterior disco
                }
                // Si el de la izquierda no coincide
                else
                {
                    // Ya no hay más discos que coincidan a la izquierda
                    HayIzq = false;

                    // Si ya no había más a la derecha, y ya no hay a la izquierda, salgo del while
                    if (!HayDer)
                    {
                        Encontrado2 = true;
                    }
                }
            }

            // Comprobar derecha
            if (HayDer) // Entra si el anterior disco por la derecha había sido compatible
            {
                AutorMedio[0] = 0; // Limpio la variable donde guardo los autores de las fichas
                // Pasar el apellido a minúsculas
                for (j = 0; Orden[medio]->ApellAutor[j] != 0; j++)
                {
                    AutorMedio[j] = Orden[medio]->ApellAutor[j];
                    if (AutorMedio[j] < 'a') // Si el autor está en mayúscula sumarle 32(' ')
                        AutorMedio[j] += ' ';
                }
                AutorMedio[j] = 0; // Poner fin al string después de escribir el apellido

                // Si el de la derecha coincide con lo buscado
                if (strcmp(AutorMedio, Autor) == 0)
                {
                    // Hay derecha, por lo que el bool de hayDer sigue en true
                    Resultado[Hallados] = Orden[medio]; // Guardo el disco en el array
                    Hallados++;                         // Aumento el número de discos hallados
                    medio++;                            // Paso al siguiente disco
                }
                // Si el de la derecha no coincide
                else
                {
                    // Ya no hay más discos que coincidan a la derecha
                    HayDer = false;

                    // Si ya no había más discos a la izquierda, y ya tampoco a la derecha, paro el while
                    if (!HayIzq)
                    {
                        Encontrado2 = true;
                    }
                }
            }
        }
    }
    //Libero el array de punteros que contenía las fichas ordenadas
    free(Orden);

    //Cogemos el tiempo final
    gettimeofday(&fin, NULL);
    //Calculamos la diferencia entre tiempo inicial y final, y lo asignamos a la estadística correspondiente
    Estadisticas.TiempoBusquedaBinaria = DifTiempo(inicio, fin);

    //Si no se han encontrado fichas que coincidan con el autor buscado, se muestra mensaje de error
    if (Encontrado == false)
    {
        VentanaError("No hay autores que cumplan el criterio");
        return;
    }

    //Se muestran las fichas encontradas
    Listado1(Resultado, Hallados, Fichas);
    //Se libera el array de punteros con las fichas encontradas
    free(Resultado);
    return;
}