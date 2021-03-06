所有 DNA 都由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。

编写一个函数来查找目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。

示例：

输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出：["AAAAACCCCC", "CCCCCAAAAA"]

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>hash;
        vector<string>res;
        for(int i=0 ;i<s.size();i++){
            string path = s.substr(i,10);
            hash[path]++;
        }
        for(auto x:hash){
            if(x.second>1){
                res.push_back(x.first);
            }
        }
        return res;
    }
};