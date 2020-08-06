给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意:
假设字符串的长度不会超过 1010。

示例 1:

输入:
"abccccdd"

输出:
7

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>hash;
        int res = 0;
        int flag = 0;
        for(int i = 0;i<s.size();i++){
            hash[s[i]]++;
        }
        for(auto x:hash){
            if(x.second%2 == 0)
                res+=x.second;
            else{
                res+=x.second-1;
                flag = 1;
            }
        }
        return res+flag;
    }
};