#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// leetcode problem number 287
int main()
{
    int n;
    cout << "Enter the number of elements in the array:";
    cin >> n;
    vector<int> nums(n, 0);
    cout << "Enter the elements of the array:";
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << "Array elements are:";
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    cout << endl;
    // Brute force
    // time complexity O(n^2) and space complexity O(1)
    int duplicate;
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (nums[i] == nums[j])
            {
                duplicate = nums[i];
                break;
            }
        }
    }
    // time complexity O(nlogn) and space complexity O(1)
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            duplicate = nums[i];
            break;
        }
    } // time complexity O(n) and space complexity O(n)
    unordered_map<int, int> seen;
    for (int i = 0; i <= n; i++)
    {
        if (seen.find(nums[i]) != seen.end())
        {
            duplicate = nums[i];
            break;
        }
        else
        {
            seen[nums[i]] = i;
        }
    }
    cout << "The duplicate element is: " << duplicate << endl;
    // Optimal approach
    // Floyd's Tortoise and Hare (Cycle Detection)
    int slow = nums[0];
    int fast = nums[0];

    // Phase 1: Detect cycle
    do
    {
        slow = nums[slow];       // move 1 step
        fast = nums[nums[fast]]; // move 2 steps
    } while (slow != fast);

    // Phase 2: Find entry point of cycle
    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow; // duplicate number
}