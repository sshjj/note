请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。


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
        int res = 0;
        for(int i =0 ,j =0;j<s.size();j++){
            hash[s[j]]++;
            while(hash[s[j]]>1){
                hash[s[i++]]--;
            }
            res = max(res,j-i+1);
        }
        return res;

    }
};