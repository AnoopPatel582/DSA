#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums){
    unordered_set<int>us(nums.begin(),nums.end());
    int max_length=0;
    for(int x:us){
        if(!(us.contains(x-1))){
            int count=0;
            int i=0;
            while(us.contains(x+i)){
                count++;
                i++;
            }
            max_length = max(max_length, count);
        }
    }
    return max_length;
}

int main(){
    int n;
    cout<<"Enter the number of elements in array:";
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
    int max_length=longestConsecutive(nums);
    cout<<"The maximum length of consecutive array is "<<max_length;
    return 0;
}