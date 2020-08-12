//用于统计，排序，存储字符串的数据结构,关键字不保存在节点中，而是由节点在树中的位置决定，
//trie树节点的表示
struct TrieNode{
    TrieNode *child[TRIE_MAX_CHAR_NUM];
    bool is_end;
    TrieNode():is_end(false){
        for(int i = 0;i<TRIE_MAX_CHAR_NUM;i++){
            child[i] = 0;
        }
    }
};
class TrieTree{
public:
    TrieTree(){}
    ~TrieTree(){
        for(int i=0;i<_node_vec.size();i++){
            delete _node_vec[i];
        }
    }
    void insert(const char *word){
        TrieNode *ptr = &_root;
        while(*word){
            int pos = *word-'a';
            if(!ptr->child[pos]){
                ptr->child[pos] = new node();
            }
            ptr = ptr->child[pos];
            word++;
        }
        ptr->is_end = true;
    }
    void search(const char *word){

    }
    bool startsWith(const char *prefix){

    }
    TrieNode *root(){
        return &_root;
    }
private:
    TrieNode *new_node(){
        TrieNode *node = new TrieNode();
        _node_vec.push_back(node);
        return node;
    }
    std::vector<TrieNode*>_node_vec;
    TrieNode _root;
}