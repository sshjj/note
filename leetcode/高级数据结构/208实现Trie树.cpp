实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");   
trie.search("app");     // 返回 true

class Trie {
public:
    bool isend;
    Trie* next[26];
    /** Initialize your data structure here. */
    Trie() {
        isend = false;
        memset(next,0,sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for(char c:word){
            if(node->next[c-'a'] == NULL){
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->isend = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = this;
        for(char c:word){
            node = node->next[c-'a'];
            if(node == NULL){
                return false;
            }
        }
        return node->isend;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for(auto c:prefix){
            node = node->next[c-'a'];
            if(node ==NULL){
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */