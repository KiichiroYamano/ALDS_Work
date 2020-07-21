#include<cstdio>
#include<iostream>
using namespace std;

struct Card{char suit; int value;};

void merge(struct Card A[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    struct Card L[n1 + 1], R[n2 + 1];
    for (int i = 0; i < n1; i++)
    {
        L[i].value = A[left + i].value;
        L[i].suit = A[left + i].suit;
    }
    for (int i = 0; i < n2; i++)
    {
        R[i].value = A[mid + i].value;
        R[i].suit = A[mid + i].suit;
    }
    L[n1].value = 2147483647;
    R[n2].value = 2147483647;

    int i_left = 0;
    int i_right = 0;
    for (int i = left; i < right; i++)
    {
        if(L[i_left].value <= R[i_right].value)
        {
            A[i].value = L[i_left].value;
            A[i].suit = L[i_left].suit;
            i_left++;
        }
        else
        {
            A[i].value = R[i_right].value;
            A[i].suit = R[i_right].suit;
            i_right++;
        }
    }
}

void mergeSort(struct Card A[], int left, int right)
{
    if(left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A,left, mid, right);
    }
}

int partition(struct Card A[], int p, int r)
{
    struct Card x;
    x = A[r];
    int i = p - 1;
    struct Card temp;
    for (int j = p; j < r; j++)
    {
        if(A[j].value <= x.value)
        {
            i = i + 1;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;

    return i + 1;
}

void quickSort(struct Card A[], int p, int r)
{
    if(p < r)
    {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main()
{
    int n;
    struct Card A[100000];
    struct Card B[100000];
    scanf("%d", &n);
    
    char s[10];
    int v;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", s, &v);
        A[i].suit = B[i].suit = s[0];
        A[i].value = B[i].value = v;
    }
    
    quickSort(A, 0, n-1);
    mergeSort(B, 0, n);

    bool stable = true;
    for (int i = 0; i < n; i++)
    {
        if(A[i].suit != B[i].suit) 
        {
            stable = false;
            break;
        }
    }

    if(stable) printf("Stable\n");
    else printf("Not stable\n");

    for (int i = 0; i < n; i++)
    {
        printf("%c %d\n", A[i].suit, A[i].value);
    }
    
    return 0;
}

