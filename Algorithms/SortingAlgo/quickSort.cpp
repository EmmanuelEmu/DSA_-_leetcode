#include <bits/stdc++.h>
using namespace std;

int Partition(vector<int> &arr, int low, int high)
{
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
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[low]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low > high)
    {
        return;
    }
    int pIndex = Partition(arr, low, high);
    quickSort(arr, low, pIndex - 1);
    quickSort(arr, pIndex + 1, high);
}

int main()
{

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        vector<int> arr;
        int n;
        cin >> n;
        while (n--)
        {
            int number;
            cin >> number;
            arr.push_back(number);
        }
        quickSort(arr, 0, arr.size()-1);
        for (int i : arr)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        arr.clear();
    }

    return 0;
}