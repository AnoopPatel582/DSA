#include <iostream>
#include <vector>
using namespace std;
class ZAlgorithm
{
private:
    vector<int>CalculateZ(const string& input){
        int n=input.length();
        vector<int>z(n,0);
        int left=0,right=0;
        for(int i=1;i<n;i++){
            if(i>right){
                left=right=i;
                while(right<n && input[right]==input[right-left]){
                    right++;
                }
                z[i]=right-left;
                right--;
            }else{
                int i1=i-left;
                if(z[i1]<right-i+1){
                    z[i]=z[i1];
                }else{
                    left=i;
                    while(right<n && input[right]==input[right-left]){
                        right++;
                    }
                    z[i]=right-left;
                    right--;
                }
            }
        }
        return z;
    }
public:
    vector<int> matchPattern(const string &text, const string &pattern)
    {
        string newStr = pattern + '$' + text;
        vector<int> result;
        vector<int> Z = CalculateZ(newStr);
        int patternLen = pattern.length();
        for (int i = 0; i < newStr.size(); i++)
        {
            if (Z[i] == patternLen)
            {
                result.push_back(i - patternLen - 1);
            }
        }
        return result;
    }
};

int main()
{
    string text = "aaabcxyzaaabczaacz";
    string pattern = "aaabc";
    ZAlgorithm zAlgorithm;
    vector<int> result = zAlgorithm.matchPattern(text, pattern);
    for (int index : result)
    {
        cout << index << "\n";
    }
    return 0;
}