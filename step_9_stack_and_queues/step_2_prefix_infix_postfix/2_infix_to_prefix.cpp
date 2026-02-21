#include <iostream>
using namespace std;

int priority(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0; // for '(' and others
}

string infix_to_prefix(string s)
{
    reverse(s.begin(), s.end());
    string s_new = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            s_new += ')';
        else if (s[i] == ')')
            s_new += '(';
        else
        {
            s_new += s[i];
        }
    }
    s = s_new;
    int i = 0;
    stack<char> st;
    string ans = "";
    while (i < s.size())
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            ans += s[i];
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && priority(st.top()) >= priority(s[i]))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string expr = "(A+B)*C";
    cout << infix_to_prefix(expr) << endl; // Expected: AB+C*
}