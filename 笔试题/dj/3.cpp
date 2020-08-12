有一个二维字母表，给定一个单词列表，找出所有能用这个字母表构造出来的单词，并按首字母升序输出（测试数据单词中首字母都不相同）：

案例一

 

// 字母表

alphabet = [

['a', 't', 'm', 'b'],

['f', 'u', 'e', 'g'],

['l', 'y', 'i', 'n'],

['p', 'k', 'j', 'd']

]

 

// 被检查的单词列表

words = ["dji", "year", "flying", "ideas"]

 

// 符合要求的单词

["dji", "flying"]

 

案例二

 

// 字母表

alphabet = [

['u', 'v', 'w', 'x', 'y'],

['g'],

['g', 'o', 'b', 'i'],

['a', 'o', 's'],

['t', 'd', 's']

]

 

// 被检查的单词列表

words = ["good", "dos"]

 

// 符合要求的单词

["dos, "goods"]

要求，每个单词的所有字符都必须在字母表中，字符的选择路径必须是二维字母表的水平或者垂直相邻元素，另外，同一个单词中，相同位置字母表元素至多使用一次。


#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    map<char, TrieNode*> child;
    string word;
    TrieNode() {}
};

int m,n;int dx[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
void dfs(vector<string>& board, int i, int j, TrieNode* root, vector<string>& res) {
     if(i < 0 || i >= m || j < 0 || j >= n || root->child.count(board[i][j]) == 0 || board[i][j]=='0')
            return;
        char visited = board[i][j];
        root = root->child[visited];
        if(root->word != "") {
            res.push_back(root->word);
            root->word = "";
        }
        board[i][j] = '*';
        for(int t=0;t<4;t++){
            int tx=i+dx[t][0],ty=j+dx[t][1];
            dfs(board,tx,ty,root,res);
        }
        board[i][j] = visited;
}
//建立字典树
TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(auto& word : words) {
            TrieNode* p = root;
            for(auto& c : word) {
                if(p->child.count(c) == 0)
                    p->child[c] = new TrieNode();
                p = p->child[c];
            }
            p->word = word;
        }
        return root;
}
int main()
{
    int N,M;cin>>N;
    vector<string> board(N,"");
    for(int i=0;i<N;i++) cin>>board[i];
    cin>>M;vector<string> words(N,""),res;
    for(int i=0;i<M;i++) cin>>words[i];
    TrieNode* root = buildTrie(words);
    m = board.size();
    int len=0;
    for(int i=0;i<m;i++) len=max(len,(int)board[i].size());
    for(int i=0;i<m;i++){
        for(int j=board[i].size();j<len;j++) board[i]+='0';
        //cout<<board[i]<<endl;
    }
    n=len;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j){ 
              dfs(board, i, j, root, res);
        }
    sort(begin(res),end(res));
    for(auto s:res) cout<<s<<endl;
    return 0;
    
}



struct TrieNode {
    map<char, TrieNode*> child;
    string word;
    TrieNode() {}
};

class Solution {
public:
    int m, n;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        TrieNode* root = buildTrie(words);
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                dfs(board, i, j, root, res);
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root, vector<string>& res) {
        if(i < 0 || i >= m || j < 0 || j >= n || root->child.count(board[i][j]) == 0)
            return;
        char visited = board[i][j];
        root = root->child[visited];
        if(root->word != "") {
            res.push_back(root->word);
            root->word = "";
        }
        board[i][j] = '*';
        dfs(board, i+1, j, root, res);
        dfs(board, i-1, j, root, res);
        dfs(board, i, j+1, root, res);
        dfs(board, i, j-1, root, res);
        board[i][j] = visited;
    }
    
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(auto& word : words) {
            TrieNode* p = root;
            for(auto& c : word) {
                if(p->child.count(c) == 0)
                    p->child[c] = new TrieNode();
                p = p->child[c];
            }
            p->word = word;
        }
        return root;
    }
};