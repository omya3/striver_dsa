#include<iostream>
#include <cmath>

using namespace std;

int check_armstrong(int x){
    int copy_x = x;
    int cubed = 0;
    int digit = 0;
    while(x>0){
        digit = x%10;
        if(cubed > INT_MAX /10 || ((cubed == INT_MAX /10 ) && digit > 7 ))
        {
            return 0;
        }
        if(cubed < INT_MIN /10 || ((cubed == INT_MIN /10 ) && digit < 7 ))
        {
            return 0;
        }
        x=x/10;
        cubed = cubed + pow(digit, 3);

    }
    if(cubed == copy_x){
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