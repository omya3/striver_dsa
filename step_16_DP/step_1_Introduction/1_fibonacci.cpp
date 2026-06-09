#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int main()
{
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    // Initialize vector with -1 to track uncalculated states
    vector<int> dp(n + 1, -1);

    cout << "Fibonacci number: " << fib(n, dp) << endl;
    return 0;
}
