#include<iostream>
#include<vector>
using namespace std;

int secLargest(vector<int>&arr){
    if(arr.size()<2){
        return -1;
    }
    int largest=arr[0];
    int secLarge=INT_MIN;
    bool found2large=false;
    for(int i=1;i<arr.size();i++){
        if(largest<arr[i]){
            secLarge=largest;
            largest=arr[i];
            found2large=true;
        }else if(largest>arr[i] && secLarge<arr[i]){
            secLarge=arr[i];
            found2large=true;
        }
    }
    if(found2large==false){
        return -1;
    }
    return secLarge;
}

int main(){
    vector<int>arr={5,-1};
    int secLarge=secLargest(arr);
    if(secLarge==-1){
        cout<<"There is no valid 2nd largest element in the array.";
    }else{
        cout<<"Second Largest element of the array:"<<secLarge;
    }
}