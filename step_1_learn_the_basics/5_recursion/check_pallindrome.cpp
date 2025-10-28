#include<iostream>
using namespace std;


bool check_pallindrome(int i, string s){
    if(i>s.size()/2){return true;}
    if(tolower(s[i]) != tolower(s[s.size()-i-1])){return false;}
    return check_pallindrome(i+1, s);
}

int main(){
    string s;
    cout<<"Entera string: ";
    cin>>s;
    if(check_pallindrome(0, s))
    {
        cout<<"PALLINDROME";
    }
    else{
        cout<<"NOT PALLINDROME";
    }
}