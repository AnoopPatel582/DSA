// #include<iostream>
// #include <vector>
// using namespace std;

// int main(){
//     int numRows;
//     cout<<"Enter number of rows:";
//     cin>>numRows;
//     vector<vector<int>> matrix(numRows,vector<int>(numRows,0));
//     for(int i=0;i<numRows;i++){
//         for(int j=0;j<=i;j++){
//             if(j!=0 && j!=i){
//                 matrix[i][j]=matrix[i-1][j-1]+matrix[i-1][j];
//                 cout<<matrix[i][j]<<" ";
//             }else{
//                 matrix[i][j]=1;
//                 cout<<matrix[i][j]<<" ";
//             }

//         }
//         cout<<endl;
//     }
//     return 0;
// }


// Optimized Code
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int numRows;
//     cout << "Enter number of rows: ";
//     cin>> numRows;
//     if (numRows <= 0) return 0;

    // vector<vector<int>> triangle;
    // triangle.reserve(numRows);

    // for (int i = 0; i < numRows; ++i) {
    //     vector<int> row(i + 1, 1);          
    //     for (int j = 1; j < i; ++j) {      
    //         row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
    //     }
    //     triangle.push_back(move(row));
    // }

//     for (const auto &r : triangle) {
//         for (int x : r) cout << x << ' ';
//         cout << '\n';
//     }
//     return 0;
// }

//Space comlexity O(1) solution this is not optimized
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int numRows;
//     cout << "Enter number of rows: ";
//     cin>> numRows;
//     if (numRows <= 0) return 0;

//     vector<vector<int>> triangle;
//     triangle.reserve(numRows);
//     vector<int> cur;
//     cur.reserve(numRows);
//     for (int i = 0; i < numRows; ++i) {
//         cur.push_back(1);          
//         for(int j=i-1;j>=1;--j){
//             cur[j]=cur[j]+cur[j-1];
//         }
//         triangle.push_back(cur);
//     }

//     for (const auto &r : triangle) {
//         for (int x : r) cout << x << ' ';
//         cout << '\n';
//     }
//     return 0;
// }


#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    if (numRows <= 0) return ans;

    vector<int> cur;            // single working row
    cur.reserve(numRows);       // optional: avoid reallocations

    for (int i = 0; i < numRows; ++i) {
        cur.push_back(1);               // add rightmost 1 for the new row
        // update inner values from right to left
        for (int j = i - 1; j >= 1; --j) {
            cur[j] = cur[j] + cur[j - 1];
        }
        ans.push_back(cur);             // store a copy for output
    }
    return ans;
}

int main() {
    int numRows;
    cout << "Enter number of rows: ";
    if (!(cin >> numRows) || numRows <= 0) return 0;

    auto triangle = generate(numRows);
    for (const auto &r : triangle) {
        for (int x : r) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
