实现一个基本的计算器来计算一个简单的字符串表达式的值。

字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。

示例 1:

输入: "1 + 1"
输出: 2


class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int res = 0,n = s.size(),sign = 1;
        for(int i = 0;i<n;i++){
            int num = 0;
            if(s[i]>='0'){
                while(i<n && s[i]>='0'){
                    num = num*10+(s[i]-'0');
                    i++;
                }
                i--;
                res += sign*num;
            }
            else if(s[i] == '+')sign = 1;
            else if(s[i] == '-')sign = -1;
            else if(s[i] == '('){
                st.push(res);
                st.push(sign);
                res  = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                res *= st.top();st.pop();
                res += st.top();st.pop();
            }
        }
        return res;
    }
};