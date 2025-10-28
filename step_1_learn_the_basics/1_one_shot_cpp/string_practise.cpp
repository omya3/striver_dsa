#include<iostream>

using namespace std;

// string is set of characters

int main(){

    string s = "Omkar";

    cout<<s<<endl;

    int len  = s.size();

    s[len-1] = 'z'; // only single quotes are allowed as it is a character.

    cout<<s;
    return 0;
}