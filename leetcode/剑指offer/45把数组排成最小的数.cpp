输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。


示例 1:

输入: [10,2]
输出: "102"
示例 2:

输入: [3,30,34,5,9]
输出: "3033459"


class Solution {
public:
    static bool cmp(int a,int b){
        auto as = to_string(a),bs = to_string(b);
        return as+bs<bs+as;
    }
    string minNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string res;
        for(auto x:nums)res+=to_string(x);
        return res;
    }
};