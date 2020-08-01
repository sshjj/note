给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

注意:

num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。
示例 1 :

输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。

//笨方法
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k>=n)return "0";
        while(k){
            int i = 0;
            while(num[i]<=num[i+1])i++;        
            num.erase(i,1);
            k--;
            if(num.size()>1 && num[0] == '0')
                num.erase(0,1);

        }
        return num;
    }
};

// 单调栈
