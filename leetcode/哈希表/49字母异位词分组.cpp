给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>hash;
        vector<vector<string>>res;
        for(int i = 0;i<strs.size();i++){
            string str = strs[i];
            sort(str.begin(),str.end());
            if(hash.find(str) == hash.end()){
                vector<string>tmp;
                hash[str] = tmp;
            }
            hash[str].push_back(strs[i]);
        }
        for(auto it:hash){
            res.push_back(it.second);
        }
        return res;
    }
};


class Solution {
public:
    void change_to_vector(string& s,vector<int>&vec){
        for(int i = 0;i<26;i++){
            vec.push_back(0);
        }
        for(int i = 0;i<s.length();i++){
            vec[s[i] -'a']++;
        }
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string> >hash;
        vector<vector<string>>res;
        for(int i = 0;i<strs.size();i++){
            vector<int>vec;
            change_to_vector(strs[i],vec);
            if(hash.find(vec) == hash.end()){
                vector<string>tmp;
                hash[vec] = tmp;
            }
            hash[vec].push_back(strs[i]);
        }
        for(auto x:hash){
            res.push_back(x.second);
        }
        return res;
    }
};