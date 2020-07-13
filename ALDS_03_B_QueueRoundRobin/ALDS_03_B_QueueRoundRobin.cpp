#include<iostream>
#define MAX_MYQUEUE 100000
#define MIX_MYQUEUE 0
using namespace std;

struct procStruct
{
    char name[11];
    int time;
};

class myQueue
{
    procStruct Q[MAX_MYQUEUE];
    int head,tail;

    public:
    myQueue(){
        head = tail = 0;
    }

    bool isFull()
    {
        return head == (( tail + 1 ) % MAX_MYQUEUE);
    }

    bool isEmpty()
    {
        return head == tail;
    }

    bool enqueue(procStruct x)
    {
        if(isFull()) false;
        Q[tail] = x;
        if((tail + 1) == MAX_MYQUEUE) tail = 0;
        else tail++;
        return true;
    }

    bool dequeue(procStruct& x)
    {
        if(isEmpty()) false;
        x = Q[head];
        if((head + 1) == MAX_MYQUEUE) head = 0;
        else head++;
        return true;
    }

};

int main()
{
    int n,q;
    cin >> n >> q;
    
    myQueue mq;
    procStruct ps;

    for (int i = 0; i < n; i++)
    {
        cin >> ps.name >> ps.time;
        mq.enqueue(ps);
    }
    
    int time=0;
    while(!mq.isEmpty())
    {
        mq.dequeue(ps);
        if(ps.time <= q) 
        {
            time += ps.time;
            cout << ps.name << ' ' << time << endl;
        }
        else
        {
            time += q;
            ps.time -= q;
            mq.enqueue(ps);
        }
    }
    
    return 0;
}
