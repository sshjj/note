给你一个字符串 S、一个字符串 T 。请你设计一种算法，可以在 O(n) 的时间复杂度内，从字符串 S 里面找出：包含 T 所有字符的最小子串。

示例：

输入：S = "ADOBECODEBANC", T = "ABC"
输出："BANC"

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>hash;
        for(auto x:t)hash[x]++;
        int cnt = hash.size();
        string res;
        for(int i = 0,j = 0,c = 0;i<s.size();i++){
            if(hash[s[i]] ==1)c++;
            hash[s[i]]--;
            while(hash[s[j]]<0)hash[s[j++]]++;
            if(c == cnt){
                if(res.empty() || res.size()>i-j+1)res = s.substr(j,i-j+1);
            }
        }
        return res;
    }
};