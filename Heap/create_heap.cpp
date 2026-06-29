#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void heapify(vector<int>&arr,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<arr.size()&& arr[left]>arr[largest]){
        largest=left;
    }
    if(right<arr.size()&& arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,largest);
    }
}
void create_heap(vector<int>&arr){
    int n=arr.size();
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,i);
    }
}
void insertion_heap(vector<int>&arr,int value){
    arr.push_back(value);
    int child=arr.size()-1;
    while(child>0){
        int parent=(child-1)/2;
        if(arr[child]>arr[parent]){
            swap(arr[parent],arr[child]);
            child=parent;
        }else{
            break;
        }
    }

}
void deletion_heap(vector<int>&arr){
    int i=0;
    int n=arr.size();
    while(i<(n/2)-1){
        int left=2*i+1;
        int right=2*i+2;
        if(arr[left]>arr[right]){
            arr[i]=arr[left];
        }else{
            arr[i]=arr[right];
        }
        i++;
    }
    while(i<n-1){
        arr[i+1]=arr[i+2];
        i++;
    }
}

int main(){
    vector<int>arr={10,20,15,30,40,50};
    cout<<"Original Array:";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    create_heap(arr);
    cout<<"Max heap array:";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int x;
    cout<<"Enter the element to insert:";
    cin>>x;
    insertion_heap(arr,x);
    cout<<"Array after insertion:";
    for(int num:arr){
        cout<<num<<" ";
    }
    cout<<endl;
    deletion_heap(arr);
    cout<<"Array after deletion:";
    for(int num:arr) cout<<num<<" ";
    return 0;
}

