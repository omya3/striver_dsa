#include <iostream>
using namespace std;

void insertinOrder(stack<int> &s, int t)
{
    if (s.empty() || s.top() <= t)
    {
        s.push(t);
        return;
    }

    int x = s.top();
    s.pop();
    insertinOrder(s, t);
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
    insertinOrder(s, t);
}