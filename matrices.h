#ifndef MATRIZ
#define MATRIZ

void mostrarMatriz(int **,int ,int);

void rellenarMatriz(int **,int ,int);

int** reservarMatriz(int, int);

void liberarMatriz(int** , int);

void verDiagonalPrincipal(int **, int , int);

int** devolverTraspuesta(int **, int , int);

int** sumarMatrices(int**, int**, int, int);

int** restarMatrices(int**, int**, int, int);

int** multiplicarMatrices(int**, int**, int, int, int);

#endif // MATRIZ
