
#include <stdio.h>

#define MAX 10

/* Function Prototypes */
void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void displayMatrix(int matrix[MAX][MAX], int rows, int cols);

void addMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX],
                 int result[MAX][MAX], int rows, int cols);

void multiplyMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX],
                      int result[MAX][MAX], int rows1, int cols1,
                      int rows2, int cols2);

void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX],
                     int rows, int cols);

int isValidDimension(int rows, int cols);


/* Main Function */
int main() {
    int choice;

    do {
        printf("\n===== MATRIX OPERATIONS =====\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        /* Matrix Addition */
        if (choice == 1) {
            int matrix1[MAX][MAX];
            int matrix2[MAX][MAX];
            int result[MAX][MAX];
            int rows, cols;

            printf("\nEnter number of rows: ");
            scanf("%d", &rows);

            printf("Enter number of columns: ");
            scanf("%d", &cols);

            if (!isValidDimension(rows, cols)) {
                printf("\nInvalid matrix dimensions.\n");
                printf("Rows and columns must be between 1 and %d.\n", MAX);
                continue;
            }

            printf("\nEnter elements of Matrix 1:\n");
            inputMatrix(matrix1, rows, cols);

            printf("\nEnter elements of Matrix 2:\n");
            inputMatrix(matrix2, rows, cols);

            addMatrices(matrix1, matrix2, result, rows, cols);

            printf("\nMatrix 1:\n");
            displayMatrix(matrix1, rows, cols);

            printf("\nMatrix 2:\n");
            displayMatrix(matrix2, rows, cols);

            printf("\nResult of Addition:\n");
            displayMatrix(result, rows, cols);
        }

        /* Matrix Multiplication */
        else if (choice == 2) {
            int matrix1[MAX][MAX];
            int matrix2[MAX][MAX];
            int result[MAX][MAX];

            int rows1, cols1;
            int rows2, cols2;

            printf("\nEnter rows of Matrix 1: ");
            scanf("%d", &rows1);

            printf("Enter columns of Matrix 1: ");
            scanf("%d", &cols1);

            printf("\nEnter rows of Matrix 2: ");
            scanf("%d", &rows2);

            printf("Enter columns of Matrix 2: ");
            scanf("%d", &cols2);

            /* Validate dimensions */
            if (!isValidDimension(rows1, cols1) ||
                !isValidDimension(rows2, cols2)) {

                printf("\nInvalid matrix dimensions.\n");
                printf("Rows and columns must be between 1 and %d.\n", MAX);
                continue;
            }

            /* Check multiplication compatibility */
            if (cols1 != rows2) {
                printf("\nMatrix multiplication is not possible.\n");
                printf("Columns of Matrix 1 must equal rows of Matrix 2.\n");
                continue;
            }

            printf("\nEnter elements of Matrix 1:\n");
            inputMatrix(matrix1, rows1, cols1);

            printf("\nEnter elements of Matrix 2:\n");
            inputMatrix(matrix2, rows2, cols2);

            multiplyMatrices(
                matrix1,
                matrix2,
                result,
                rows1,
                cols1,
                rows2,
                cols2
            );

            printf("\nMatrix 1:\n");
            displayMatrix(matrix1, rows1, cols1);

            printf("\nMatrix 2:\n");
            displayMatrix(matrix2, rows2, cols2);

            printf("\nResult of Multiplication:\n");
            displayMatrix(result, rows1, cols2);
        }

        /* Matrix Transpose */
        else if (choice == 3) {
            int matrix[MAX][MAX];
            int result[MAX][MAX];

            int rows, cols;

            printf("\nEnter number of rows: ");
            scanf("%d", &rows);

            printf("Enter number of columns: ");
            scanf("%d", &cols);

            if (!isValidDimension(rows, cols)) {
                printf("\nInvalid matrix dimensions.\n");
                printf("Rows and columns must be between 1 and %d.\n", MAX);
                continue;
            }

            printf("\nEnter matrix elements:\n");
            inputMatrix(matrix, rows, cols);

            transposeMatrix(matrix, result, rows, cols);

            printf("\nOriginal Matrix:\n");
            displayMatrix(matrix, rows, cols);

            printf("\nTranspose of Matrix:\n");
            displayMatrix(result, cols, rows);
        }

        /* Exit */
        else if (choice == 4) {
            printf("\nThank you for using Matrix Operations!\n");
        }

        /* Invalid Menu Choice */
        else {
            printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}


/* Input Matrix */
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}


/* Display Matrix */
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }

        printf("\n");
    }
}


/* Matrix Addition */
void addMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX],
                 int result[MAX][MAX], int rows, int cols) {

    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}


/* Matrix Multiplication */
void multiplyMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX],
                      int result[MAX][MAX], int rows1, int cols1,
                      int rows2, int cols2) {

    int i, j, k;

    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {

            result[i][j] = 0;

            for (k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}


/* Matrix Transpose */
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX],
                     int rows, int cols) {

    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}


/* Validate Matrix Dimensions */
int isValidDimension(int rows, int cols) {
    return rows > 0 &&
           rows <= MAX &&
           cols > 0 &&
           cols <= MAX;
}

