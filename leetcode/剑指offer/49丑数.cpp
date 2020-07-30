我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。


示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> q(1,1);
        int i =0,j =0,k  =0;
        while(--n){
            int t = min(q[i]*2,min(q[j]*3,q[k]*5));
            q.push_back(t);
            if(q[i]*2 == t)i++;
            if(q[j]*3 == t)j++;
            if(q[k]*5 == t)k++;
        }

        return q.back();
    }
};