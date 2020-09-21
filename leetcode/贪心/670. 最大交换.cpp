给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。

示例 1 :

输入: 2736
输出: 7236
解释: 交换数字2和数字7。

class Solution {
public:
    int maximumSwap(int num) {
        if(num<10)return num;
        string s = to_string(num);
        for(int i =0;i<s.size();i++){
            int index = i;
            for(int j = i+1;j<s.size();++j){
                if(s[j]>=s[index])index = j;
            }
            if(index!=i&&s[index]!=s[i]){
                swap(s[i],s[index]);
                break;
            }
        }
        return stoi(s);
    }
};