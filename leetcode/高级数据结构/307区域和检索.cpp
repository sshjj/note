给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

update(i, val) 函数可以通过将下标为 i 的数值更新为 val，从而对数列进行修改。

示例:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8

class NumArray {
public:
    vector<int>tree;
    int n;
    NumArray(vector<int>& nums) {
        if(nums.size()>0){
            n = nums.size();
            tree = vector<int>(n*2);
            builTree(nums);
        }
    }
    void builTree(vector<int>&nums){
        for(int i =n,j = 0;i<2*n;++i,++j){
            tree[i] = nums[j];
        }
        for(int i =n-1;i>0;--i){
            tree[i] = tree[i*2]+tree[i*2+1];
        }
    }
    
    void update(int i, int val) {
        i+=n;
        tree[i] = val;
        while(i>0){
            int l =i;
            int r = i;
            if(i%2 ==0){
                r = i+1;
            }else{
                l = i-1;
            }
            tree[i/2] = tree[l] + tree[r];
            i/=2;
        }
    }
    
    int sumRange(int i, int j) {
        i+=n;
        j +=n;
        int sum = 0;
        while(i<=j){
            if(i%2 ==1){
                sum+=tree[i];
                i++;
            }
            if(j%2 ==0){
                sum+=tree[j];
                j--;
            }
            i/=2;
            j/=2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */