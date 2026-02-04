#include <iostream>
using namespace std;

vector<string> arr;
void generate_bin_str(string str, int n)
{
    if (str.length() == n)
    {
        arr.emplace_back(str);
        return;
    }

    generate_bin_str(str + '0', n);
    if (!str.empty())
    {
        char c1 = str.back();
        if (c1 != '1')
            generate_bin_str(str + '1', n);
    }
    else
    {
        generate_bin_str(str + '1', n);
    }
}
int main()
{

    int n;
    cout << "Enter the value of n";
    cin >> n;
    generate_bin_str("", n);
}