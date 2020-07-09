#include<iostream>
using namespace std;

int main()
{
    int n;
    long R[200000];

    cin >> n;
    for (int  i = 0; i < n; i++)
    {
        cin >> R[i];
    }
    
    long temp_value;
    long min_val = R[0];
    long max_val = R[1] - R[0];
    for (int i = 1; i < n; i++)
    {   
        if(max_val < R[i] -min_val) max_val = R[i] -min_val;
        if(min_val > R[i]) min_val = R[i];
    }
    cout << max_val << endl;

    return 0;
}