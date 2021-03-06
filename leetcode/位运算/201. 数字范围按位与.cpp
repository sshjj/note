给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。

示例 1: 

输入: [5,7]
输出: 4
示例 2:

输入: [0,1]
输出: 0

class Solution {
public:
    //思路：此题其实就是寻找[m,n]范围内二进制数高位（左边）没有变化的数，后面补上0即为所求的结果。
    //分析1：判断m、n是否相等，如果不相等，m+1会使m的二进制数末位进位，有进位说明m的末位肯定有0的情况，0与任何数相与皆得0，所以结果的末位肯定是0。同理，不断右移1位进行比较，直到最终m=n时，说明找到了[m,n]这个范围内高位没有变化的数，左移相同位数得到的结果就是所求的值。
    //分析2：若n的位数大于m的位数，则最后结果为0，因为左边没有变化都为0；若n的位数等于m的位数，则最后结果为n的最高位1后面全部补0，因为左边没有变化的为n的最高位1了，后面全部补0
    int rangeBitwiseAnd(int m, int n) {
        int i=0;
        while(m!=n)
        {
            m>>=1;
            n>>=1;
            i++;
        }
        return n<<i;
    }
};