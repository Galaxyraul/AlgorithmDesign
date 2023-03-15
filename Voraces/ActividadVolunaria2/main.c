#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define NUM_ARCHIVOS 20
#define TAM_DISCO 1000

/*
 * Primer algoritmo
 * Demostración:
 * La estrategia seguida para maximizar el número de archivos consiste en introducir siempre los de menor almacenamiento necesario
 * Para demostrar que esto es un algorítmo que obtiene solución óptima vamos a utilizar redución al absurdo
 * Asumamos que nuestra solución no es optima eso sígnifica que existe un conjunto c' tal que
 * contiene un número total de archivos mayor que el obtenido por nuestra estrategia es decir que existen  A', A'' ∈ Archivos
 * tal que A'+ A'' es menor que el mayor elemento del conjunto.Sin embargo, eso querría decir que nuestro algoritmo no escoge los archivos menores
 * haciendo así que no se cumpliera la premisa del funcionamiento cosa que no es posible
 * por ello queda demostrado que la estrategia elegida es óptima
 */
int maxArchivos(int** archivos,int* capacidadRestante,int izq,int der){
    //Buscamos un valor válido con los conjuntos disjuntos
    int busca = izq;
    while(!archivos[0][busca] && busca <= der){
        busca++;
    }
    //Una vez encontrado un valor que no haya sido usado empezamos a comparar con el de base
    for(int i = busca + 1; i <= der;++i){
        if(archivos[0][i]){
            busca = archivos[1][i] < archivos[1][busca]? i : busca;
        }
    }
    //Comprobamos que el primer bucle no haya hecho que se paso lo cual significaría que todos han sido usados
    if(busca <= der){
        if(*capacidadRestante >= archivos[1][busca]){
            *capacidadRestante-= archivos[1][busca];
            archivos[0][busca] = 0;
            printf("Se ha añadido el archivo %d con tamanio %d\n",busca,archivos[1][busca]);
            return 1;
        }
        printf("Capacidad insuficiente terminando\n");
        return 0;
    }
    printf("Ya se han agregado todos los elementos posibles terminando\n");
    return 0;
}
/*
 * Segundo algoritmo
 * Demostración:
 * La estrategia seguida para maximizar el espacio utilizado en disco consiste en introducir siempre
 * los archivos de mayor almacenamiento necesario que aún cojan en el disco
 * Para demostrar que esto es un algorítmo que obtiene solución óptima vamos a utilizar redución al absurdo
 * Asumamos que nuestra solución no es optima eso sígnifica que existe un conjunto c' tal que
 * contiene un A' ∈ Archivos que cubre la diferencia ya sea más chico o más grande
 * En el caso de que fuera un valor más chico que el menor eso diría que el conjunto aún podía contener
 * un valor y no lo ha seleccionado lo cual es contrario al funcionamiento descrito lo no es factible
 * Por otro lado si fuera un valor mayor el que no haya sido seleccionado nos encontraríamos con la misma tesitura anterior
 * por ello estos dos casos no son posibles por ello es óptimo
 */
int maxAlmacenamiento(int** archivos,int* capacidadRestante,int izq,int der){
    //Buscamos un valor válido con los conjuntos disjuntos
    int busca = izq;
    while(!archivos[0][busca] && busca <= der){
        busca++;
    }
    //Una vez encontrado un valor que no haya sido usado empezamos a comparar con el de base
    for(int i = busca + 1; i <= der;++i){
        if(archivos[0][i]){
            busca = archivos[1][i] > archivos[1][busca]? i : busca;
        }
    }
    //Comprobamos que el primer bucle no haya hecho que se paso lo cual significaría que todos han sido usados
    if(busca <= der){
        if(*capacidadRestante >= archivos[1][busca]){
            *capacidadRestante-= archivos[1][busca];
            printf("Se ha añadido el archivo %d con tamanio %d\n",busca,archivos[1][busca]);
        }
        archivos[0][busca] = 0;
        return 1;
    }
    printf("Ya se han agregado todos los elementos posibles terminando\n");
    return 0;
}
int main() {
    srand(28);
    int capacidadRestante = TAM_DISCO;
    int **archivos = malloc(2*sizeof (int*));
    archivos[0] = malloc(NUM_ARCHIVOS * sizeof (int));
    archivos[1] = malloc(NUM_ARCHIVOS * sizeof (int));
    for(int i = 0; i < NUM_ARCHIVOS; ++i){
        archivos[0][i] = 1;
        archivos[1][i] = rand() % 500 + 20;
    }
    for(int i = 0; i < NUM_ARCHIVOS; ++i){
        printf("%d ",archivos[1][i]);
    }
    printf("\n");
    while(maxArchivos(archivos,&capacidadRestante,0,NUM_ARCHIVOS - 1));
    for(int i = 0; i < NUM_ARCHIVOS; ++i){
        archivos[0][i] = 1;
    }
    capacidadRestante = TAM_DISCO;
    while(maxAlmacenamiento(archivos,&capacidadRestante,0,NUM_ARCHIVOS - 1));
}
