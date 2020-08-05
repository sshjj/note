给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

示例：

输入：[5,2,6,1]
输出：[2,1,1,0] 
解释：
5 的右侧有 2 个更小的元素 (2 和 1)
2 的右侧仅有 1 个更小的元素 (1)
6 的右侧有 1 个更小的元素 (1)
1 的右侧有 0 个更小的元素

class Solution {
public:
    vector<int>count;
    vector<int>tmp;
    vector<int>index;
    void merge(vector<int>&nums,int l,int r){
        if(l>=r)return;
        int mid = (l+r)/2;
        merge(nums,l,mid);
        merge(nums,mid+1,r);
        int i = l,j = mid+1;
        for(int k = l;k<=r;k++){
            if(i>mid || (j<=r && nums[index[i]]<=nums[index[j]]))tmp[k] = index[j++];
            else if(j>r || (i<=mid && nums[index[i]]>nums[index[j]])){
                count[index[i]] += r-j+1;
                tmp[k] = index[i++];
            }
        }
        for(int k = l;k<=r;k++){
            index[k] = tmp[k];
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n =nums.size();
        count = vector<int>(n,0);
        tmp = vector<int>(n,0);
        index = vector<int>(n,0);
        for(int i = 0;i<n;i++)index[i] = i;
        merge(nums,0,n-1);
        return count;
    }
};