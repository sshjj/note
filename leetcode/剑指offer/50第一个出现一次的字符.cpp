在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

示例:

s = "abaccdeff"
返回 "b"

s = "" 
返回 " "

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> hash;
        for(auto x:s)hash[x]++;
        char res  = ' ';
        for(auto x:s)
        {
            if(hash[x] == 1){
                res = x;
                break;
            }
        }
        return res;
    }
};