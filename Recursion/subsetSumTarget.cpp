#include<iostream>
#include<vector>
using namespace std;

void isSubsetSum(vector<int>&arr,vector<int>&subset,int target,int i,bool &k){
    if(k) return;
    if(i==arr.size()){
        int sum=0;
        for(int val:subset){
            sum+=val;
        }
        if(sum==target){
            k=true;
        }
        return;
    }
    subset.push_back(arr[i]);
    isSubsetSum(arr,subset,target,i+1,k);
    subset.pop_back();
    isSubsetSum(arr,subset,target,i+1,k);
}
int main(){
    vector<int>arr={1,2,7,3};
    vector<int>subset;
    bool k=false;
    isSubsetSum(arr,subset,5,0,k);
    cout<<k;
}