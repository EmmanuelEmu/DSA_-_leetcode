#include <bits/stdc++.h>
using namespace std;


long long int merge(std::vector<long long> &vec, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    long long int inv_count = 0;

    // Create temporary vectors
    std::vector<long long> leftVec(n1);
    std::vector<long long> rightVec(n2);

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
            inv_count += n1 - i+1;
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

    return inv_count;
}

// Function to implement merge sort
long long int mergeSort(std::vector<long long> &vec, int left, int right)
{
    int inv_count = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        inv_count += mergeSort(vec, left, mid);
        inv_count += mergeSort(vec, mid + 1, right);
        // Merge the sorted halves
        inv_count +=merge(vec, left, mid, right);
    } 
    return inv_count;
}

long long int inversionCount(vector<long long> &arr)
{
    return mergeSort(arr, 0, arr.size() - 1);
}

int main()
{

    return 0;
}