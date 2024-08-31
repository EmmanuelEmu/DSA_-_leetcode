#include <bits/stdc++.h>
using namespace std;


// This is the better optimization for selecting pivot element using median
int medianOfThree(vector<int> &arr, int low, int mid, int high)
{
    if ((arr[low] > arr[mid]) != (arr[low] > arr[high]))
        return low;
    else if ((arr[mid] > arr[low]) != (arr[mid] > arr[high]))
        return mid;
    else
        return high;
}

int partition(vector<int> &arr, int low, int high)
{

    int mid = low + (high - low) / 2;
    int medianIndex = medianOfThree(arr, low, mid, high);

    // Swap median element with the first element to use it as pivot
    int tempo = arr[low];
    arr[low] = arr[medianIndex];
    arr[medianIndex] = tempo;

    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;
    return j;
}

void qs(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

vector<int> sortArray(vector<int> &nums)
{
    qs(nums, 0, nums.size() - 1);
    return nums;
}

int main()
{

    vector<int> v;
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    vector<int> res = sortArray(v);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}