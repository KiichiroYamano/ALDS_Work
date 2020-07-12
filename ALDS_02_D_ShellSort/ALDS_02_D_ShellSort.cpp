#include<iostream>
#include<vector>
using namespace std;
void outIntArray(int A[], int n);
void outIntVector(vector<int> A);
int insertionSort(int A[], int n, int g);
int shellSort(int A[], int n, int& m, vector<int>& G);

int main()
{
    int n,A[1000000]={};
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int m = 0;
    vector<int> G = {};
    int swapCnt = shellSort(A, n, m, G);
    cout << m << endl;
    outIntVector(G);
    cout << swapCnt << endl;
    outIntArray(A, n);

    return 0;
}

int insertionSort(int A[], int n, int g)
{
    int cnt = 0;
    if(A != nullptr)
    {
        int v,j;
        for (int i = g; i < n; i++)
        {
            v = A[i];
            j = i - g;
            while(j >= 0 && A[j] >v)
            {
                A[j + g] = A[j];
                j = j - g;
                cnt++;
            }
            A[j + g] = v;
        }
    }
    return cnt;
}

int shellSort(int A[], int n, int& m, vector<int>& G)
{
    int cnt = 0;
    if(A != nullptr)
    {
        // G = {1, 4, 13, 40, 121...} => O(N^1,25)
        for (int h = 1; ; )
        {
            if(h > n) break;
            G.push_back(h);
            h = 3 * h + 1;
        }
        m = G.size();

        for (int i = G.size() - 1; i >= 0; i--)
        {
            cnt += insertionSort(A, n, G[i]);
        }
    }
    return cnt;
}

void outIntArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
}

void outIntVector(vector<int> A)
{
    for (int i = A.size() - 1; i > 0; i--)
    {
        cout << A[i] << " ";
    }
    cout << A[0] << endl;
}