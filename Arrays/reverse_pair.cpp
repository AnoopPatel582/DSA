#include <iostream>
#include <vector>
using namespace std;

// Brute force approach time complexity O(n^2) and space complexity O(1)
// int reversePairs(vector<int>& nums){
//     int count=0;
//     for(int i=0;i<nums.size();i++){
//         for(int j=i+1;j<nums.size();j++){
//             if(nums[i]>2*nums[j]){
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// Merge sort approach time complexity O(n log n) and space complexity O(n)
int merge(vector<int> &nums, int st, int mid, int end)
{
    long long count = 0;
    int j = mid + 1;
    vector<int> temp;
    for (int i = st; i <= mid; i++)
    {

        while (j <= end && nums[i] > 2LL * nums[j])
        {
            j++;
        }
        count += (j - (mid + 1));
    }

    int i = st;
    j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (nums[i] <= nums[j])
        {
            temp.push_back(nums[i]);
            i++;
        }
        else
        {
            temp.push_back(nums[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(nums[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(nums[j]);
        j++;
    }
    for (int idx = 0; idx < temp.size(); idx++)
    {
        nums[st + idx] = temp[idx];
    }
    return count;
}

int mergeSort(vector<int> &nums, int st, int end)
{
    int count = 0;
    if (st >= end)
        return 0;
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        count += mergeSort(nums, st, mid);
        count += mergeSort(nums, mid + 1, end);
        count += merge(nums, st, mid, end);
    }
    return count;
}

int reversePairs(vector<int> &nums, int st, int end)
{
    return mergeSort(nums, st, end);
}

int main()
{
    int n;
    cout << "Enter number of elements:";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "The entered array is:";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    int result = reversePairs(nums, 0, n - 1);
    cout << "\nNumber of reverse pairs are:" << result;
    return 0;
}