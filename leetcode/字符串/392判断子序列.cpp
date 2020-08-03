给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

示例 1:
s = "abc", t = "ahbgdc"
返回true

双指针法
```
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(),m = t.size();
        int i = 0,j = 0;
        while(i<n && j<m){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return i == n;
    }
};
```
