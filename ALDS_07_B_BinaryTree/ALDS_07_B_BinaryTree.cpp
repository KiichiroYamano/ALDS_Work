#include<cstdio>
#include<algorithm>
#include<vector>
#define NIL -1
using namespace std;

struct Node{int parent, left, right;};
struct Node tree[25];
int H[25];

int getDepth(int id);
int getHeight(int u);

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

int getHeight(int u)
{
    int h1 = 0;
    int h2 = 0;

    if(tree[u].right != NIL) h1 = getHeight(tree[u].right) + 1;
    if(tree[u].left != NIL) h2 = getHeight(tree[u].left) + 1;

    return H[u] = max(h1, h2);
}

void outputTree(int n)
{
    for(int i = 0; i < n; i++)
    {
        int sibling, degree, depth;
        depth = getDepth(i);

        if(tree[i].left == NIL && tree[i].right == NIL) degree = 0;
        else if(tree[i].left != NIL && tree[i].right != NIL) degree = 2;
        else degree = 1;

        if(tree[i].parent == NIL)
        {
            sibling = NIL;
            printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, root\n", i, tree[i].parent, sibling, degree, depth, H[i]);
        }
        else if(tree[i].left == NIL && tree[i].right == NIL )
        {
            sibling = tree[tree[i].parent].left == i ? tree[tree[i].parent].right :  tree[tree[i].parent].left; 
            printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, leaf\n", i, tree[i].parent, sibling, degree, depth, H[i]);
        }
        else 
        {
            sibling = tree[tree[i].parent].left == i ? tree[tree[i].parent].right :  tree[tree[i].parent].left;
            printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, internal node\n", i, tree[i].parent, sibling, degree, depth, H[i]);
        }
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) 
    {
        tree[i].parent = NIL;
        tree[i].left = NIL;
        tree[i].right = NIL;
    }

    int id, l, r;
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &id, &l, &r);
        tree[id].left = l;
        tree[id].right = r;
        if(l != NIL) tree[l].parent = id;
        if(r != NIL) tree[r].parent = id;
    }

    int root;
    for(int i = 0; i < n; i++)
    {
        if(tree[i].parent == NIL)
        {
            root = i;
            break;
        }
    }

    H[root] = getHeight(root);
    outputTree(n);
    
    return 0;
}

