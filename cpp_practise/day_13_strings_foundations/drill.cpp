// Day 13: implement only these two functions. Run after each one.
#include <array>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

bool is_clean_palindrome(const string &text)
{
    // TODO: Use two indices, skip non-alphanumeric characters, and compare
    //       lowercase characters. An empty or punctuation-only string is true.
    (void)text; // Remove this placeholder line when you implement the function.
    return true;
}

bool are_anagrams_lowercase(const string &first, const string &second)
{
    // Precondition: both strings contain only lowercase English letters.
    // TODO: Check length, count characters with array<int, 26>, and verify zero.
    (void)first;  // Remove these placeholder lines when you implement the function.
    (void)second;
    return false;
}

void check(const string &name, bool actual, bool expected, int &passed)
{
    const bool correct = actual == expected;
    cout << (correct ? "PASS " : "FAIL ") << name;
    if (!correct)
    {
        cout << " (got " << boolalpha << actual << ", expected " << expected << ')';
    }
    cout << '\n';
    if (correct)
    {
        ++passed;
    }
}

int main()
{
    // Predict these lines before running the program.
    const string word = "leetcode";
    const size_t position = word.find("code");
    if (position != string::npos)
    {
        cout << "found at=" << position << '\n';
        cout << "substring=" << word.substr(position, 4) << '\n';
    }

    int passed = 0;
    check("panama", is_clean_palindrome("A man, a plan, a canal: Panama"), true, passed);
    check("race a car", is_clean_palindrome("race a car"), false, passed);
    check("empty palindrome", is_clean_palindrome(""), true, passed);
    check("punctuation only", is_clean_palindrome("!!!"), true, passed);
    check("digit mismatch", is_clean_palindrome("0P"), false, passed);
    check("punctuation at right", is_clean_palindrome("a."), true, passed);
    check("two different letters", is_clean_palindrome("ab"), false, passed);

    check("listen/silent", are_anagrams_lowercase("listen", "silent"), true, passed);
    check("rat/car", are_anagrams_lowercase("rat", "car"), false, passed);
    check("different lengths", are_anagrams_lowercase("ab", "a"), false, passed);
    check("empty anagrams", are_anagrams_lowercase("", ""), true, passed);
    check("repeated letters match", are_anagrams_lowercase("aab", "aba"), true, passed);
    check("repeated letters differ", are_anagrams_lowercase("aab", "abb"), false, passed);

    cout << passed << "/13 checks passed\n";
}
