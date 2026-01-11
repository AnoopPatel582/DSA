#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// leetcode problem number 88
int main()
{
    int n, m;
    cout << "Enter the number of elements in nums1:";
    cin >> m;
    cout << "Enter the number of elements in nums2:";
    cin >> n;
    vector<int> nums1(m + n, 0);
    vector<int> nums2(n, 0);
    cout << "Enter the elements of nums1:";
    for (int i = 0; i < m; i++)
        cin >> nums1[i];
    cout << "Enter the elements of nums2:";
    for (int i = 0; i < n; i++)
        cin >> nums2[i];
    cout << "Array nums1:";
    for (int i = 0; i < m; i++)
        cout << nums1[i] << " ";
    cout << endl;
    cout << "Array nums2:";
    for (int i = 0; i < n; i++)
        cout << nums2[i] << " ";
    cout << endl;
    // for(int i=m,j=0;i<m+n;i++,j++)
    //     nums1[i]=nums2[j];
    // sort(nums1.begin(),nums1.end()); this approach takes O((m+n)log(m+n)) time complexity
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (j >= 0)
    {
        if (i >= 0 && nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    cout << "Array after merging:";
    for (int i = 0; i < m + n; i++)
        cout << nums1[i] << " ";
    cout << endl;
    return 0;
}