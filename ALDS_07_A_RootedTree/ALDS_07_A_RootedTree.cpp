#include<cstdio>
#include<algorithm>
#include<vector>
#define NIL -1
using namespace std;

struct Node{int parent, leftChild, rightSibling;};
struct Node tree[100000];

void generateTree(int p, int rs);
void setNode(int p, int l, int r, int id);
int getDepth(int id);
void generateTree2(int n);

void setNode(int p, int l, int r, int id)
{
    tree[id].parent = p;
    tree[id].leftChild = l;
    tree[id].rightSibling = r;
}

void generateTree(int p, int rs)
{
    int id, k;
    vector<int> children;
    
    scanf("%d%d", &id, &k);
    int tmp;
    if(k >= 1)
    {
        for(int i =0;i < k;i++)
        {
            scanf("%d", &tmp);
            children.push_back(tmp);
        }
        children.push_back(NIL);
        for(int i =1;i < k + 1;i++)
        {
            generateTree(id, children[i]);
        }
        setNode(p, children[0], rs, id);
    }
    else
    {
        setNode(p, NIL, rs, id);   
    }
}

void generateTree2(int n)
{
    int id, k;
    vector<int> children;
    
    for(int m =0; m < n; m++)
    {
        scanf("%d%d", &id, &k);
        int tmp;
        for(int i =0;i < k;i++)
        {
            scanf("%d", &tmp);
            children.push_back(tmp);
            if(i == 0)
            {
                tree[id].leftChild = tmp;
                tree[tmp].parent = id;
            }
            if(i >= 1)
            {
                tree[tmp].parent = id;
                tree[children[i - 1]].rightSibling = tmp;
            }
        }
        children.clear();
    }

}

int getDepth(int id)
{
    int dep = 0;
    while(tree[id].parent != NIL)
    {
        id = tree[id].parent;
        dep++;
    }
    return dep;
}

void outputTree(int n)
{
    for(int i = 0; i < n; i++)
    {
        int dep = getDepth(i);
        if(tree[i].parent == NIL)
            printf("node %d: parent = %d, depth = %d, root, [", i, tree[i].parent, dep);
        else if(tree[i].leftChild == NIL)   
            printf("node %d: parent = %d, depth = %d, leaf, [", i, tree[i].parent, dep);
        else 
            printf("node %d: parent = %d, depth = %d, internal node, [", i, tree[i].parent, dep);
        
        int child = tree[i].leftChild;
        while(child != NIL)
        {
            printf("%d", child);
            child = tree[child].rightSibling;
            if(child != NIL) printf(", ");
        }
        printf("]\n");
    }
}

int main()
{
    int n;

    scanf("%d", &n);
    for(int i=0; i < n; i++) setNode(NIL,NIL,NIL,i);

    generateTree2(n);

    outputTree(n);
    
    return 0;
}

