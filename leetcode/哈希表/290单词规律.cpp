给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:

输入: pattern = "abba", str = "dog cat cat dog"
输出: true
//哈希表
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string,char>hash;
        char use[128] = {0};
        string word;
        int pos = 0;
        str.push_back(' ');
        for(int i = 0;i<str.size();i++){
            if(str[i] == ' '){
                if(pos == pattern.length()){
                    return false;
                }
                if(hash.find(word) == hash.end()){
                    if(use[pattern[pos]]){
                        return false;
                    }
                    hash[word] = pattern[pos];
                    use[pattern[pos]] = 1;
                }
                else{
                    if(hash[word]!=pattern[pos])
                        return false;
                }
                word = "";
                pos++;
            }else{
                word+=str[i];
            }
        }
        if(pos!=pattern.size()){
            return false;
        }
        return true;
    }
};

//直接分割
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string>words;
        string s;
        for(int i = 0;i<str.size();i++){
            if(str[i] == ' '){
                if(s.size())
                    words.push_back(s);
                s = "";
            }else{
                s+=str[i];
            }
        }
        if(s.size())
            words.push_back(s);
        if(words.size()!=pattern.size())
            return false;
        for(int i = 0;i<pattern.length();i++){
            for(int j = i+1;j<pattern.size();j++){
                if((pattern[i] == pattern[j])&&(words[i]!=words[j])||(pattern[i]!=pattern[j])&&(words[i] == words[j]))
                    return false;
            }
        }
        return true;
    }
};