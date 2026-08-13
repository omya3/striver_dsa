#include <string>

using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        int n = a.size();
        int m = b.size();

        long long prime_base = 31;
        long long mod = 1e9+7;

        long long max_power = 1;

        for(int i=0; i<m-1; i++){
            max_power = (max_power * prime_base) % mod;
        }

        long long hash_b = 0;
        for(int i=0; i<m; i++){
            // Fix 1: Added missing closing parenthesis
            hash_b = (hash_b * prime_base + (b[i] - 'a' + 1)) % mod;
        }

        long long hash_window = 0;
        for(int i=0; i<m; i++){
            // Fix 2: Changed a[i] to a[i % n] to prevent out-of-bounds crash
            hash_window = (hash_window * prime_base + (a[i % n] - 'a' + 1)) % mod;
        }

        int max_len = n * ((m + n - 1) / n + 2);

        // Fix 3: Changed '<' to '<=' so the last character block is verified
        for(int i=0; i <= max_len - m; i++){

            if(hash_b == hash_window){
                bool match = true;
                for(int j=0; j<m; j++){
                    if(a[(i + j) % n] != b[j]){
                        match = false;
                        break;
                    }
                }
                if(match){
                    int repeats = i + m;
                    return (repeats + n - 1) / n;
                }
            }

            if(i < max_len - m){
                long long old_char = a[i % n] - 'a' + 1;
                hash_window = (hash_window - (old_char * max_power) % mod + mod) % mod;

                long long new_char = a[(i + m) % n] - 'a' + 1;
                hash_window = (hash_window * prime_base + new_char) % mod;
            }
        }
        return -1;
    }
};