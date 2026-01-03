#include<iostream>
using namespace std;

int main(){
    double x;
    int n;
    cout<<"Enter the base:";
    cin>>x;
    cout<<"Enter the exponent:";
    cin>>n;
    double pow=1.0;
    // if(n>=0){
    //     for(int i=0;i<n;i++){
    //         pow=pow*x;
    //     }
    //     cout<<"Power of "<<x<<"^"<<n<<" is "<<pow<<endl;
    // }else{
    //     for(int i=0;i<abs(n);i++){
    //         pow=pow*(1/x);
    //     }
    //     cout<<"Power of "<<x<<"^"<<n<<" is "<<pow<<endl;
    // }

    //optimized approach
    cout<<"Power of "<<x<<"^"<<n<<" is ";
    long long power = n;   // prevent overflow
    double result = 1.0;
    if (power < 0) {
        x = 1 / x;
        power = -power;
    }
    while (power > 0) {
        if (power % 2 == 1) {
            result *= x;
        }
        x *= x;
        power /= 2;
    }
    cout << result << endl;
    return 0;
}