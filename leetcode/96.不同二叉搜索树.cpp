/* dp 问题
G(n): 长度为 n 的序列能构成的不同二叉搜索树的个数。
F(i, n): 以 i 为根、序列长度为 n 的不同二叉搜索树个数 (1≤i≤n)。
可见，G(n)G(n) 是我们求解需要的函数。
G(n)= i=1∑nF(i,n)

F(i,n) = G(i-1)*G(n-i)

G(n) =sum(G(i-1)*G(n-i)); 


*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n+1,0);
        G[0] = 1;
        G[1] = 1;
        for(int i = 2;i<=n;i++){
            for(int j = 1;j<=i;j++){
                G[i] += G[j-1]*G[i-j];
            }
        }
        return G[n];
    }
};