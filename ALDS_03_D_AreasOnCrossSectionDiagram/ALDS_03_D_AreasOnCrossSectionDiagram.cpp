#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    stack<int> s1;
    stack<pair<int, int>> s2;
    char ch;
    int i = 1;
    int allArea = 0,tempArea;

    while(1)
    {
        scanf("%c", &ch);
        if(ch == '\n') break;

        if(ch == '\\')
        {
            s1.push(i);
            i++;
        }
        else if(ch == '/')
        {
            if(!s1.empty())
            {
                allArea += i - s1.top();
                if(s2.empty()) s2.push(make_pair(s1.top(), i - s1.top()));
                else
                {
                    tempArea = 0;
                    while(1)
                    {
                        if(s2.empty()) break;
                        if(s2.top().first < s1.top()) break;
                        else
                        {
                            tempArea += s2.top().second;
                            s2.pop();
                        }
                    }
                    tempArea += i - s1.top();
                    s2.push(make_pair(s1.top(), tempArea));
                }
                s1.pop();
            }
            i++;
        }
        else if(ch == '_')
        {
            i++;
        }
    }

    vector<int> localAreas;
    while(!s2.empty())
    {
        localAreas.push_back(s2.top().second);
        s2.pop();
    }
    reverse(localAreas.begin(),localAreas.end());
    
    printf("%d\n", allArea);
    printf("%d", localAreas.size());
    for (int i = 0; i < localAreas.size(); i++)
    {
        printf(" %d", localAreas[i]);
    }
    printf("\n");

    return 0;
}

