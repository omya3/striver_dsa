#include <iostream>
using namespace std;

int find_xor_till(int x)
{
    if (x % 4 == 1)
        return 1;
    else if (x % 4 == 2)
        return x + 1;
    else if (x % 4 == 3)
        return 0;
    else
        return x;
}

int find_xor_range(int m, int n)
{
    int a = find_xor_till(m);
    int b = find_xor_till(n);
    return a ^ b;
}

int main()
{

    int m;
    cin >> m;
    int n;
    cin >> n;
    
    return find_xor_range(m, n);
}