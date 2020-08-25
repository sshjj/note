给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for(int i = 0;i<s.size();i++){
            for(int j = i, k =i;j>=0&&k<s.size()&&s[j] == s[k];j--,k++){
                if(res.size()<k-j+1)
                    res = s.substr(j,k-j+1);
            }
            for(int j = i,k=i+1;j>=0&&k<s.size()&&s[j] == s[k];j--,k++){
                if(res.size()<k-j+1)
                    res = s.substr(j,k-j+1);
            }
        }
        return res;
    }
};