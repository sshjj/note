4. 寻找两个正序数组的中位数
给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。

请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

 

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size()+nums2.size();
        if(total%2 == 0){
            int left = findKthNumber(nums1,0,nums2,0,total/2);
            int right = findKthNumber(nums1,0,nums2,0,total/2+1);
            return (left+right)/2.0;
        }
        else{
            return findKthNumber(nums1,0,nums2,0,total/2+1);
        }
    }
    int findKthNumber(vector<int>&nums1,int i,vector<int>&nums2,int j,int k){
        if(nums1.size()-i>nums2.size()-j)return findKthNumber(nums2,j,nums1,i,k);
        if(nums1.size() == i)return nums2[j+k-1];
        if(k == 1)return min(nums1[i],nums2[j]);
        int si = min(i+k/2,int(nums1.size())),sj =j+k/2;
        if(nums1[si-1]>nums2[sj-1]){
            return findKthNumber(nums1,i,nums2,j+k/2,k-k/2);
        }
        else {
            return findKthNumber(nums1,si,nums2,j,k-(si-i));
        }
    }
};


class Solution {
public:
    int getKth(const vector<int>&nums1,const vector<int>&nums2,int k){
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0,index2 = 0;
        while(true){
            if(index1 == m){
                return nums2[index2+k-1];
            }
            if(index2 == n){
                return nums1[index1+k-1];
            }
            if(k == 1){
                return min(nums1[index1],nums2[index2]);
            }
            int newIdx1 = min(index1+k/2 -1,m-1);
            int newIdx2 = min(index2+k/2-1,n-1);
            int pivot1 = nums1[newIdx1];
            int pivot2 = nums2[newIdx2];
            if(pivot1<=pivot2){
                k-=newIdx1 -index1+1;
                index1 = newIdx1+1;
            }
            else{
                k -=newIdx2-index2+1;
                index2 = newIdx2+1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tl = nums1.size()+nums2.size();
        if(tl%2 == 1){
            return getKth(nums1,nums2,(tl+1)/2);
        }
        else{
            return (getKth(nums1,nums2,tl/2)+getKth(nums1,nums2,tl/2+1))/2.0;
        }
    }
};