#include <iostream>
using namespace std;

void insertatBottom(stack<int> &s, int t)
{
    if (s.empty())
    {
        s.push(t);
        return;
    }

    int x = s.top();
    s.pop();
    insertatBottom(s, t);
    s.push(x);
}

void sortStack(stack<int> &s)
{
    if (s.size() <= 1)
    {
        return;
    }

    int t = s.top();
    s.pop();
    sortStack(s);
    insertatBottom(s, t);
}