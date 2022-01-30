#include <climits>
#include <iostream>
using namespace std;

class Stack
    {
        int *data;
        int nextIndex;
        int capacity;
    public :
        Stack(int n)
        {
            data=new int[n];
            nextIndex=0;
            capacity=n;
        }

        int size()
        {
            return nextIndex;
        }
        bool isEmpty()
        {
            return nextIndex==0;
        }
        void push(int val)
        {
            if(nextIndex==capacity)
            {
                cout << "Stack full" << endl;
                return;
            }
            data[nextIndex] = val;
            nextIndex++;
        }
        int pop()
        {
            if(nextIndex==0)
            {
                cout << "Stack is empty" << endl;
                return INT_MIN;
            }
           // int a =
            nextIndex--;
            return data[nextIndex-1];
        }
        int top()
        {
            if(nextIndex==0)
            {
                cout << "Stack is empty" << endl;
                return INT_MIN;
            }
            return data[nextIndex-1];
        }
    };

    int main()
    {
        Stack s(4);
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);
        cout << s.top() << endl;
         cout << s.pop() << endl;
          cout << s.pop() << endl;
           cout << s.pop() << endl;
           cout << s.size() << endl;
            cout << s.top() << endl;
            cout << s.pop() << endl;
            cout << s.top() << endl;
            cout << s.isEmpty() << endl;
    }
