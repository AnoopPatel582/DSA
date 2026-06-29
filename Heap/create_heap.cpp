#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void create_heap(vector<int>&arr){
    int n=arr.size();
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,n,i);
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
    if(arr.empty()) return;
    arr[0]=arr.back();
    arr.pop_back();
    if(!arr.empty()){
        heapify(arr,arr.size(),0);
    }
}

void heap_sort(vector<int>&arr){
    int n=arr.size();
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
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
    cout<<endl;
    heap_sort(arr);
    cout<<"Array after heap sort:";
    for(int num:arr) cout<<num<<" ";
    return 0;
}

