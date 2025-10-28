#include<iostream>
using namespace std;

// it's just the list of similar data type

int main(){

    // int arr[5];

    // cout<<"Enter the numbers"<<endl;

    // cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4];

    // cout<<"Following are the numbers you entered"<<endl;
    // cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4];

    // Following is the 2D array;

    int arr[3][4];

    cout<<"Enter a value";
    cin>>arr[0][0];
    cout<<arr[0][0];

    cout<<"Following is the size of array";
    cout<<sizeof(arr)/sizeof(arr[0][0]);
    return 0;

}