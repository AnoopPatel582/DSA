#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements of array:";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"The entered array is: ";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    // int count,majority;
    // for(int i=0;i<n/2;i++){
    //     count=0;
    //     majority=nums[i];
    //     for(int j=0;j<n;j++){
    //         if(nums[j]==majority){
    //             count++;
    //         }
    //         if(count>n/2){
    //             return majority;
    //         }
    //     }
    // }

    //boyer-moore voting algorithm
    int count=0,candidate;
    for(int i=0;i<n;i++){
        if(count==0){
            candidate=nums[i];
            count++;
        }else if(nums[i]==candidate){
            count++;
        }else{
            count--;
        }
    }
    cout<<"\nThe majority element is: "<<candidate<<endl;
    return 0;
}