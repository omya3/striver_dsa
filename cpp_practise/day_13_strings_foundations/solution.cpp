// Day 13 reference solution. Open after minute 27.

#include <array>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

bool is_clean_palindrome(const string &text)
{
    size_t left = 0;
    size_t right = text.size(); // Exclusive, so an empty string is safe.

    while (left < right)
    {
        const unsigned char left_char = static_cast<unsigned char>(text[left]);
        if (!isalnum(left_char))
        {
            ++left;
            continue;
        }

        const unsigned char right_char =
            static_cast<unsigned char>(text[right - 1]);
        if (!isalnum(right_char))
        {
            --right;
            continue;
        }

        if (tolower(left_char) != tolower(right_char))
        {
            return false;
        }

        ++left;
        --right;
    }

    return true;
}

bool are_anagrams_lowercase(const string &first, const string &second)
{
    if (first.size() != second.size())
    {
        return false;
    }

    array<int, 26> frequency{};
    for (char ch : first)
    {
        ++frequency[ch - 'a'];
    }
    for (char ch : second)
    {
        --frequency[ch - 'a'];
    }

    for (int count : frequency)
    {
        if (count != 0)
        {
            return false;
        }
    }
    return true;
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
