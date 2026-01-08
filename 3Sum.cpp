#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> result;
    long long sum = 0;
    for (int i = 0; i <= n - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int left = i + 1, right = n - 1;
        while (left < right)
        {
            sum = 1LL * nums[i] + nums[left] + nums[right];
            if (sum == 0)
            {
                vector<int> triplet;
                triplet.push_back(nums[i]);
                triplet.push_back(nums[left]);
                triplet.push_back(nums[right]);
                result.push_back(triplet);
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                left++;
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return result;
}

int main()
{
    int n;
    cout << "Enter number of elements in array:";
    cin >> n;
    vector<int> nums(n, 0);
    cout << "Enter the elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "The entered array:";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    vector<vector<int>> result = threeSum(nums);
    cout << "\nThe triplets are:";
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}