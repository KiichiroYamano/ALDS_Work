#include<cstdio>
#include<cmath>
using namespace std;

int cmp_counter = 0;

void merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1 + 1], R[n2 + 1];
    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i_left = 0;
    int i_right = 0;
    for (int i = left; i < right; i++)
    {
        if(L[i_left] <= R[i_right])
        {
            A[i] = L[i_left];
            i_left++;
            cmp_counter++;
        }
        else
        {
            A[i] = R[i_right];
            i_right++;
            cmp_counter++;
        }
    }
}

void mergeSort(int A[], int left, int right)
{
    if(left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A,left, mid, right);
    }
}

int main()
{
    int n, A[500000] = {};

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    mergeSort(A, 0, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n%d\n", cmp_counter);
    
    return 0;
}

