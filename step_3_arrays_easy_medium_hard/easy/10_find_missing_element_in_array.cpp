#include<iostream>
using namespace std;

void xor_method(int arr[], int n){
    int xor1 = 0;
    int xor2 = 0;

    for(int i=0; i<n-1; i++){
        xor1 = xor1^(i+1);
        xor2 = xor2^(arr[i]);
    }

    xor1 = xor1^n;
    int miss = 0;
    miss = xor1^xor2;

    cout<<"Missing element is "<<miss<<endl;
    
}

void sum_method(int arr[], int n){

    int real_sum = (n*(n+1))/2;
    int sum2 = 0;

    for(int i=0; i<n-1; i++){
        sum2 = sum2+arr[i];
    }

    int miss_elem = real_sum - sum2;

    cout<<"Missing element is "<<miss_elem<<endl;
}



int main(){

    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    int arr[n-1];
    cout<<"Enter the value of elemts in the array"<<endl;
    for(int i=0; i<n-1; i++){
        cin>>arr[i];
    }

    xor_method(arr, n);
    sum_method(arr, n);
    
    return 0;
}