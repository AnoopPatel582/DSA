#include<iostream>
#include<vector>
using namespace std;

//Brute force approach
// int main(){
//     int n,maxProfit=0;
//     cout<<"Enter the number of elements of array:";
//     cin>>n;
//     cout<<"Enter the elements of array:";
//     vector<int>prices(n,0);
//     for(int i=0;i<n;i++){
//         cin>>prices[i];
//     }
//     cout<<"Entered array:";
//     for(int i=0;i<n;i++){
//         cout<<prices[i]<<" ";
//     }
//     cout<<endl;
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             maxProfit=max(maxProfit,prices[j]-prices[i]);
//         }
//     }
//     cout<<"The maximum profit is "<<maxProfit;
//     return 0;
// }

//Optimized solution for this problem
int main(){
    int n,maxProfit=0,minPrice;
    cout<<"Enter the number of elements of array:";
    cin>>n;
    cout<<"Enter the elements of array:";
    vector<int>prices(n,0);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    cout<<"Entered array:";
    for(int i=0;i<n;i++){
        cout<<prices[i]<<" ";
    }
    cout<<endl;
    minPrice=prices[0];
    for(int i=0;i<n;i++){
        minPrice=min(minPrice,prices[i]);
        maxProfit=max(maxProfit,prices[i]-minPrice);
    }
    cout<<"The maximum profit is "<<maxProfit;
    return 0;
}
//leetcode problem number 121
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=prices[0],maxProfit=0;
        for(int i=0;i<prices.size();i++){
            minPrice=min(minPrice,prices[i]);
            maxProfit=max(prices[i]-minPrice,maxProfit);
        }
        return maxProfit;
    }
};