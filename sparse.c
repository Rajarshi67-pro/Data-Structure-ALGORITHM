#include <stdio.h>
#include <stdlib.h>

void convertToNonSparse(int** matrix, int rows, int cols, int* rowIndices, int* colIndices, int* values, int* nonZeroCount) {
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                rowIndices[k] = i;
                colIndices[k] = j;
                values[k] = matrix[i][j];
                k++;
            }
        }
    }
    *nonZeroCount = k;
}

void displayNonSparse(int* rowIndices, int* colIndices, int* values, int nonZeroCount, int rows, int cols) {
    printf("Non-sparse matrix representation:\n");
    printf("%d %d %d\n", rows, cols, nonZeroCount);
    for (int i = 0; i < nonZeroCount; i++) {
        printf("%d %d %d\n", rowIndices[i], colIndices[i], values[i]);
    }
}


int main() {
    int rows, cols, fillValue;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int maxElements = rows * cols;
    int* rowIndices = (int*)malloc(maxElements * sizeof(int));
    int* colIndices = (int*)malloc(maxElements * sizeof(int));
    int* values = (int*)malloc(maxElements * sizeof(int));
    int nonZeroCount = 0;

    convertToNonSparse(matrix, rows, cols, rowIndices, colIndices, values, &nonZeroCount);
    displayNonSparse(rowIndices, colIndices, values, nonZeroCount, rows, cols);
    free(matrix);
    free(rowIndices);
    free(colIndices);
    free(values);

    return 0;
}
