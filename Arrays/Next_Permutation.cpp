#include<iostream>
#include<vector>
using namespace std;

//self try to find the next permutation but it is incorrect
// int main(){
//     int n,k=0;
//     cout<<"Enter the number of elements in array:";
//     cin>>n;
//     vector<int>nums(n,0);
//     for(int i=0;i<n;i++){
//         cin>>nums[i];
//     }
//     cout<<"Array before next permutation:";
//     for(int i=0;i<n;i++){
//         cout<<nums[i]<<" ";
//     }
//     cout<<endl;
//     for(int i=n-1;i>0;i--){
//         if(nums[i]>nums[i-1]){
//             k=nums[i-1];
//             nums[i-1]=nums[i];
//             nums[i]=k;
//             break;
//         }else if(nums[i-2]>nums[i-1]&&i-3==0){
//             k=nums[i-2];
//             nums[i-2]=nums[i];
//             nums[i]=k;
//             break;
//         }else if(nums[i-2]>nums[i-1]&&i-3!=0){
//             k=nums[i];
//             nums[i]=nums[i-2];
//             nums[i-2]=nums[i-3];
//             nums[i-3]=k;
//             break;
//         }else{
//             k=nums[i-2];
//             nums[i-2]=nums[i-1];
//             nums[i-1]=nums[i];
//             nums[i]=k;
//             break;
//         }
//     }
//     cout<<"Array after next permutation:";
//     for(int i=0;i<n;i++){
//         cout<<nums[i]<<" ";
//     }
//     return 0;
// }

//Standard 3-step next permutation algorithm
int main(){
    int n,k=0,i;
    cout<<"Enter the number of elements in array:";
    cin>>n;
    vector<int>nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Array before next permutation:";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    for(i=n-1;i>0;i--){
        if(nums[i-1]<nums[i]){
            for(int j=n-1;j>0;j--){
                if(nums[j]>nums[i-1]){
                    k=nums[i-1];
                    nums[i-1]=nums[j];
                    nums[j]=k;
                    break;
                }
            }
            break;
        }
    }
    int l = i , r = n - 1;
    while (l < r) {
        swap(nums[l], nums[r]);
        l++;
        r--;
    }
    cout<<"Array after next permutation:";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}