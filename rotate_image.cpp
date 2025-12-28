#include<iostream>
#include<vector>
#include<utility>
using namespace std;

// leetcode problem number 48
 int main(){
    int n;
    cout<<"Enter number of rows and columns (n):";
    cin>>n;
    vector<int> row(n, 0);
    vector<int> col(n, 0);
    vector<vector<int>> matrix(n,vector<int>(n));
    cout<<"Enter elements of matrix:";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"Matrix before rotation:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            swap(matrix[i][j],matrix[i][n-1-j]);
        }
    }
    cout<<"Matrix after rotation:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
 }