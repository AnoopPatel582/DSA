#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// leetcode problem number 56
int main(){
    int n;
    cout<<"Enter the number of intervals:";
    cin>>n;
    vector<vector<int>>intervals;
    cout<<"Enter the intervals (start end):";
    for(int i=0;i<n;i++){
        int start,end;
        cin>>start>>end;
        intervals.push_back({start,end});
    }
    for(auto interval:intervals){
        cout<<"["<<interval[0]<<","<<interval[1]<<"] ";
    }
    cout<<endl;
    sort(intervals.begin(),intervals.end(),
        [](vector<int>& a, vector<int>& b){
            return a[0]<b[0];
        }
    );
    cout<<"Intervals after sorting:";
    for(auto interval:intervals){
        cout<<"["<<interval[0]<<","<<interval[1]<<"] ";
    }
    cout<<endl;
    vector<vector<int>>merged;
    merged.push_back(intervals[0]);
    for(int i=1;i<n;i++){
        if(intervals[i][0]<=merged.back()[1]){
            merged.back()[1]=max(merged.back()[1],intervals[i][1]);
        }
        else{
            merged.push_back(intervals[i]);
        }
    }
    cout<<"Merged intervals:";
    for(auto interval:merged){
        cout<<"["<<interval[0]<<","<<interval[1]<<"] ";
    }
}