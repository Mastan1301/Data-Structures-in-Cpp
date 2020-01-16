/*
    Implementation of a Queue using two stacks.
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s_f, s_b, temp;

    int q;
    cin >> q;
    int i;

    while(q--)
    {
        cin >> i;
        if(i == 1)
        {
            int x;
            cin >> x;
            s_b.push(x);
        }

        if(s_f.empty())
        {
            while(!s_b.empty())
            {
                s_f.push(s_b.top());
                s_b.pop();
            }
        }

        if(i == 2)
            s_f.pop();

        else if(i == 3)
            cout << s_f.top() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
