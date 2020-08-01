在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i = 0;i<nums.size();i++){
            q.push(nums[i]);
            while(q.size()>k)q.pop();
        }
        return q.top();
    }
};



class Solution {
public:
    void maxHeapify(vector<int>&a,int i,int heapSize){
        int l = i*2+1,r = i*2+2,largest = i;
        if(l<heapSize && a[l]>a[largest]){
            largest = l;
        }
        if(r<heapSize && a[r]>a[largest]){
            largest = r;
        }
        if(largest != i){
            swap(a[i],a[largest]);
            maxHeapify(a,largest,heapSize);
        }
    }
    void buildMaxHeap(vector<int>&a,int heapSize){
        for(int i = heapSize/2;i>=0;i--){
            maxHeapify(a,i,heapSize);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums,heapSize);
        for(int i = nums.size()-1;i>=nums.size()-k+1;--i){
            swap(nums[0],nums[i]);
            --heapSize;
            maxHeapify(nums,0,heapSize);
        }
        return nums[0];
    }
};