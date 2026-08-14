#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RabinKarp {
public:
    // Returns a list of all starting indices where the pattern is found in the text
    vector<int> search(string text, string pattern) {
        vector<int> match_indices;
        int n = text.length();
        int m = pattern.length();
        
        // Edge case: Pattern cannot be longer than the text
        if (m > n) return match_indices;

        int d = 256;      // Number of characters in the input alphabet (base)
        int q = 101;      // A prime number for modulo arithmetic to prevent overflow
        
        int p_hash = 0;   // Hash value for pattern
        int t_hash = 0;   // Hash value for current window of text
        int h = 1;        // The value of d^(m-1) % q

        // Precompute h = (d^(m-1)) % q used for removing the leading digit
        for (int i = 0; i < m - 1; i++) {
            h = (h * d) % q;
        }

        // Step 1: Calculate the initial hash value of pattern and first window of text
        for (int i = 0; i < m; i++) {
            p_hash = (d * p_hash + pattern[i]) % q;
            t_hash = (d * t_hash + text[i]) % q;
        }

        // Step 2: Slide the pattern over text one by one
        for (int i = 0; i <= n - m; i++) {
            
            // If the hash values match, verify characters to rule out collisions
            if (p_hash == t_hash) {
                bool match_found = true;
                for (int j = 0; j < m; j++) {
                    if (text[i + j] != pattern[j]) {
                        match_found = false;
                        break;
                    }
                }
                
                // If checking confirms it, store the index
                if (match_found) {
                    match_indices.push_back(i);
                }
            }

            // Step 3: Compute hash value for the next window of text
            // Remove leading digit, add trailing digit
            if (i < n - m) {
                t_hash = (d * (t_hash - text[i] * h) + text[i + m]) % q;

                // If we get a negative hash value, convert it to positive
                if (t_hash < 0) {
                    t_hash = (t_hash + q);
                }
            }
        }
        
        return match_indices;
    }
};

int main() {
    RabinKarp solver;
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";
    
    vector<int> results = solver.search(text, pattern);
    
    cout << "Pattern found at indices: ";
    for (int idx : results) {
        cout << idx << " ";
    }
    cout << endl;
    
    return 0;
}
