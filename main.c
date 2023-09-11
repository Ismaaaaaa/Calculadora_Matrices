#include <stdio.h>
#include "matrices.h"

int main(){

    int filasPrimera = 3, colsPrimera = 3, filasSegunda = 3, colsSegunda = 3;

    printf("Introduzca el número de filas de la matriz: ");
    scanf("%d",&filasPrimera);

    printf("Introduzca el número de columnas de la matriz: ");
    scanf("%d",&colsPrimera);

    int **matrizPrimera = reservarMatriz(filasPrimera, colsPrimera);

    printf("Rellenando la primera matriz\n");

    rellenarMatriz(matrizPrimera, filasPrimera, colsPrimera);

    int **matrizSegunda = NULL;

    int **matrizResultado = NULL;

    int opcion = 0;
    do{
        printf("\n[1] Ver diagonal principal\n");
        printf("[2] Ver traspuesta\n");
        printf("[3] Sumar matrices\n");
        printf("[4] Restar matrices\n");
        printf("[5] Multiplicar matrices\n");
        printf("[0] Salir del programa\n");
        printf("Introduzca una opción: ");
        scanf("%d", &opcion);

        if(opcion >= 3){
                printf("Creando la segunda matriz\n");
                printf("Introduzca el número de filas de la matriz: ");
                scanf("%d",&filasSegunda);

                printf("Introduzca el número de columnas de la matriz: ");
                scanf("%d",&colsSegunda);

                matrizSegunda = reservarMatriz(filasSegunda, colsSegunda);
                mostrarMatriz(matrizSegunda,filasSegunda, colsSegunda);
                rellenarMatriz(matrizSegunda, filasSegunda, colsSegunda);
        }

        switch(opcion){
            case 1:
                verDiagonalPrincipal(matrizPrimera, filasPrimera, colsPrimera);
                break;
            case 2:
                int **traspuesta = devolverTraspuesta(matrizPrimera, filasPrimera, colsPrimera);
                mostrarMatriz(traspuesta, colsPrimera, filasPrimera);
                liberarMatriz(traspuesta,colsPrimera);
                break;
            case 3:
                if(filasPrimera == filasSegunda && colsPrimera == colsSegunda){
                    matrizResultado = sumarMatrices(matrizPrimera, matrizSegunda, filasPrimera, colsPrimera);
                    printf("\nEl resultado de la suma es:\n");
                    mostrarMatriz(matrizResultado, filasPrimera, colsPrimera);
                    liberarMatriz(matrizResultado, filasPrimera);
                } else {
                    printf("\nNo se pueden sumar matrices con diferente número de filas y columnas");
                }
                liberarMatriz(matrizSegunda,filasSegunda);
                break;
            case 4:
                if(filasPrimera == filasSegunda && colsPrimera == colsSegunda){
                    matrizResultado = restarMatrices(matrizPrimera, matrizSegunda, filasPrimera, colsPrimera);
                    printf("\nEl resultado de la resta es:\n");
                    mostrarMatriz(matrizResultado, filasPrimera, colsPrimera);
                    liberarMatriz(matrizResultado, filasPrimera);
                } else {
                    printf("\nNo se pueden restar matrices con diferente número de filas y columnas");
                }
                liberarMatriz(matrizSegunda,filasSegunda);
                break;
            case 5:
                if(colsPrimera == filasSegunda){
                    matrizResultado = multiplicarMatrices(matrizPrimera, matrizSegunda, colsPrimera, filasPrimera, colsSegunda);
                    printf("\nEl resultado de la multiplicación es:\n");
                    mostrarMatriz(matrizResultado, filasPrimera, colsSegunda);
                    liberarMatriz(matrizResultado, filasPrimera);
                } else {
                    printf("No se puede multiplicar una matriz de %dx%d con una matriz de %dx%d", filasPrimera, colsPrimera, filasSegunda, colsSegunda);
                }
                liberarMatriz(matrizSegunda,filasSegunda);
                break;
            default:
                break;
        };
    }while(opcion != 0);

    liberarMatriz(matrizPrimera, filasPrimera);

    return 0;
}
