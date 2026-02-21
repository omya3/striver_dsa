#include <bits/stdc++.h>
using namespace std;

string postfix_to_infix(string s)
{
    int i = 0;
    stack<string> st;
    while (i < (int)s.size())
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
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            st.push("(" + b + ch + a + ")");
        }
        i++;
    }
    return st.top();
}

int main()
{
    string post = "AB+C*";
    cout << postfix_to_infix(post) << endl; // ((A+B)*C)
}
