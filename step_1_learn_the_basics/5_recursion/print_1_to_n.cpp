#include<iostream>

using namespace std;

void print_n(int i, int n){
    if(i<=n){
        cout<<i<<" ";
        print_n(i+1, n);
    }
    return;
}

int main(){
    int n;
    cout<<"enter the valude of n: ";
    cin>>n;
    print_n(1, n);
}