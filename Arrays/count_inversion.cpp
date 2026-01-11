#include<iostream>
#include<vector>
using namespace std;
//brute force approach O(n^2)
// int main(){
//     int n;
//     cout<<"Enter number of elements:";
//     cin>>n;
//     vector<int>arr(n);
//     cout<<"Enter elements:";
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     cout<<"Entered array is:";
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     int inv_count=0;
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i]>arr[j])
//                 inv_count++;
//         }
//     }
//     cout<<"\nNumber of inversions are:"<<inv_count;
//     return 0;
// }

//optimized approach using merge sort O(nlogn)
int merge(vector<int>&arr,int st,int mid,int end){
    int count=0;
    vector<int>temp;
    int i=st,j=mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            count+=(mid-i+1);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int idx=0;idx<temp.size();idx++){
        arr[st+idx]=temp[idx];
    }
    return count;
}

int mergeSort(vector<int>&arr,int st,int end){
    int count=0;
    if(st>=end) return 0;
    if(st<end){
        int mid=st+(end-st)/2;
        count+=mergeSort(arr,st,mid);
        count+=mergeSort(arr,mid+1,end);
        count+=merge(arr,st,mid,end);
    }
    return count;
}

int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Entered array is:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    int inv_count=mergeSort(arr,0,n-1);
    cout<<"\nNumber of inversions are:"<<inv_count;
    return 0;
}