#include <bits/stdc++.h>
using namespace std;

string prefix_to_postfix(string s)
{
    int i = s.size() - 1;
    stack<string> st;
    while (i >= 0)
    {
        char ch = s[i];
        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9'))
        {
            st.push(string(1, ch)); // operand
        }
        else
        {
            string t1 = st.top();
            st.pop(); // left operand
            string t2 = st.top();
            st.pop(); // right operand
            st.push(t1 + t2 + ch);
        }
        i--;
    }
    return st.top();
}

int main()
{
    string pre = "*+ABC";
    cout << prefix_to_postfix(pre) << endl; // ((A+B)*C)
}
