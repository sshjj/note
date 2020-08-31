给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。

下图是字符串 s1 = "great" 的一种可能的表示形式。

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。

例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat" 。

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
我们将 "rgeat” 称作 "great" 的一个扰乱字符串。

同样地，如果我们继续交换节点 "eat" 和 "at" 的子节点，将会产生另一个新的扰乱字符串 "rgtae" 。

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
我们将 "rgtae” 称作 "great" 的一个扰乱字符串。

给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。

示例 1:

输入: s1 = "great", s2 = "rgeat"
输出: true

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1==s2)return true;
        int n=s1.size();
        int memo[26];
        memset(memo,0,sizeof(memo));
        for(int i=0;i<n;++i){
            memo[s1[i]-'a']++;
            memo[s2[i]-'a']--;
        }
        for(int i=0;i<26;++i){
            if(memo[i]!=0)return false;
        }
        for(int i=1;i<n;++i){
            //s1的前部分->s2的前部分，s1的后部分->s2的后部分
            if(isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i),s2.substr(i))){
                return true;
            }
            //s1的前部分->s2的后部分，s1的后部分->s2的前部分
            if(isScramble(s1.substr(0,i), s2.substr(n-i))&&isScramble(s1.substr(i), s2.substr(0, n-i))){
                return true;
            }
        }
        return false;
    }
};