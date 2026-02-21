#include <bits/stdc++.h>
using namespace std;

string postfix_to_prefix(string s)
{
    int i = 0;
    stack<string> st;
    while (i < s.size())
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
            st.push(ch + t2 + t1);
        }
        i++;
    }
    return st.top();
}

int main()
{
    string post = "AB+C*";
    cout << postfix_to_prefix(post) << endl; // Expected: *+ABC
}

