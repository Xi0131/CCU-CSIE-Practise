#include<stdio.h>

void sym(), multiply();

int main()
{
    int M;
    printf("What is the size of the matrix: ");
    scanf("%d", &M);
    int arr[M][M];
    printf("Please enter the matrix: ");
    for(int i = 0; i < M; ++i)
        for(int j = 0; j < M; ++j)
            scanf("%d", &arr[j][i]);
    for(int i = 0; i < M; ++i)
        for(int j = M-1; j >= 0; --j)
            printf("%d ", arr[i][j]);
    printf("\n");

    int t;
    printf("Enter the number of input data: ");
    scanf("%d", &t);
    for(int i = 0; i < t; ++i)
        sym();

    printf("Enter the number of input data: ");
    scanf("%d", &t);
    for(int i = 0; i < t; ++i)
        multiply();

    return 0;
}

void sym()
{
    int m;
    printf("What is the size of the matrix: ");
    scanf("%d", &m);
    int arr[m][m];
    int negative = 0;
    printf("Please enter the matrix: ");
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            scanf("%d", &arr[j][i]);
            if(arr[j][i] < 0) negative = 1;
        }
    }
    if(negative == 1)
    {
        printf("The matrix is not symmetric!\n");
        return;
    }

    if(arr[0][0] != arr[2][2] || arr[0][1] != arr[2][1] || arr[0][2] != arr[2][0] || arr[1][0] != arr[1][2])
    {
        printf("The matrix is not symmetric!\n");
        return;
    }
    printf("The matrix is symmetric!\n");
}

void multiply()
{
    int m;
    printf("What is the size of the matrix: ");
    scanf("%d", &m);
    int arr1[m][m], arr2[m][m];
    printf("the first matrix: ");
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j)
            scanf("%d", &arr1[i][j]);
    printf("the second matrix: ");
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j)
            scanf("%d", &arr2[i][j]);

    int arr_ans[m][m];
    int sum = 0;
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < m; j++)
        {
            for(int k = 0; k < m; k++)
            {
                sum += arr1[j][k] * arr2[k][i];
            }
            arr_ans[j][i] = sum;
            sum = 0;
        }
    }

    for(int *p = &arr_ans[0][0]; p <= &arr_ans[m-1][m-1]; p++)
        printf("%d ", *p);
    printf("\n");
}