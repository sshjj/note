给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>hash;
        int j = 0,res = 0;
        for(int i = 0;i<s.size();i++){
            hash[s[i]]++;
            while(hash[s[i]]>1)hash[s[j++]]--;
            res = max(res,i-j+1);
        }
        return res;
    }
};