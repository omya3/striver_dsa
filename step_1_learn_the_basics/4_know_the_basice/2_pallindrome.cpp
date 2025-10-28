#include<iostream>

using namespace std;

int check_pallindrome(int n){
    int copy_n = n;
    int reversed_int = 0;
    int digit = 0;
    while(n>0){
        digit = n%10;
        if(reversed_int > INT_MAX /10 || ((reversed_int == INT_MAX /10 ) && digit > 7 ))
        {
            return 0;
        }
        if(reversed_int < INT_MIN /10 || ((reversed_int == INT_MIN /10 ) && digit < 7 ))
        {
            return 0;
        }
        n=n/10;
        reversed_int = reversed_int*10 + digit;

    }
    if(reversed_int == copy_n){
        return true;
    }
    else{
        return false;
    }

}

int main(){
    int n;
    cout<<"Enter an integer"<<endl;
    cin>>n;
    bool check = check_pallindrome(n);
    if(check){
        cout<<"The integer you have entered is pallindrome"<<endl;
    }
    else{
        cout<<"The integer you have entered is not pallindrome"<<endl;
    }

}