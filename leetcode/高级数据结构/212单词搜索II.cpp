给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

示例:

输入: 
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

输出: ["eat","oath"]


class TrieNode{
public:
    bool is_word;
    string str;
    vector<TrieNode*>next;
    TrieNode(){
        is_word = false;
        next = vector<TrieNode*>(26,nullptr);
    }
};
class Solution {
public:
    TrieNode* root;
    int n,m;
    vector<string>res;
    vector<vector<char>>data;
    unordered_set<string>tmp;
    vector<vector<bool>>v;
    int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
    void add(string &word){
        TrieNode* cur = root;
        for(auto c:word){
            if(cur->next[c-'a'] == nullptr)cur->next[c-'a'] = new TrieNode();
            cur = cur->next[c-'a'];
        }
        cur->is_word = true;
        cur->str = word;
    }
    void dfs(int x,int y,TrieNode* cur){
        if(cur->is_word){
            if(!tmp.count(cur->str)){
                res.push_back(cur->str);
                tmp.insert(cur->str);
            }
        }
        for(int i =0;i<4;i++){
            int xx =x+dx[i],yy = y+dy[i];
            if(xx<0 || xx>=n ||yy<0||yy>=m||v[xx][yy])continue;
            if(cur->next[data[xx][yy]-'a']){
                v[xx][yy] = true;
                dfs(xx,yy,cur->next[data[xx][yy]-'a']);
                v[xx][yy] = false;
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        data = board;
        res = vector<string>();
        for(auto x:words)add(x);
        n = board.size();
        if(n == 0)return {};
        m = board[0].size();
        v = vector<vector<bool>>(n,vector<bool>(m,false));
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(root->next[board[i][j]-'a']){
                    v[i][j] = true;
                    dfs(i,j,root->next[board[i][j]-'a']);
                    v[i][j] = false;
                }
            }
        }
        sort(res.begin(),res.end());
        return res;

    }
};