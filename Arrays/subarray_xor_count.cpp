#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarray_xor_counter(vector<int>A, int K){
    //brute force approach is to find the xor of everypossible subarray by nested loop which cause the time complexity O(n2)
    //Optimal approach by using prefix XOR
    unordered_map<int, int> freq;
    
    int currXor = 0;
    int count = 0;
    
    freq[0] = 1;
    
    for (int i = 0; i < A.size(); i++) {
        currXor ^= A[i];
        
        int need = currXor ^ K;
        
        if (freq.find(need) != freq.end()) {
            count += freq[need];
        }
        
        freq[currXor]++;
    }
    
    return count;

}

int main(){
    int n;
    cout<<"Enter the number of elements in array:";
    cin>>n;
    cout<<"Enter the elements of array:";
    vector<int>A(n,0);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int k;
    cout<<"Enter the xor target element:";
    cin>>k;
    int xor_count=subarray_xor_counter(A,k);
    cout<<"The total number of subarray: "<<xor_count;
    return 0;
}