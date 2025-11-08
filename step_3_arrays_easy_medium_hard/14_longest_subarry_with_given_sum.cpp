#include<iostream>
using namespace std;

int find_lonest_subarray_with_sum_k(int arr[], int n, int k){

    int back = 0;
    int front = 0;
    int sum = arr[0];
    int len = 0;
    int max_len = 0;

    while(back<=front && front<n){
        // cout<<front;
        if(sum==k){
            len = front-back+1;
            max_len = max(len, max_len); 
        }
        if(sum>k){
            sum-=arr[back];
            back++;
            continue;
        }
        
        front++;
        if(front<n){
            sum+=arr[front];
        }
    }
    return max_len;

}

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

    cout << "Enter the sum: " << endl;
    int k;
    cin >> k;
    int max_len = find_lonest_subarray_with_sum_k(arr, n, k);
    cout<<"Array of max len containing the desired sum is"<<max_len;

}