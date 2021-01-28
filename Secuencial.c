#include "../Utilidades/Utilidades.h"
#define TAM_ARREGLO 30
#define MIN 1
#define MAX 30

int Busqueda(int *, int);

int main(int argc, char const *argv[])
{
    int vector[TAM_ARREGLO], enteroBuscado = 0, pos = 0;
    int buscado = 0;

    //Carga aleatorio del valor a buscar, para ejemplo.
    Carga_Aleatoria(&buscado, 1, MIN, MAX);

    Carga_Aleatoria(vector, TAM_ARREGLO, 1, 100);
    Imprimir_Vector(vector, TAM_ARREGLO);

    printf("\nElemento a buscar: %d\n", buscado);

    pos = Busqueda(vector, enteroBuscado);

    if(pos != -1){
        printf("Valor encontrado en la posición: %d\n", pos);
    }else{
        printf("Elemento %d, no encontrado.\n", enteroBuscado);
    }
    return 0;
}

/**
 * Busca un elemento en un arreglo de enteros 
 * en forma secuencial.
 * @param int * vector
 * @param int buscado -> elemento a buscar
 * @return int, posición en le vector del elemento encontrado
 * o '-1', en cosa de no encontrarlo.
 */
int Busqueda(int *vector, int buscado)
{
    for (size_t i = 0; i < TAM_ARREGLO; i++)
    {
        if (buscado == *(vector + i))
        {
            return i;
        }
    }
    return -1;
}