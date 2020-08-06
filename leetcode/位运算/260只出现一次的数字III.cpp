给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

示例 :

输入: [1,2,1,3,2,5]
输出: [3,5]

//位运算
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int s = 0;
        for(int num:nums){
            s^=num;
        }
        int k = s&(-s);
        vector<int>rs(2,0);
        for(int num:nums){
            if(num&k){
                rs[0]^=num;
            }else{
                rs[1]^=num;
            }
        }
        return rs;
    }
};


//hash
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>hash;
        vector<int>res;
        for(auto x:nums){
            hash[x]++;
        }
        for(auto x:hash){
            if(x.second == 1){
                res.push_back(x.first);
            }
        }
        return res;
    }
};