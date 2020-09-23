#include<cstdio>
#include<vector>
#include<algorithm>
#define NIL -1
using namespace std;
vector <int> preorder, inorder, postorder;

void reconstruction(int l, int r)
{
    if(l >= r) return;

    int root = preorder.front();
    preorder.erase(preorder.begin());
    int m = distance(inorder.begin(),find(inorder.begin(), inorder.end(), root));
    reconstruction(l, m);
    reconstruction(m + 1, r);

    postorder.push_back(root);
}

int main()
{
    int n;

    scanf("%d", &n);

    int tmp;
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &tmp);
        preorder.push_back(tmp);
    }

    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &tmp);
        inorder.push_back(tmp);
    }

    reconstruction(0, preorder.size());

    for(int i = 0; i < n - 1; i++) 
    {
        tmp = postorder[i];
        printf("%d ", tmp);
    }
    printf("%d\n",postorder[n - 1]);

    return 0;
}

