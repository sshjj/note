给你一个 山脉数组 mountainArr，请你返回能够使得 mountainArr.get(index) 等于 target 最小 的下标 index 值。

如果不存在这样的下标 index，就请返回 -1。

 

何为山脉数组？如果数组 A 是一个山脉数组的话，那它满足如下条件：

首先，A.length >= 3

其次，在 0 < i < A.length - 1 条件下，存在 i 使得：

A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
 

你将 不能直接访问该山脉数组，必须通过 MountainArray 接口来获取数据：

MountainArray.get(k) - 会返回数组中索引为k 的元素（下标从 0 开始）
MountainArray.length() - 会返回该数组的长度

示例 1：

输入：array = [1,2,3,4,5,3,1], target = 3
输出：2
解释：3 在数组中出现了两次，下标分别为 2 和 5，我们返回最小的下标 2。
示例 2：

输入：array = [0,1,2,4,2,1], target = 3
输出：-1
解释：3 在数组中没有出现，返回 -1。

题解：

三次二分法寻找山脉数组中的目标值，
第一次二分：使用二分法的模板Ⅱ，寻找数组的山峰，将数组分为前半部分升序的数组和后半部分降序的数组
第二次二分：在前半部分升序数组中继续使用二分法的模板Ⅱ，寻找大于等于x的最小值
第三次二分：若在前半部分没有找到x，那么我们需要使用二分法的模板Ⅱ对后半部分降序数组中寻找x
代码如下：

class Solution {
public:
    //思路：三次二分查找寻找目标值的最小下标
    int findInMountainArray(int target, MountainArray &mountainArr) {
        //注意使用闭区间，如果使用开区间，在[size-1,size)时mid取左中位数，mid+1会溢出，所以我们使用闭区间
        int left=0,right=mountainArr.length()-1;

        //第一次二分，寻找山脉的山峰
        while(left<right){
            //取左中位数，因为进入循环，数组一定至少有 2 个元素
            //因此，左中位数一定有右边元素，数组下标不会发生越界
            int mid=left+((right-left)>>1);
            //mid所指的值大于等于mid+1，那么山峰在数组的左边，我们应该向左边逼近
            if(mountainArr.get(mid)>=mountainArr.get(mid+1))right=mid;
            //mid所指的值小于mid+1，那么山峰在数组的右边，我们应该向右边逼近
            else left=mid+1;
        }
        //根据题意山峰一定存在，所以我们不用特判了
        int peak=left;

        //第二次二分，在前半部分升序数组中寻找target
        left=0,right=peak;
        while(left<right){
            int mid=left+((right-left)>>1);
            if(mountainArr.get(mid)>=target)right=mid;
            else left=mid+1;
        }
        //在左边找到target，直接返回下标，否则在右半部分寻找
        if(mountainArr.get(left)==target)return left;

        //第三次二分，在后半部分降序数组中寻找target
        left=peak+1,right=mountainArr.length()-1;
        while(left<right){
            int mid=left+((right-left)>>1);
            //注意这里为<=，因为mid比x小，mid右边的元素肯定比x大，那么我们应该向左逼近
            if(mountainArr.get(mid)<=target)right=mid;
            else left=mid+1;
        }
        //在右边找到target后，直接返回下标，否则返回-1
        if(mountainArr.get(left)==target)return left;
        return -1;
    }
};