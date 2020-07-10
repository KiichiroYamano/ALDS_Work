#include<iostream>
using namespace std;
void outIntArray(int A[], int n);
void insertionSort(int A[], int n);

int main()
{
    int n,A[100]={};
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    outIntArray(A, n);
    insertionSort(A, n);
    
    return 0;
}

void insertionSort(int A[], int n)
{
    if(A != nullptr)
    {
        int v,j;
        for (int i = 1; i < n; i++)
        {
            v = A[i];
            j = i - 1;
            while(j >= 0 && A[j] >v)
            {
                A[j+1] = A[j];
                j--;
            }
            A[j + 1] = v;
            outIntArray(A, n);
        }
    }
}

void outIntArray(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << A[i] << " ";
    }
    cout << A[n -1] << endl;
}
