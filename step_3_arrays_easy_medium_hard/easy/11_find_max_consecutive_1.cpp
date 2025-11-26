#include<iostream>
using namespace std;

int main(){

    cout << "Enter the size of the array: " << endl;
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;
    int max_sum = 0;

    for(int i=0; i<n; i++){
        if(arr[i]==1){
            sum+=1;
        }
        else{
            if(sum>=max_sum){
                max_sum = sum;
                sum=0;
            }
        }
    }

    if(sum>max_sum){
        cout<<"Max num of consecutive 1's in the given array are "<< sum<<endl;
        return 0;
    }
    
    cout<<"Max num of consecutive 1's in the given array are "<< max_sum<<endl;

    return 0 ;
}