#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int low,int mid,int high){
    int i = low,j = mid+1,k = 0;
    int *temp = new int[high-low+1];
    while(i<=mid && j<=high ){
        if(arr[i]<=arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i<=mid)
        temp[k++] = arr[i++];
    while(j<=high)
        temp[k++] = arr[j++];
    for(i = low,k = 0;i<high;i++,k++)
        arr[i] = temp[k];
    delete []temp;
}
void mergeSort(int arr[],int low,int high){
    if(low>=high){return ;}
    int mid = low + (high-low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main()
{
	int array[]={34,65,12,43,67,5,78,10,3,70},k;
	int len=sizeof(array)/sizeof(int);
	cout<<"The orginal arrayare:"<<endl;
	for(k=0;k<len;k++)
		cout<<array[k]<<",";
	cout<<endl;
	mergeSort(array,0,len-1);
	cout<<"The sorted arrayare:"<<endl;
	for(k=0;k<len;k++)
		cout<<array[k]<<",";
	cout<<endl;
	system("pause");
	return 0;
}