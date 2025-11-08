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

    int exor = 0;

    for (int i = 0; i < n; i++)
    {
        exor^= arr[i];
    }

    cout<<"The element occuring only once is "<<exor<<endl;
}