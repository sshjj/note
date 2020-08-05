给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]


class Solution {
public:
    vector<vector<string>>res;
    vector<vector<string>> partition(string s) {
        vector<string>path;
        dfs(s,path,0);
        return res;
    }
    void dfs(string &s,vector<string>&path,int pre ){
        if(pre == s.size()){
            res.push_back(path);
            return ;
        }
        string temp;
        for(int i =pre;i<s.size();i++){
            bool flag = true;
            temp = s.substr(pre,i-pre+1);
            int m = temp.size();
            for(int k = 0,j=m-1;k<m&&j>=0;k++,j--){
                if(temp[k] != temp[j]){
                    flag = false;
                    break;
                }
            }
            if(flag == false)continue;
            path.push_back(temp);
            dfs(s,path,i+1);
            path.pop_back();
        }
    }
};