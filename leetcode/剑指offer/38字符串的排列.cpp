输入一个字符串，打印出该字符串中字符的所有排列。

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
 
示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]

class Solution {
public:
    vector<string> res;
    vector<string> permutation(string s) {
        res.push_back(s);
        find(s,0);
        return res;
    }
    void find(string &s,int p ){
        if(p == s.size())return;
        set<char>hash;
        for(int i = p;i<s.size();i++){
            if(hash.count(s[i]))continue;
            hash.insert(s[i]);
            swap(s[p],s[i]);
            if(p!=i)res.push_back(s);
            find(s,p+1);
            swap(s[p],s[i]);
        }
    }
};