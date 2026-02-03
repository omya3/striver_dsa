#include <iostream>
using namespace std;

double pow(double x, long n)
{
    double ans = 1;
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 1.0 / pow(x, -n);
    }

    double res = pow(x, n / 2);
    if (n % 2 == 1)
    {
        return x * res * res;
    }
    else
    {
        return res * res;
    }
}
int main()
{
    double x;
    long n;
    cout << "Enter the base" << endl;
    cin >> x;
    cout << "Enter the power" << endl;
    cin >> n;
    double ans = 0;
    cout << pow(x, n);
}