#include<cstdio>
#include<iostream>
using namespace std;

int partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if(A[j] <= x)
        {
            i = i + 1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);

    return i + 1;
}

int main()
{
    int n;
    int A[100000] = {};
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    
    int partitionIndex = partition(A, 0, n - 1);

    if(partitionIndex == 0)
    {
        printf("[%d]", A[0]);
    }
    else
    {
        printf("%d", A[0]);
    }
    for (int i = 1; i < n; i++)
    {
        if(i == partitionIndex)
        {
            printf(" [%d]", A[i]);
        }
        else
        {
            printf(" %d", A[i]);
        }
    }
    printf("\n");

    return 0;
}

