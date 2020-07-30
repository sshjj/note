输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

示例 1：

输入：n = 12
输出：5
示例 2：

输入：n = 13
输出：6

class Solution {
public:
    int countDigitOne(int n) {
        if(!n)return 0;
        vector<int>nums;
        while(n)nums.push_back(n%10),n /=10;
        int res = 0;
        for(int i = 0;i<nums.size();i++){
            auto left = 0,right = 0,t =1;
            for(int j = nums.size()-1;j>i;j--)left = left*10 +nums[j];
            for(int j = i-1;j>=0;j--)right = right*10 +nums[j],t *= 10;
            res+=left*t;
            if(nums[i] == 1)res+=right+1;
            else if(nums[i]>1)res+=t;
       }
       return res;
    }
};