#include<iostream>
using namespace std;

vector<int> leaders(vector<int> arr){
    vector<int> leaders;
    int n = arr.size()-1;
    leaders.emplace_back(arr[n]);
    int max = arr[n];

    for(int i=n-1; i>=0; i--){
        if(arr[i]>max){
            max = arr[i];
            leaders.emplace_back(max);
        }
    }
    return leaders;
}

int main(){
    cout << "Enter the size of the array: " << endl;
    int n;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }


}