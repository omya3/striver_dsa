#include <iostream>
using namespace std;

vector<string> result;

void generate_braces(string str, int openLeft, int closeLeft)
{
    if (openLeft == 0 && closeLeft == 0)
    {
        result.emplace_back(str);
        return;
    }

    if (openLeft == 0 && closeLeft != 0)
    {
        while (closeLeft != 0)
        {
            str += ')';
            closeLeft--;
        }
        result.emplace_back(str);
        return;
    }

    if (openLeft == closeLeft)
    {
        str += '(';
        openLeft--;
        generate_braces(str, openLeft, closeLeft);
    }
    else
    {
        generate_braces(str + '(', openLeft - 1, closeLeft);
        generate_braces(str + ')', openLeft, closeLeft - 1);
    }
}

int main()
{
    int n;
    cout << "Enter the value of n";
    cin >> n;
    generate_braces("", n, n);
}