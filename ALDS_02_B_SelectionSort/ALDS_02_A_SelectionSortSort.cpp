#include<iostream>
using namespace std;
void outIntArray(int A[], int n);
int selectionSort(int A[], int n);

int main()
{
    int n,A[100]={};
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int countSwap = selectionSort(A, n);
    outIntArray(A, n);
    cout << countSwap << endl;

    return 0;
}

int selectionSort(int A[], int n)
{
    int counter =0;
    if( A != nullptr) 
    {
        for (int i = 0; i < n; i++)
        {
            int minj = i;
            for (int j = i; j < n; j++)
            {
                if(A[j] < A[minj]) minj = j; 
            }
            if(i != minj)
            {
                swap(A[i],A[minj]);
                counter++;
            }
        }
    }
    
    return counter;
}

void outIntArray(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << A[i] << " ";
    }
    cout << A[n -1] << endl;
}
