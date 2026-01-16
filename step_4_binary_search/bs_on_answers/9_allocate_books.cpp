#include <iostream>
using namespace std;

tuple<int, int> find_max_and_sum(vector<int> &pages)
{
    int n = pages.size();
    int max_pages = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (pages[i] > max_pages)
        {
            max_pages = pages[i];
        }
        sum += pages[i];
    }
    return make_tuple(max_pages, sum);
}

int check_possible_allocation(vector<int> &arr, int page_sum, int students_in_class)
{
    int n = arr.size();
    int student = 1;
    long long assigned_pages = 0;

    for (int i = 0; i < n; i++)
    {

        if ((assigned_pages + arr[i]) <= page_sum)
        {
            assigned_pages += arr[i];
        }
        else
        {
            student += 1;
            assigned_pages = arr[i];
        }
    }
    return student;
}

int find_max_values_of_pages(vector<int> &arr, int students)
{
    int n = arr.size();
    if(n<students){
        return -1;
    }
    int max_pages, sum;
    tie(max_pages, sum) = find_max_and_sum(arr);
    int left = max_pages;
    int right = sum;
    int mid;
    int ans;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (check_possible_allocation(arr, mid, students)>students)
        {
            
            left = mid + 1;
        }
        else
        {   ans = mid;
            right = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;

    vector<int> arr;
    cout << "Enter the elements of the array" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the value of students";
    cin >> k;

    int least_capacity = find_max_values_of_pages(arr, k);
}