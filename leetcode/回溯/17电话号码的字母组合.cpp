给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

class Solution {
public:
    vector<string>res;
    string path;
    map<int,string>M={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return res;
        }
        dfs(0,digits);
        return res;
    }
    void dfs(int index,string digits){
        if(index == digits.size()){
            res.push_back(path);
            return;
        }
        for(int i = 0;i<M[digits[index]].size();i++){
            path.push_back(M[digits[index]][i]);
            dfs(index+1,digits);
            path.pop_back();
        }
    }

};