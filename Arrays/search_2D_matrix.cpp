#include<iostream>
#include<vector>
using namespace std;
// leetcode problem number 74
int main(){
    int m,n,target;
    cout<<"Enter the number of rows:";
    cin>>m;
    cout<<"Enter the number of columns:";
    cin>>n;
    vector<vector<int>> matrix(m,vector<int>(n,0));
    cout<<"Enter the elements of the matrix:";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"Matix:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter the target element to be searched:";
    cin>>target;
    int low=0,high=m*n-1,mid,row,col;
    while(low<=high){
        mid=(low+high)/2;
        row=mid/n;
        col=mid%n;
        if(matrix[row][col]==target){
            cout<<"true"<<endl;
            break;
        }
        else if(matrix[row][col]>target){
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    return 0;
}