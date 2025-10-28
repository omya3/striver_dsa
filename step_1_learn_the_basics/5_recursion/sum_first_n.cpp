#include<iostream>
using namespace std;

// parameterised method
void parameterised_sum(int i, int sum){
    if(i<1){
        cout<<sum<<endl;
        return;
    }
    parameterised_sum(i-1, sum+i);
    return;
}

int functional_sum(int n){
    if(n<1){
        return 0;
    }
    return functional_sum(n-1)+n;
}

 int main(){
    int n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    cout<<"The sum is: "<<endl;
    // parameterised_sum(n, 0);
    cout<<functional_sum(n)<<endl;
 }