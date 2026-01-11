#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//Brute Force with time complexity 0(n^3) and space 0(1)
// int longest_subarray(vector<int>array){
//     cout<<"The entered array:";
//     int n=array.size();
//     for(int i=0;i<n;i++){
//         cout<<array[i]<<" ";
//     }
//     int m=n-1;
//     while(m>1){
//         int left=0,right=m;
//         while(left!=right && right<n){
//             int i=left,sum=0;
//             while(i<=right){
//                 sum+=array[i];
//                 i++;
//             }
//             if(sum==0){
//                 return m+1;
//             }
//             else{
//                 left++;
//                 right++;
//             }
//         }
//         m--;
//     }
//     return 0;
// }

//Brute force with time complexity 0(n^2) and space 0(1)
// int longest_subarray(vector<int>array){
//     int max_length=0,sum=0;
//     for(int i=0;i<array.size();i++){
//         for(int j=i;j<array.size();j++){
//             sum+=array[j];
//             if(sum==0){
//                 max_length=max(max_length,j-i+1);
//             }
//         }
//         sum=0;
//     }
//     return max_length;
// }


//Optimal solution using hash map time complexity O(n) and space complexity O(n)
int longest_subarray(vector<int>array){
    unordered_map<int,int>mp;
    int prefix_sum=0,max_length=0;
    for(int i=0;i<array.size();i++){
        prefix_sum+=array[i];
        if(prefix_sum==0){
            max_length = max(max_length, i + 1);
        }else if(mp.find(prefix_sum)!=mp.end()){
            int length=i-mp[prefix_sum];
            max_length=max(max_length,length);
        }else {
            mp[prefix_sum]=i;
        }
    }
    return max_length;
}

int main(){
    int n;
    cout<<"Enter the number of elements in array:";
    cin>>n;
    vector<int>array(n,0);
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int max_subarray=longest_subarray(array);
    cout<<"\nThe length of the longest subarray: "<<max_subarray;
}