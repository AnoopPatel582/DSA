#include<iostream>
#include<vector>
#include <utility>
using namespace std;

// color sort leedcode problem number 75
//cout->rewrite soltion
// int main(){
//     int n;
//     cout<<"Enter number of elements in array:";
//     cin>>n;
//     vector<int>nums(n,0);
//     cout<<"Enter elememts of array:";
//     for(int i=0;i<n;i++){
//         cin>>nums[i];
//     }
//     cout<<"Array before sorting:";
//     for(int i=0;i<n;i++){
//         cout<<nums[i]<<" ";
//     }
//     cout<<endl;
//     int low=0,min=0;
//     for(int i=0;i<n;i++){
//         if(nums[i]==0) low++;
//         else if(nums[i]==1) min++;
//     }
//     for(int i=0;i<n;i++){
//         if(i<low) nums[i]=0;
//         else if(i<low+min) nums[i]=1;
//         else nums[i]=2;
//     }
//     cout<<"Array after sorting:";
//     for(int i=0;i<n;i++){
//         cout<<nums[i]<<" ";
//     }
//     return 0;
// }

//Dutch National Flag Algorithm
int main(){
    int n;
    cout<<"Enter number of elements in array:";
    cin>>n;
    vector<int>nums(n,0);
    cout<<"Enter elememts of array:";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Array before sorting:";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
    cout<<"Array after sorting:";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}