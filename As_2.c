#include <stdio.h>

void mat_accept(int a[20][20], int r, int c)
{
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void mat_print(int a[20][20], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void compact(int a[20][20], int r, int c, int cp[20][3])
{
    int k = 1;

    cp[0][0] = r;
    cp[0][1] = c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                cp[k][0] = i;
                cp[k][1] = j;
                cp[k][2] = a[i][j];
                k++;
            }
        }
    }

    cp[0][2] = k - 1;
}

void Transpose(int b[][3], int c[][3])
{
    int m = b[0][0];
    int n = b[0][1];
    int t = b[0][2];

    c[0][0] = n;
    c[0][1] = m;
    c[0][2] = t;

    if (t <= 0)
        return;

    int q = 1;

    for (int col = 0; col < n; col++)
    {
        for (int p = 1; p <= t; p++)
        {
            if (b[p][1] == col)
            {
                c[q][0] = b[p][1];
                c[q][1] = b[p][0];
                c[q][2] = b[p][2];
                q++;
            }
        }
    }
}

void Fast_Transpose(int b[][3], int d[][3])
{
    int n = b[0][1];
    int t = b[0][2];

    d[0][0] = b[0][1];
    d[0][1] = b[0][0];
    d[0][2] = t;

    if (t <= 0)
        return;

    int S[20] = {0};
    int T[20];

    for (int i = 1; i <= t; i++)
    {
        S[b[i][1]]++;
    }

    T[0] = 1;

    for (int i = 1; i < n; i++)
    {
        T[i] = T[i - 1] + S[i - 1];
    }

    for (int i = 1; i <= t; i++)
    {
        int j = b[i][1];

        d[T[j]][0] = b[i][1];
        d[T[j]][1] = b[i][0];
        d[T[j]][2] = b[i][2];

        T[j]++;
    }
}

int main()
{
    int a[20][20];
    int cp[20][3];
    int tran[20][3];
    int r, c;
    int cho;

    printf("Enter rows and columns of matrix:\n");
    scanf("%d %d", &r, &c);

    mat_accept(a, r, c);

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Display Original Matrix\n");
        printf("2. Display Compact Form\n");
        printf("3. Simple Transpose\n");
        printf("4. Fast Transpose\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &cho);

        switch (cho)
        {
        case 1:
            printf("\nOriginal Matrix:\n");
            mat_print(a, r, c);
            break;

        case 2:
            compact(a, r, c, cp);
            printf("\nCompact Form:\n");
            mat_print((int (*)[20])cp, cp[0][2] + 1, 3);
            break;

        case 3:
            compact(a, r, c, cp);
            Transpose(cp, tran);
            printf("\nSimple Transpose:\n");
            mat_print((int (*)[20])tran, tran[0][2] + 1, 3);
            break;

        case 4:
            compact(a, r, c, cp);
            Fast_Transpose(cp, tran);
            printf("\nFast Transpose:\n");
            mat_print((int (*)[20])tran, tran[0][2] + 1, 3);
            break;

        case 5:
            printf("Program terminated.\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (cho != 5);

    return 0;
}