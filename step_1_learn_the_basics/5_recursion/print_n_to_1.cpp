#include<iostream>

using namespace std;

void print_n(int n){
    if(n>0){
        cout<<n<<" ";
        print_n(n-1);
    }
    return;
}

int main(){
    int n;
    cout<<"enter the valude of n: ";
    cin>>n;
    print_n(n);
}