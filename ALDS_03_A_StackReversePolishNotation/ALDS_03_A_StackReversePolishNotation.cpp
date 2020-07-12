#include<iostream>
#define MAX_MYSTACK 100
#define MIN_MYSTACK 1
using namespace std;


class myStack
{
    int st[101]={};
    int top;

    public:
    myStack(){
        top = 0;
    };

    bool isFull()
    {
        if(top >= MAX_MYSTACK) return true;
        return false;
    }

    bool isEmpty()
    {
        if(top < MIN_MYSTACK) return true;
        return false;
    }

    bool push(int x)
    {
        if(isFull()) return false;
        top++;
        st[top] = x;
        return true;
    }

    bool pop(int& x)
    {
        if(isEmpty()) return false;
        x = st[top];
        top--;
        return true;
    }

};

int main()
{
    int i=0;
    char s[100]={};
    myStack st;
    cin.getline(s,100);
    int res=0,a=0,b=0;
    while(s[i] != '\000' && s[i] != EOF)
    {
        if(s[i] == '+')
        {
            st.pop(a);
            st.pop(b);
            st.push(a + b);
        }
        else if(s[i] == '-')
        {
            st.pop(a);
            st.pop(b);
            st.push(a - b);           
        }
        else if(s[i] == '/')
        {
            st.pop(a);
            st.pop(b);
            st.push(a / b);
        }
        else if(s[i] == '*')
        {
            st.pop(a);
            st.pop(b);
            st.push(a * b);
        }
        else
        {
            while(s[i] != ' ')
            {
                
                i++;
            }
            
            st.push((int)s[i]);
        }
        
        i++;
    }
    
    st.pop(a);
    cout << a;
    
    return 0;
}



