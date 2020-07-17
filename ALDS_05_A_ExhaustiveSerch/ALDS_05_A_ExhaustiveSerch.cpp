#include<cstdio>
using namespace std;

int solve(int A[], int i, int m, int n)
{
    if(m == 0) return true;
    if(i >= n) return false;
    int res = solve(A, i + 1, m, n) || solve(A, i + 1, m- A[i], n);
    return res;
}

int main()
{
    int n, q;
    int A[2000] = {}, m[2000] = {};
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &m[i]);
    }
    
    for (int i = 0; i < q; i++)
    {
        if(solve(A, 0, m[i], n)) printf("yes\n");
        else printf("no\n");
    }
    
    return 0;
}

