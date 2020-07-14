#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;

struct Node
{
    int key;
    Node *prev, *next;
};

class DoublyLinkedList
{
    Node *nil;

    public:
    DoublyLinkedList()
    {
        nil = (Node *)malloc(sizeof(Node));
        nil->next = nil;
        nil->prev = nil;
    }

    Node* getNil()
    {
        return nil;
    }

    void insert(int key)
    {
        Node *x = (Node *)malloc(sizeof(Node));
        x->key = key;
        x->next = nil->next;
        nil->next->prev = x;
        nil->next = x;
        x->prev = nil;
    }

    Node* listSerch(int key)
    {
        Node *cur = nil->next;
        while( cur != nil && cur->key != key) cur = cur->next;
        return cur;
    }

    void deleteNode(Node *t)
    {
        if( t == nil ) return;
        t->prev->next = t->next;
        t->next->prev = t->prev;
        free(t);
    }

    void deleteFirst()
    {
        deleteNode(nil->next);
    }

    void deleteLast()
    {
        deleteNode(nil->prev);
    }

    void deleteKey(int key)
    {
        deleteNode(listSerch(key));
    }

};

void printList(DoublyLinkedList list)
{
    Node *nil = list.getNil();
    Node *cur = nil->next;
    int isf = 0;
    while(1)
    {
        if(cur == nil) break;
        if(isf > 0) printf(" ");
        printf("%d", cur->key);
        cur = cur->next;
        isf++;
    }
    printf("\n");
}

int main()
{
    int n,key;
    DoublyLinkedList list;
    char cmd[20] = {};

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s%d",cmd,&key);

        if(cmd[0] == 'i')
        {
            list.insert(key);
        }
        else if(cmd[6] == 'F')
        {
            list.deleteFirst();
        }
        else if(cmd[6] == 'L')
        {
            list.deleteLast();
        }
        else if(cmd[0] == 'd')
        {
            list.deleteKey(key);
        }
    }
    
    printList(list);
    
    return 0;
}

