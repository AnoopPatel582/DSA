#include <iostream>
#include <vector>
using namespace std;

// O(m+n) approach
//  int main(){
//      int m,n;

//     cout<<"Enter number of rows (m):";
//     cin>>m;
//     cout<<"Enter number of columns (n):";
//     cin>>n;
//     vector<int> row(m, 0);
//     vector<int> col(n, 0);
//     vector<vector<int>> matrix(m,vector<int>(n));
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cin>>matrix[i][j];
//         }
//     }
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             if(matrix[i][j]==0){
//                 row[i]=1;
//                 col[j]=1;
//             }
//         }
//     }
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             if(row[i]==1||col[j]==1){
//                 matrix[i][j]=0;
//             }
//         }
//     }
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cout<<matrix[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// brute force approach
//  int main(){
//      int m,n;
//      cout<<"Enter number of rows (m):";
//      cin>>m;
//      cout<<"Enter number of columns (n):";
//      cin>>n;
//      vector<vector<int>> matrix1(m,vector<int>(n));
//      vector<vector<int>> matrix2(m,vector<int>(n));
//      for(int i=0;i<m;i++){
//          for(int j=0;j<n;j++){
//              cin>>matrix1[i][j];
//              matrix2[i][j]=matrix1[i][j];
//          }
//      }
//      for(int i=0;i<m;i++){
//          for(int j=0;j<n;j++){
//              if(matrix2[i][j]==0){
//                  for(int k=0;k<m;k++){
//                      matrix1[k][j]=0;
//                  }
//                  for(int k=0;k<n;k++){
//                      matrix1[i][k]=0;
//                  }
//              }
//          }
//      }
//      for(int i=0;i<m;i++){
//          for(int j=0;j<n;j++){
//              cout<<matrix1[i][j]<<" ";
//          }
//          cout<<endl;
//      }
//      return 0;
//  }

// Optimised space complexity O(1)
int main()
{
    int m, n;
    bool firstcol = false;
    cout << "Enter number of rows (m):";
    cin >> m;
    cout << "Enter number of columns (n):";
    cin >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] == 0)
        {
            firstcol = true;
        }
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    if (m > 0 && n > 0 && matrix[0][0] == 0)
    {
        for (int j = 0; j < n; ++j)
            matrix[0][j] = 0;
    }

    if (firstcol)
    {
        for (int i = 0; i < m; ++i)
            matrix[i][0] = 0;
    }
    cout << "Modified Matrix is:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}