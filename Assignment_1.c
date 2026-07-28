#include <stdio.h>

void mat_accept(int m1[20][20], int r1, int c1) {
    printf("Enter the matrix elements:\n"); 
    for(int i = 0; i < r1; i++) 
    {
        for(int j = 0; j < c1; j++) 
        {
            scanf("%d", &m1[i][j]); 
        }
    }
}

void mat_print(int m2[20][20], int r2, int c2)
 {
    for(int i = 0; i < r2; i++) 
    {
        for(int j = 0; j < c2; j++)
        {
            printf("%d\t", m2[i][j]);
        }
        printf("\n"); 
    }
}


void add(int m1[20][20], int m2[20][20], int res[20][20], int r1, int r2, int c1, int c2)
 {
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c1; j++) 
        {
            res[i][j] = m1[i][j] + m2[i][j];
        }
    }
    printf("\nResult Matrix:\n");
    mat_print(res, r1, c1);
}

void sub(int m1[20][20], int m2[20][20], int res[20][20], int r1, int r2, int c1, int c2) 
{
    for(int i = 0; i < r1; i++) 
    {
        for(int j = 0; j < c1; j++) 
        {
            res[i][j] = m1[i][j] - m2[i][j];
        }
    }
    printf("\nResult Matrix:\n");
    mat_print(res, r1, c1);
}

void mult(int m1[20][20], int m2[20][20], int res[20][20], int r1, int c1, int c2) 
{
    for(int i = 0; i < r1; i++) 
    {
        for(int j = 0; j < c2; j++) 
        {
            res[i][j] = 0;
            for(int k = 0; k < c1; k++) 
            {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    printf("\nResult Matrix:\n");
    mat_print(res, r1, c2);
}


void transpose(int m[20][20], int res[20][20], int r, int c) 
{
    for(int i = 0; i < r; i++) 
    {
        for(int j = 0; j < c; j++) 
        {
            res[j][i] = m[i][j];
        }
    }
    printf("\nResult Transpose Matrix:\n");
    mat_print(res, c, r); 
}

int main() 
{
    int m1[20][20];
    int m2[20][20];
    int res[20][20];
    int r1, r2, c1, c2;
    int c;

    printf("Select operation of matrix:\n");


    printf("1:Add\n2:sub\n3:mult\n4:transpose\n");


    printf("Enter Selected operation:\n");
    scanf("%d", &c); 

    if (c == 4) 
    {
        printf("Enter row and col for Matrix:\n");
        scanf("%d %d", &r1, &c1);
        mat_accept(m1, r1, c1);
    } 
    else 
    {
        printf("enter row and cal for mat 1\n");
        scanf("%d %d", &r1, &c1);
        mat_accept(m1, r1, c1);

        printf("enter row and cal for mat 2 same as mat 1\n");
        scanf("%d %d", &r2, &c2);
        mat_accept(m2, r2, c2);
    }

    switch (c) 
    {
        case 1:
            if(r1 == r2 && c1 == c2)
            {
                 add(m1, m2, res, r1, r2, c1, c2);
            }
            else 
            {
                printf("Error: Size mismatch for addition!\n");
            }
            break;
        case 2:
            if(r1 == r2 && c1 == c2) 
            { 
                sub(m1, m2, res, r1, r2, c1, c2);
            }
            else
            {
                 printf("Error: Size mismatch for subtraction!\n");
            }
            break;
        case 3:
            if(c1 == r2) 
            {
                mult(m1, m2, res, r1, c1, c2);
            }
            else
            {
                 printf("Error: Outer sizes must match for multiplication (c1 must equal r2)!\n");
            }
            break;
        case 4:
            transpose(m1, res, r1, c1);
            break;
        default:
            printf("Invalid Option Selected\n");
            break;
    }
    return 0;
}
