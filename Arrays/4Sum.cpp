#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums,int target){
    sort(nums.begin(),nums.end());
    cout<<"Sorted array:";
    int n=nums.size();
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    vector<vector<int>>result;
    long long sum=0;
    for(int i=0;i<=n-4;i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        for(int j=i+1;j<=n-3;j++){
            if(j>i+1 && nums[j]==nums[j-1]){
                continue;
            }
            int left=j+1,right=n-1;
            while(left<right){
                sum=1LL*nums[i]+nums[j]+nums[left]+nums[right];
                if(sum==target){
                    vector<int>quadruplet;
                    quadruplet.push_back(nums[i]);
                    quadruplet.push_back(nums[j]);
                    quadruplet.push_back(nums[left]);
                    quadruplet.push_back(nums[right]);
                    result.push_back(quadruplet);
                    while(left<right && nums[left]==nums[left+1])
                        left++;
                    while(left<right && nums[right]==nums[right-1])
                        right--;
                    left++;    
                    right--;                    
                }
                else if(sum<target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
    }
    return result;
}

int main(){
    int n;
    cout<<"Enter number of elements in array:";
    cin>>n;
    vector<int>nums(n,0);
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"The entered array:";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    int target;
    cout<<"\nEnter the target:";
    cin>>target;
    vector<vector<int>> result=fourSum(nums,target);
    cout<<"\nThe quadruplets are:";
    for(int i=0;i<result.size();i++){
        for(int j=0;j<4;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}