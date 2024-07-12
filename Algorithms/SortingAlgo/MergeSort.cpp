#include <bits/stdc++.h>
using namespace std;

// Function to merge two halves
void merge(std::vector<int> &vec, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors
    std::vector<int> leftVec(n1);
    std::vector<int> rightVec(n2);

    // Copy data to temporary vectors leftVec and rightVec
    for (int i = 0; i < n1; ++i)
    {
        leftVec[i] = vec[left + i];
    }
    for (int j = 0; j < n2; ++j)
    {
        rightVec[j] = vec[mid + 1 + j];
    }

    // Merge the temporary vectors back into vec[left..right]
    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (leftVec[i] <= rightVec[j])
        {
            vec[k] = leftVec[i];
            ++i;
        }
        else
        {
            vec[k] = rightVec[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of leftVec, if there are any
    while (i < n1)
    {
        vec[k] = leftVec[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of rightVec, if there are any
    while (j < n2)
    {
        vec[k] = rightVec[j];
        ++j;
        ++k;
    }
}

// Function to implement merge sort
void mergeSort(std::vector<int> &vec, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        // Merge the sorted halves
        merge(vec, left, mid, right);
    }
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
            int num;
            cin >> num;
            arr.push_back(num);
        }
        mergeSort(arr, 0, arr.size() - 1);
        for (int i : arr)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        arr.clear();
    }

    return 0;
}
