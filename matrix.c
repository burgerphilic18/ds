#include <stdio.h>
#define SIZE 10

void read(int a[SIZE][SIZE], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
}

void print(int a[SIZE][SIZE], int r, int c) {
    for (int i = 0; i < r; i++, printf("\n"))
        for (int j = 0; j < c; j++)
            printf("%d ", a[i][j]);
}

void add(int a[SIZE][SIZE], int b[SIZE][SIZE], int r, int c) {
    int res[SIZE][SIZE];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            res[i][j] = a[i][j] + b[i][j];
    printf("Addition:\n");
    print(res, r, c);
}

void sub(int a[SIZE][SIZE], int b[SIZE][SIZE], int r, int c) {
    int res[SIZE][SIZE];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            res[i][j] = a[i][j] - b[i][j];
    printf("Subtraction:\n");
    print(res, r, c);
}

void mul(int a[SIZE][SIZE], int b[SIZE][SIZE], int r1, int c1, int c2) {
    int res[SIZE][SIZE] = {0};
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                res[i][j] += a[i][k] * b[k][j];
    printf("Multiplication:\n");
    print(res, r1, c2);
}

int main() {
    int a[SIZE][SIZE], b[SIZE][SIZE], r1, c1, r2, c2;
    printf("Enter size of Matrix A: ");
    scanf("%d%d", &r1, &c1);
    printf("Enter Matrix A:\n");
    read(a, r1, c1);

    printf("Enter size of Matrix B: ");
    scanf("%d%d", &r2, &c2);
    printf("Enter Matrix B:\n");
    read(b, r2, c2);

    if (r1 == r2 && c1 == c2) {
        add(a, b, r1, c1);
        sub(a, b, r1, c1);
    } else {
        printf("Addition/Subtraction not possible\n");
    }

    if (c1 == r2)
        mul(a, b, r1, c1, c2);
    else
        printf("Multiplication not possible\n");

    return 0;
}