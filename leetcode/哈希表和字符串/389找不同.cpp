给定两个字符串 s 和 t，它们只包含小写字母。

字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

请找出在 t 中被添加的字母。

示例:

输入：
s = "abcd"
t = "abcde"

输出：
e

解释：
'e' 是那个被添加的字母。

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>char_s(26,0);
        vector<int>char_t(26,0);
        for(auto x:s)char_s[x-'a']++;
        for(auto x:t)char_t[x-'a']++;
        for(int i =0;i<26;i++){
            if(char_t[i]>char_s[i])
                return 'a'+i;
        }
        return 'a';
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        int res=0;
        //由于t比s多一位，所以s用减，t用加
        for(char c:s)res-=c;
        for(char c:t)res+=c;
        //最后结果要转换为对应的assic码
        return char(res);
    }
};