#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int>findDuplicate(vector<int>&arr){
    unordered_map<int,int>dupl_map;
    vector<int>duplicate;
    for(int i=0;i<arr.size();i++){
        dupl_map[arr[i]]++;
    }
    for(const auto &[ele,freq]:dupl_map){
        if(freq>1){
            duplicate.push_back(ele);
        }
    }
    return duplicate;
}


int main(){
    vector<int> arr={1};
    vector<int>duplicate=findDuplicate(arr);
    cout<<"Duplicate elements:";
    for(int i=0;i<duplicate.size();i++){
        cout<<duplicate[i]<<" ";
    }
}