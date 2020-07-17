#include<cstdio>
using namespace std;

//[argument] p1:Maximum amount that truck can load, w[]:weight of cargos, n:number of cargos, numOfTruck:number of trucks
//[return] number of cargos which can be transported
int countCargo(int pmax, int w[], int n, int numOfTruck) 
{
    int i, countPack = 0, p = 0, countTruck = 0;

    for (i = 0; i < n; i++)
    {
        if(w[i] > pmax) return 0; // truck cannot load cargo
        
        if((p + w[i]) < pmax)
        {
            p += w[i];
        }
        else if((p + w[i]) > pmax)
        {
            countTruck++;
            if(countTruck == numOfTruck) return i;
            p = w[i];
        }
        else if((p + w[i]) == pmax)
        {
            countTruck++;
            if(countTruck == numOfTruck) return i + 1;
            p = 0;
        }
    }
    
    return n;

}


int main()
{
    int n, k;
    int w[100000] = {};
    
    scanf("%d%d", &n,&k);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }
    
    int left = 0, right = n * 10000, mid, resCountCargo;
    while(left < right)
    {
        mid = (left + right) / 2;
        resCountCargo = countCargo(mid, w, n, k);

        if(resCountCargo == n)
        {
            if(mid == 1) break;
            resCountCargo = countCargo(mid - 1, w, n, k);
            if(resCountCargo < n) break;
            else right = mid;
        }
        else if(resCountCargo < n) left = mid + 1;
    }

    printf("%d\n", mid);

    return 0;
}

