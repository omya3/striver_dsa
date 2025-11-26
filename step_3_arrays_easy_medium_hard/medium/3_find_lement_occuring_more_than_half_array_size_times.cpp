#include<iostream>
using namespace std;

int find_dominating_element(vector<int> &arr){
    int count, element;
    element = arr[0];
    for(int i=1; i<arr.size(); i++){
        if(count==0){
            element = arr[i];
            count = 1;
            continue;
        }

        if(arr[i]==element){
            count++;
        }
        else{
            count--;
        }
    }

    if(count>0){
        int check_count = 0;
        for(int i=1; i<arr.size(); i++){
            if(arr[i]==element){
                check_count++;
            }
        }
        if(check_count>(arr.size()/2)){
            return element;
        }
    }
    return -1;
}


int main(){

    cout<<"Enter the size of the array: "<<endl;
    int n;
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    find_dominating_element(arr);
}