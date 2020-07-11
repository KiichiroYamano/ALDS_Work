#include<iostream>
using namespace std;
void outIntArray(int A[], int n);
int selectionSort(int A[], int n);
int bubbleSort(int A[], int n);

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

int bubbleSort(int A[], int n)
{
    bool flag = true;
    int temp = 0;
    int counter = 0;
    while(flag)
    {
        flag = false;
        for (int i = n - 1 ; i > 0; i--)
        {
            if(A[i] < A[i - 1])
            {
                swap(A[i],A[i - 1]);
                flag = true;
                counter++;
            }
        }
    }
    return counter;
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
