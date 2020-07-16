#include<cstdio>
#include<cstring>
using namespace std;

#define M 1046527
#define NIL (-1)
#define L 14

int charToNum(char ch)
{
    if(ch == 'A') return 1;
    else if(ch == 'C') return 2;
    else if(ch == 'G') return 3;
    else if(ch == 'T') return 4;
    return 0;
}

long long getKey(char str[])
{
    long long sum = 0, p = 1, i;
    for (int i = 0; i < strlen(str); i++)
    {
        sum += p * charToNum(str[i]);
        p *= 5;
    }
    return sum;
}

class myHash
{
    char mh[M][L];
    
    int h1(int key)
    {
        return key % M;
    }

    int h2(int key)
    {
        return 1 + (key % ( M - 1));
    }

    int hashKey(int key, int i)
    {
        return (h1(key) + i * h2(key)) % M;
    }

    public:
    int find(char val[], int key)
    {
        int h;
        for (int i = 0; ; i++)
        {
            h = hashKey(key, i);
            if(strcmp(mh[h], val) == 0) return 1;
            else if(strlen(mh[h]) == 0) return 0;
        }
        return 0;
    }

    int insert(char val[], int key)
    {
        int h;
        for (int i = 0; ; i++)
        {
            h = hashKey(key, i);
            if(strcmp(mh[h], val) == 0) return 1;
            else if(strlen(mh[h]) == 0)
            {
                strcpy(mh[h], val);
                return 0;
            }
        }
        return 0;
    }
    
};

int main()
{
    int n, key;
    char op[9] = {};
    char value[L] = {};
    myHash mh;
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", op, value);

        key = getKey(value);
        if(op[0] == 'i')
        {
            mh.insert(value, key);
        }
        else
        {
            if(mh.find(value, key)) printf("yes\n");
            else printf("no\n");
        }
    }
    return 0;
}

