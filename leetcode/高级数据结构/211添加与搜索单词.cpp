设计一个支持以下两种操作的数据结构：

void addWord(word)
bool search(word)
search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。

示例:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

class WordDictionary {
public:
    struct Trie{
        bool isend;
        Trie* next[26];
        Trie(){
            isend = false;
            for(int i = 0;i<26;i++){
                next[i] = NULL;
            }
        }
    };
    Trie* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int n = word.size();
        Trie* node = root;
        for(int i =0;i<n;i++){
            int idx = word[i] - 'a';
            if(node->next[idx]== NULL)node->next[idx] = new Trie();
            node = node->next[idx];
        }
        node->isend = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return subseach(root ,word);
    }
    bool subseach(Trie* p,string word){
        if(p == NULL)return false;
        int n = word.size();
        for(int i =0;i<n;i++){
            if(word[i] == '.'){
                for(int j = 0;j<26;j++){
                    if(subseach(p->next[j],word.substr(i+1)))return true;
                }
                return false;
            }
            int idx = word[i] - 'a';
            if(p->next[idx] == NULL)return false;
            p = p->next[idx];
        }
        return p->isend;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */