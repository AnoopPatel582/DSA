#include<iostream>
#include<vector>
using namespace std;

// Brute force approach time and space complexity O(m*n)
// int uniquePaths(int m, int n){
//     vector<vector<int>> dp(m, vector<int>(n,0));
//     for(int i=1;i<m;i++){
//         for(int j=1;j<n;j++){
//             dp[i][0]=1;
//             dp[0][j]=1;
//             dp[i][j]=dp[i-1][j]+dp[i][j-1];
//         }
//     }
//     return dp[m-1][n-1];
// }

// Optimized approach time complexity O(m*n) and space complexity O(n)
// int uniquePaths(int m, int n){
//     vector<int> dp(n,1);
//     for(int i=1;i<m;i++){
//         for(int j=1;j<n;j++){
//             dp[j]=dp[j]+dp[j-1];
//         }
//     }
//     return dp[n-1];
// }

// Combinatorial approach time complexity O(min(m,n)) and space complexity O(1)
int uniquePaths(int m, int n){
    int N=m+n-2;
    int r=min(m-1,n-1);
    long long int res=1;
    for(int i=1;i<=r;i++){
        res*=(N-r+i);
        res/=i;
    }
    return res;
}
int main(){
    int m,n;
    cout<<"Enter number of rows and columns:";
    cin>>m>>n;
    int result=uniquePaths(m,n);
    cout<<"Number of unique paths are:"<<result;
    return 0;
}