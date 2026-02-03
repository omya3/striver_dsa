class Solution {
public:
    int countGoodNumbers(long long n) {
        const long long MOD = 1000000007LL;
        long long even_pos = (n + 1) / 2;  // ceil(n/2)
        long long odd_pos = n / 2;         // floor(n/2)
        
        long long five_pow = mod_pow(5, even_pos, MOD);
        long long four_pow = mod_pow(4, odd_pos, MOD);
        return (five_pow * four_pow) % MOD;
    }
private:
    long long mod_pow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) result = result * base % mod;
            base = base * base % mod;
            exp /= 2;
        }
        return result;
    }
};
