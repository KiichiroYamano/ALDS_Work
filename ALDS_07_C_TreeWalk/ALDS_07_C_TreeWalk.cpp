#include<cstdio>
#include<algorithm>
#include<vector>
#define NIL -1
using namespace std;

struct Node{int parent, left, right;};
struct Node tree[25];

void PreorderTreeWalk(int node);
void InorderTreeWalk(int node);
void PostorderTreeWalk(int node);

void PreorderTreeWalk(int node)
{
    if(node == NIL) return;
    printf(" %d",node);
    PreorderTreeWalk(tree[node].left);
    PreorderTreeWalk(tree[node].right);
}

void InorderTreeWalk(int node)
{
    if(node == NIL) return;
    InorderTreeWalk(tree[node].left);
    printf(" %d",node);
    InorderTreeWalk(tree[node].right);
}

void PostorderTreeWalk(int node)
{
    if(node == NIL) return;
    PostorderTreeWalk(tree[node].left);
    PostorderTreeWalk(tree[node].right);
    printf(" %d",node);
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
    
    printf("Preorder\n");
    PreorderTreeWalk(root);
    printf("\n");

    printf("Inorder\n");
    InorderTreeWalk(root);
    printf("\n");

    printf("Postorder\n");
    PostorderTreeWalk(root);
    printf("\n");

    return 0;
}

