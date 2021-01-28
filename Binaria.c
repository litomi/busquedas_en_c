#include "../Utilidades/Utilidades.h"
#include <math.h>

#define TAM_ARREGLO 100
#define MIN 1
#define MAX 100

int Busqueda_Binaria_Ciclo(int *, int, int);
void Ordenamiento_Insercion(int *, int *, int );

int main(int argc, char const *argv[])
{
    int vector[TAM_ARREGLO], vectorPosiciones[TAM_ARREGLO];
    int buscado = 0;

    

    //Carga de valores aleatorios enteros
    Carga_Aleatoria(vector, TAM_ARREGLO, MIN, MAX);
    //Impresión
    Imprimir_Vector(vector, TAM_ARREGLO);

    //Genera el valor a buscar, para ejemplo.
    Carga_Aleatoria(&buscado, 1, MIN, MAX);

    printf("\nValor a buscar: %d\n", buscado);

    //Búsqueda
    int resultado = Busqueda_Binaria_Ciclo(vector, TAM_ARREGLO, buscado);

    if(resultado != -1){
        printf("\n->Valor encontrado en la posici%cn: %d\n", 162, resultado);
    }else{
        printf("\n->Valor no encontrado.");
    }

    return 0;
}

/**
 * Realiza una búsqueda binaria en un vector de enteros
 * @param int* vector
 * @param tam, tamaño vector
 * @param int buscado
 * @return int, si es exitoso, retorna la posición del elemento
 * Si no, devuelve -1.
 */

int Busqueda_Binaria_Ciclo(int *vector, int tam, int buscado)
{
    int izquierda = 0, derecha = tam - 1;
    int puntoMedio = 0, contenidoPuntoMedio = 0;
    int vectorDePosiones[tam];

    //Ordena el vector
    Ordenamiento_Insercion(vector, vectorDePosiones, tam);

    while (izquierda <= derecha)
    {
        //Ej.: [0][1][2][3][4]
        puntoMedio = floor(derecha + izquierda) / 2; //0 + 4 = 4 / 2 = 2
        contenidoPuntoMedio = *(vector + puntoMedio); //vector[2]
        
        //Si es el elemento del medio
        if (buscado == contenidoPuntoMedio) // vector[2] == buscado
        {
            //Retorna la posición en el vector sin ordenar.
            return vectorDePosiones[puntoMedio]; // =>vectorDePosiciones[2] 
        }
        else
        {
            if (buscado < contenidoPuntoMedio)
            {
                //Está a la izquierda [0][1][x][x][x]
                derecha = puntoMedio - 1; // 2 - 1 => derecha = 1 => [0][1]
            }
            else
            {
                //Está a la derecha [x][x][x][3][4]
                izquierda = puntoMedio + 1; //2 + 1 => izquierda = 3 => [3][4]
            }
        }
    }

    //Si no se encuentra.
    return -1;
}
/**
 * Función de ordenamiento por inserción.
 * Ordena dos vectores, pasados por parámetros.
 * El primero con los elementos a ordenar, y el segundo con 
 * los índices respectivos. Así, en el segundo vector, se guardan 
 * las posiciones originales de cada elemento.
 * @param *vectorElementos
 * @param *vectorDePosiciones
 * @param int tam, tamaño de los vectores
 */ 

void Ordenamiento_Insercion(int *vectorElementos, int *vectorPosiciones, int tam)
{
    int clave = 0, j, aux = 0, posClave = 0;

    for (size_t i = 0; i < tam; i++)
    {
        *(vectorPosiciones + i) = i;
    }    

    for (size_t i = 1; i < tam; i++) 
    {
        clave = *(vectorElementos + i); 
        posClave = i;

        j = i - 1;

        while (j >= 0 && *(vectorElementos + j) > clave)
        { 
            //Cambio en ambos vectores
            *(vectorElementos + j + 1) = *(vectorElementos + j); //elemento
            *(vectorPosiciones + j + 1) = *(vectorPosiciones + j); //posición del elemento
            j--; //Decrementar el índice
        }
        //Cambio en ambos vectores
        *(vectorElementos + j + 1) = clave; //elemento
        *(vectorPosiciones + j + 1) = posClave; //posición del elemento
    }

}
