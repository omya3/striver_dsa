#include<iostream>

using namespace std;

int main(){

    cout<<"Enter the size of the array: "<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int max = INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(arr[i] > max){
            max = arr[i];
        }
    }
    cout<<"The largest element in the array is: "<<max<<endl;
    return 0;
}