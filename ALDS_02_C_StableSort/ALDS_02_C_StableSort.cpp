#include<iostream>
using namespace std;
struct Card{char suit, value;};
void outCardArray(struct Card  A[], int n);
int selectionSort(struct Card  A[], int n);
int bubbleSort(struct Card  A[], int n);
bool isStable(struct Card in[], struct Card out[], int n);

int main()
{
    int n;
    struct Card C1[100]={};
    struct Card C2[100]={};
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> C1[i].suit >> C1[i].value;
    }
    for (int i = 0; i < n; i++) C2[i] = C1[i];
    
    bubbleSort(C1, n);
    outCardArray(C1, n);
    cout << "Stable" << endl;
    selectionSort(C2, n);
    outCardArray(C2, n);
    if(isStable(C1, C2, n))
    {
        cout << "Stable" << endl;
    }
    else
    {
        cout << "Not stable" << endl;
    }

    return 0;
}

int bubbleSort(struct Card A[], int n)
{
    bool flag = true;
    int temp = 0;
    int counter = 0;
    while(flag)
    {
        flag = false;
        for (int i = n - 1 ; i > 0; i--)
        {
            if(A[i].value < A[i - 1].value)
            {
                swap(A[i],A[i - 1]);
                flag = true;
                counter++;
            }
        }
    }
    return counter;
}

int selectionSort(struct Card A[], int n)
{
    int counter =0;
    if( A != nullptr) 
    {
        for (int i = 0; i < n; i++)
        {
            int minj = i;
            for (int j = i; j < n; j++)
            {
                if(A[j].value < A[minj].value) minj = j; 
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

void outCardArray(struct Card A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << A[i].suit << A[i].value << " ";
    }
    cout << A[n -1].suit << A[n - 1].value << endl;
}

bool isStable(struct Card in[], struct Card out[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if(in[i].suit != out[i].suit) return false;
    }
    return true;
}