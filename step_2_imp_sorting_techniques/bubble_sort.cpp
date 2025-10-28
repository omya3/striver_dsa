#include<iostream>
using namespace std;

void swap(int arr[], int i , int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}


void bubble_sort(int arr[], int n){
    bool swapped;
    for(int i=n-1; i>=0; i--){
        swapped = false;
        for(int j = 0; j<i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr, j, j+1);
                swapped=true;
            }
        }
        if(swapped==false){
            break;
        }
        
    }
    return;
}

int main(){
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    bubble_sort(arr, n);
    cout<<"Following are the sorted elements"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}