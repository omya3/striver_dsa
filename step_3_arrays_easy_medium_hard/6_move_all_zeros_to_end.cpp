#include <iostream>

using namespace std;

int fine_nonzero_index(int arr[], int j, int n)
{
    while (j < n)
    {
        if (arr[j] != 0)
        {
            return j;
        }
        j++;
    }
    return j;
}

int main()
{
    cout << "Enter the size of the array: " << endl;
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int i = 0;
    int j = 0;
    int temp = 0;

    while (i < n)
    {
        if (arr[i] == 0)
        {
            j = fine_nonzero_index(arr, j, n);
            // cout<<"Zero index found at: "<<i<<endl;
            // cout<<"Non zero index found at: "<<j<<endl;
            // cout<<"////////"<<endl;
            if (j >= n)
            {
                break;
            }
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            continue;
        }
        cout << arr[i] << " ";
        i++;
    }

    cout << "Following is the array after moving all zeros to the end: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}