#include <bits/stdc++.h>
using namespace std;

int setBitCount(int n)
{
    int count = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int pivotBits = setBitCount(pivot);
    int i = low;
    int j = high;

    while (i < j)
    {

        while (i <= high && (arr[i] <= pivot || setBitCount(arr[i]) != pivotBits))
        {
            i++;
        }

        while (j >= low && (arr[j] > pivot || setBitCount(arr[j]) != pivotBits))
        {
            j--;
        }
        if (i < j && setBitCount(arr[i]) == setBitCount(arr[j]))
        {
            swap(arr[i], arr[j]);
        }
    }
    if (setBitCount(arr[j]) == pivotBits)
    {
        swap(arr[low], arr[j]);
    }
    return j;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

bool canSortArray(vector<int> &nums)
{
    quickSort(nums, 0, nums.size() - 1);

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < nums[i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    int n;
    cin >> n;
    vector<int> nums;
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout << canSortArray(nums) << endl;
    return 0;
}