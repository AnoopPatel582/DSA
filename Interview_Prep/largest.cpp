#include<iostream>
#include<vector>
using namespace std;

int maxOfArr(vector<int>&arr){
    int max_ele=arr[0];
    for(int i=0;i<arr.size();i++){
        if(max_ele<arr[i]){
            max_ele=arr[i];
        }
    }
    return max_ele;
}

int main(){
    vector<int> arr={1,2,6,3,8,20};
    int max_ele=maxOfArr(arr);
    cout<<"Maximum elements of the arrar:"<<max_ele;
}