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
    int second_max = INT_MIN;

    for (int i=0; i<n; i++)
    {
        if(arr[i]>max){
            second_max = max;
            max = arr[i];
        }
        else if(arr[i]>second_max && arr[i]!=max){
            second_max = arr[i];
        }
    }

    cout<<"The largest element in the array is: "<<max<<endl;
    cout<<"The second largest element in the array is: "<<second_max<<endl;
    return 0;
}