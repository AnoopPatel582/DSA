#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char>st;
    int left=0,right=0;
    int max_length=0;
    while(right<s.size()){
        if(!(st.contains(s[right]))){
            st.insert(s[right]);
            right++;
        }else{
            st.erase(s[left]);
            left++;
        }
        max_length=max(max_length,right-left);
    }
    return max_length;
}

int main(){
    string s;
    cout<<"Enter the string:";
    cin>>s;
    int max_length=lengthOfLongestSubstring(s);
    cout<<"\nThe maximum length of the string is "<<max_length;
    return 0;
}