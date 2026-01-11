#include<iostream>
#include <unordered_map>
using namespace std;

//optimized approach using hashmap
int main(){
    int nums[4]={2,7,11,15};
    int target=26;
    unordered_map<int,int>mp;
    for(int i=0;i<4;i++){
        if(mp.find(target-nums[i])!=mp.end()){
            cout<<"The two sum indices are:"<<mp[target-nums[i]]<< " and "<<i;
            break;
        }else{
            mp[nums[i]]=i;
        }
    }
    return 0;
}

// Brute Force
// int main(){
//     int nums[4]={2,7,11,15};
//     int target=26;
//     for(int i=0;i<4;i++){
//         for (int j=i+1;j<4;j++){
//             if(nums[i]+nums[j]==target){
//                 cout<<"The two sum indices are: "<<i<<" and "<<j;
//             }
//         }
//     }
// }