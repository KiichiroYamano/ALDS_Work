#include<cstdio>
using namespace std;

int linearSearch(int A[], int n, int key)
{
    int i = 0;
    A[n] = key;
    while(A[i] != key) i++;
    return i != n;
}

int main()
{
    int n,q,key,result=0;
    int S[10001] = {};
    
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &S[i]);
    
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &key);
        if(linearSearch(S, n, key)) result++;
    }
    printf("%d\n", result);

    return 0;
}

