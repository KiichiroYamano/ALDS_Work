#include<cstdio>

void CountingSort(int A[], int B[], int C[], int k, int n)
{
    for (int i = 0; i < k; i++) C[i] = 0;

    for (int i = 1; i <= n; i++) C[A[i]]++;

    for (int i = 1; i <= k; i++) C[i] = C[i] + C[i - 1];
    
    for (int i = n; i >= 1; i--)
    {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
}

int main()
{
    int n, A[2000001], B[2000001], C[2000001];

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &A[i]);
    }

    CountingSort(A, B, C, 2000000, n);

    for (int i = 1; i <= n - 1; i++)
    {
        printf("%d ", B[i]);
    }
    printf("%d\n", B[n]);
    
    return 0;
}

