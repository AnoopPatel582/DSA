#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&arr,int st, int mid,int end){
    int i=st,j=mid+1;
    vector<int>temp;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    //Rest left half
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    //Rest right half
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    //copying temp into original array
    for(int idx=0;idx<temp.size();idx++){
        arr[idx+st]=temp[idx];
    }
}

void mergeSort(vector<int>&arr,int st,int ed){
    if(st<ed){
        int mid=st+(ed-st)/2;
        mergeSort(arr,st,mid);
        mergeSort(arr,mid+1,ed);
        merge(arr,st,mid,ed);
    }
}

int main(){
    vector<int>arr={12,31,35,8,32,17,4,10};
    mergeSort(arr,0,arr.size()-1);
    for(int val:arr){
        cout<<val<<" ";
    }
    return 0;
}