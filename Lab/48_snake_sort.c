#include <stdio.h>

int N;

void sortRow(int Mat[][N], int i)
{
	int j;
    for (j = 1; j < N; j++)
    {
        int k = j - 1;
        int temp = Mat[i][j];

        while (k >= 0 && Mat[i][k] > temp)
        {
            Mat[i][k + 1] = Mat[i][k];
            k -= 1;
        }
        Mat[i][k + 1] = temp;
    }
}

void descendingSortRow(int Mat[][N], int i)
{
	int j;
    for (j = 1; j < N; j++)
    {
        int k = j - 1;
        int temp = Mat[i][j];

        while (k >= 0 && Mat[i][k] < temp)
        {
            Mat[i][k + 1] = Mat[i][k];
            k -= 1;
        }
        Mat[i][k + 1] = temp;
    }
}

void sortColumn(int Mat[][N])
{
	int i,j;
    for (i = 0; i < N; i++)
    {
        for (j = 1; j < N; j++)
        {
            int k = j - 1;
            int temp = Mat[j][i];

            while (k >= 0 && Mat[k][i] > temp)
            {
                Mat[k + 1][i] = Mat[k][i];
                k -= 1;
            }
            Mat[k + 1][i] = temp;
        }
    }
}

void show(int Mat[][N])
{
	int i,j;
    printf("\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%d  ", Mat[i][j]);

        printf("\n");
    }
}

void Solve()
{
    N = 4;
    int Mat[N][N],i,j;
    printf("Enter Matrix\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            scanf("%d", &Mat[i][j]);
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {

            if (j % 2 == 0)
                sortRow(Mat, j);
            else
                descendingSortRow(Mat, j);
        }
        show(Mat);
        sortColumn(Mat);
        show(Mat);
    }
}

void main()
{
    Solve();
    getch();
}
