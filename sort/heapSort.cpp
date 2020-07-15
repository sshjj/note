#include<bits/stdc++.h>
using namespace std;

void adjust(vector<int>&arr,int len,int index){
    int left = index*2+1;
    int right =  index*2 +2;
    int maxIdx = index;
    if(left<len && arr[left]>arr[maxIdx])maxIdx = left;
    if(right <len && arr[right]>arr[maxIdx])maxIdx = right;
    if(maxIdx != index){
        swap(arr[index],arr[maxIdx]);
        adjust(arr,len,maxIdx);
    }
}
void heapSort(vector<int>&arr,int size){
    for(int i = size/2-1;i>=0;i--){
        adjust(arr,size,i);
    }
    for(int i = size-1;i>=1;i--){
        swap(arr[0],arr[i]);
        adjust(arr,i,0);
    }
}
int main(){
    vector<int> arr = {8, 1, 14, 3, 21, 5, 7, 10};
    heapSort(arr, arr.size());
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<< endl;
    system("pause");
    return 0;
}