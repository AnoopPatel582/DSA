#include<iostream>
#include<climits>
#include<vector>
using namespace std;

//O(n3) solution
// int main(){
//     int n,start=0,end=0,maxSum=INT_MIN;
//     cout<<"Enter number of elements in array:";
//     cin>>n;
//     vector<int>nums(n,0);
//     cout<<"Enter elements of array:";
//     for(int i=0;i<n;i++){
//         cin>>nums[i];
//     }
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             int sum=0;
//             for(int k=i;k<=j;k++){
//                 sum+=nums[k];
//             }
//             if(sum>maxSum){
//                 maxSum=sum;
//                 start=i;
//                 end=j;
//             }
//         }
//     }
//     cout<<"The maximum sum of the subarray:"<<maxSum<<endl;
//     cout<<"The maximum subarray:";
//     for(int i=start;i<=end;i++){
//         cout<<nums[i]<<" ";
//     }
//     return 0;
// }

// O(n2) solution
// int main(){
//     int n,start=0,end=0,maxSum=INT_MIN;
//     cout<<"Enter number of elements in array:";
//     cin>>n;
//     vector<int>nums(n,0);
//     cout<<"Enter elements of array:";
//     for(int i=0;i<n;i++){
//         cin>>nums[i];
//     }
//     for(int i=0;i<n;i++){
//         int curSum=0;
//         for(int j=i;j<n;j++){
//             curSum+=nums[j];
//             if(curSum>maxSum){
//                 maxSum=curSum;
//                 start=i;
//                 end=j;
//             }
//         }
//     }
//     cout<<"The maximum sum of the subarray:"<<maxSum<<endl;
//     cout<<"The maximum subarray:";
//     for(int i=start;i<=end;i++){
//         cout<<nums[i]<<" ";
//     }
//     return 0;
// }

// O(n) solution - Kadane's Algorithm
int main(){
    int n,curSum=0,start=0,end=0,maxSum=INT_MIN;
    cout<<"Enter number of elements in array:";
    cin>>n;
    vector<int>nums(n,0);
    cout<<"Enter elements of array:";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    for(int i=0;i<n;i++){
        if(nums[i]>curSum+nums[i])start=i;
        curSum=max(nums[i],curSum+nums[i]);
        if(curSum>maxSum){
            maxSum=curSum;
            end=i;
        }
    }
    cout<<"The maximum sum of the subarray:"<<maxSum<<endl;
    cout<<"The maximum subarray:";
    for(int i=start;i<=end;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}