#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long n;
    cout<<"Enter the size of array:";
    cin>>n;
    vector<int> nums(n,0);
    cout<<"Enter the elements of array (numbers from 1 to n with one missing and one repeating):";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"The entered array is: ";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    //brute force approach
    // int count,missing,repeating;
    // for(int i=1;i<=n;i++){
    //     count=0;
    //     for(int j=0;j<n;j++){
    //         if(nums[j]==i){
    //             count++;
    //         }
    //     }
    //     if(count==2)
    //         repeating=i;
    //     else if(count==0)
    //         missing=i;
    // }
    // cout<<"\nThe repeating element is: "<<repeating<<endl;
    // cout<<"The missing element is: "<<missing<<endl;

    //optimized approach
    long long repeating,missing,sum1=0,sum2=0,sum3=0,sum4=0;
    for(int i=0;i<n;i++){
        sum1+=nums[i];
        sum3+=nums[i]*nums[i];
    }
    sum2=(n*(n+1))/2;
    sum4=(n*(n+1)*(2*n+1))/6;
    long long diff1=sum1 - sum2;
    long long diff2=sum3 - sum4;
    long long sum=diff2/diff1;
    repeating=(diff1 + sum)/2;
    missing=sum - repeating;
    cout<<"\nThe repeating element is: "<<repeating<<endl;  
    cout<<"The missing element is: "<<missing<<endl;
    return 0;
}