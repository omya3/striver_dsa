#include <iostream>
using namespace std;

void pattern_1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j <= i)
            {
                cout << "*";
            }
        }
        cout << endl;
    }
    return;
}

void pattern_2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < n - i + 1)
            {
                cout << "*";
            }
        }
        cout << endl;
    }
    return;
}

void pattern_2_improved(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {

            cout << "*";
        }
        cout << endl;
    }
    return;
}

void pattern_3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < i)
            {
                cout << j + 1;
            }
        }
        cout << endl;
    }
    return;
}

void pattern_4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {

            cout << j + 1;
        }
        cout << endl;
    }
    return;
}

void pattern_5(int n)
{
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }

        for (int j = 0; j < n - i - 1; j++)
        {

            cout << " ";
        }

        cout << endl;
    }
    return;
}

void pattern_6(int n)
{
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < 2 * (n - i - 1) + 1; j++)
        {
            cout << "*";
        }

        for (int j = 0; j < i; j++)
        {

            cout << " ";
        }

        cout << endl;
    }
    return;
}

void pattern_7(int n)
{

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < i + 1; j++)
        {
            cout << j + 1;
        } 

        for (int j = 0; j < 2 * (n - i - 1); j++)
        {
            cout << " ";
        }

        for (int j = i + 1; j > 0; j--)
        {
            cout << j;
        }
        cout<<endl;
    }
    return;
}

void pattern_8(int n)
{
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        for (char ch = 'A'; ch <= 'A'+i; ch++)
        {
            cout << ch ;
        }

        for (char ch = 'A'+i-1; ch > 'A'-1; ch--)
        {
            cout << ch ;
        }

        for (int j = 0; j < n - i - 1; j++)
        {

            cout << " ";
        }

        cout << endl;
    }
    return;
}

int main()
{

    cout << "Enter the num of rows" << endl;
    int n;
    cin >> n;
    pattern_8(n);
    return 0;
}