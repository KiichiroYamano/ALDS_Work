#include<cstdio>
using namespace std;

int binarySearch(int A[], int n, int key)
{
    int left = 0;
    int right = n;

    int mid;
    while(left < right)
    {
        mid = (left + right) / 2;
        if(A[mid] == key)
            return 1;
        else if(key < A[mid])
            right = mid;
        else
            left = mid + 1;
    }
    return 0;
}

int main()
{
    int n,q,key,result=0;
    int S[100000] = {};
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &S[i]);
    
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &key);
        if(binarySearch(S, n, key)) result++;
    }
    printf("%d\n", result);

    return 0;
}

