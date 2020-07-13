#include<iostream>
#define MAX_MYSTACK 1000
#define MIN_MYSTACK 1
using namespace std;


class myStack
{
    int st[MAX_MYSTACK]={};
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
    char s[1000]={};
    myStack st;
    cin.getline(s,1000);
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
            st.push(b - a);           
        }
        else if(s[i] == '/')
        {
            st.pop(a);
            st.pop(b);
            st.push(b / a);
        }
        else if(s[i] == '*')
        {
            st.pop(a);
            st.pop(b);
            st.push(a * b);
        }
        else if(s[i] == ' '){/*do nothing*/}
        else
        {
            int x = 0;
            while(s[i] != ' ')
            {
                x = x * 10 + (int)(s[i] - '0');
                i++;
            }
            st.push(x);
        }
        i++;
    }
    
    st.pop(a);
    cout << a << endl;
    
    return 0;
}



