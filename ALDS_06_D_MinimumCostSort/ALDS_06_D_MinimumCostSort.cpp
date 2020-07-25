#include<cstdio>
#include<algorithm>
using namespace std;

int minimumCost(int A[], int n, int min_all)
{
    int ret = 0, min_local;
    int B[1000], T[10001]={};
    bool V[1000];

    for (int i = 0; i < n; i++)
    {
        B[i] = A[i];
        V[i] = false;
    }
    
    sort(B, B+n);

    for (int i = 0; i < n; i++) T[B[i]] = i;

    for (int i = 0; i < n; i++)
    {
        if(V[i]) continue;
        min_local = 10000;
        int cur = i;
        int n_cycle = 0;
        int sum_local = 0;
        while(1)
        {
            V[cur] = true;
            int v = A[cur];
            min_local = min(v, min_local);
            n_cycle++;
            sum_local += v;
            cur = T[v];
            if(V[cur]) break;
        }
        ret += min(sum_local + (n_cycle - 2) * min_local, sum_local + min_local + (n_cycle + 1) * min_all);
    }
    return ret;
}

int main()
{
    int n,min_all=10000, A[1000] = {};

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
        min_all = min(min_all, A[i]);   
    }

    int ans = minimumCost(A, n, min_all);

    printf("%d\n", ans);
    
    return 0;
}

