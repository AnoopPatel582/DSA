#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void subsetSum(vector<int>&arr,vector<int>&subset,vector<int>&ans,int i){
    if(i==arr.size()){
        int sum=0;
        for(int val:subset){
            sum+=val;
        }
        ans.push_back(sum);
        return;
    }
    subset.push_back(arr[i]);
    subsetSum(arr,subset,ans,i+1);
    subset.pop_back();
    subsetSum(arr,subset,ans,i+1);

}

int main(){
    vector<int> arr={5,2,1};
    vector<int>subset;
    vector<int>ans;
    subsetSum(arr,subset,ans,0);
    sort(ans.begin(),ans.end());
    for(int sum: ans){
        cout<<sum<<" ";
    }
}

