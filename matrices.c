#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void mostrarMatriz(int **matriz, int filas, int cols){
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < cols; j++){
            printf("%d ", *(*(matriz+i)+j) );
        }
        printf("\n");
    }
}

void rellenarMatriz(int **matriz, int filas, int cols){
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < cols; j++){
            printf("Introduce el valor de la posición [%d][%d]: ",i,j);
            scanf("%d", &matriz[i][j]);
            mostrarMatriz(matriz, filas, cols);
        }
    }
}

int** reservarMatriz(int filas, int cols){

    int **matrizPunteros = (int**) calloc(filas, sizeof(int*));


    for(int i = 0; i < filas; i++){
        matrizPunteros[i] = (int*) calloc(cols, sizeof(int));
    }

    return matrizPunteros;
}

void liberarMatriz(int** matriz, int filas){
    for(int i = 0; i < filas; i++){
        free(matriz[i]);
    }

    free(matriz);
}

void verDiagonalPrincipal(int **matriz, int filas, int cols){
    char tabulaciones[cols];
    char tab = '\t';
    for(int i = 0; i < filas; i++){
        printf("%s%d",tabulaciones,matriz[i][i]);
        strcat(tabulaciones,&tab);
        printf("\n");
    }
}

int** devolverTraspuesta(int **matriz, int filas, int cols){
    int **traspuesta = reservarMatriz(cols, filas);

    for(int i = 0; i < cols; i++){
        for(int j = 0; j < filas; j++){
            traspuesta[i][j] = matriz[j][i];
        }
    }
    return traspuesta;
}


int** sumarMatrices(int **matrizPrimera, int **matrizSegunda, int filas, int cols){
    int **matrizResultado = reservarMatriz(filas, cols);

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < cols; j++){
            matrizResultado[i][j] = (matrizPrimera[i][j] + matrizSegunda[i][j]);
        }
    }
    return matrizResultado;
}

int** restarMatrices(int **matrizPrimera, int **matrizSegunda, int filas, int cols){
    int **matrizResultado = reservarMatriz(filas, cols);

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < cols; j++){
            matrizResultado[i][j] = (matrizPrimera[i][j] - matrizSegunda[i][j]);
        }
    }
    return matrizResultado;
}

int** multiplicarMatrices(int **matrizPrimera, int **matrizSegunda, int colsPrimera_filasSegunda, int filasPrimera, int colsSegunda){
    int **matrizResultado = reservarMatriz(filasPrimera, colsSegunda);

    for(int i = 0; i < filasPrimera; i++){
        for(int j = 0, resultado = 0; j < colsSegunda; j++){
            for(int k = 0; k < colsPrimera_filasSegunda; k++){
                resultado += (matrizPrimera[i][k] * matrizSegunda[k][j]);
            }
            matrizResultado[i][j] = resultado;
            resultado = 0;
        }
    }

    return matrizResultado;
}
