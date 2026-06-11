#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int rows, int cols);
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int r1, int c1, int c2);
void transposeMatrix(int matrix[MAX][MAX], int rows, int cols);

int main ()
{
    int A[MAX][MAX], B[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;

    printf("===== MATRIX OPERATIONS =====\n");

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter elements of Matrix A:\n");
    inputMatrix(A, r1, c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d%d", &r2, &c2);

    printf("Enter elements of Matrix B:\n");
    inputMatrix(B, r2, c2);

    do
    {
        printf("\n==== Matrix Operations ====\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Transpose of Matrix A\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(r1 == r2 && c1 == c2)
                    addMatrices(A, B, r1, c1);
                else
                    printf("Addition not possible!\n");
                break;

            case 2:
                if(c1 == r2)
                    multiplyMatrices(A, B, r1, c1, c2);
                else
                    printf("Multiplication not possible!\n");
                break;

            case 3:
                transposeMatrix(A, r1, c1);
                break;

            case 4:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 0);

    return 0;
}

void inputMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);
}


void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int rows, int cols)
{
    int sum[MAX][MAX];

    printf("\n Result of Addition: \n");

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
            printf("%4d", sum[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int r1, int c1, int c2)
{
    int product[MAX][MAX];

    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            product[i][j] = 0;

            for(int k = 0; k < c1; k++)
                product[i][j] += A[i][k] * B[k][j];
        }
    }

    printf("\n Result of Multiplication: \n");

    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
            printf("%4d", product[i][j]);
        printf("\n");
    }
}

void transposeMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    printf("\n Transpose of Matrix A: \n");

    for(int j = 0; j < cols; j++)
    {
        for(int i = 0; i < rows; i++)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }
}