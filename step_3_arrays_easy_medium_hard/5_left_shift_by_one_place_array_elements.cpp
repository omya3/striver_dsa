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

    int temp = arr[0];

    for (int i=1; i<n; i++){
        arr[i-1] = arr[i];
    }

    arr[n-1] = temp;
    
    cout<<"Array after left rotation: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}