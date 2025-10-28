#include<iostream>

using namespace std;

int gcd(int a,int b){
    while(a>0 && b>0){
        if (a>b){
            a = a%b;
        }
        else{
            b = b%a;
        }
    }
    if(a>0){
        return a;
    }
    else{
        return b;
    }

}

int main(){
    int a = 52;
    int b= 10;
    cout<<"gcd of "<<a<<" and "<<b<<" is "<<gcd(a, b)<<endl;
}