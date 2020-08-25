#include <bits/stdc++.h>
using namespace std;
struct TrieNode
{
    bool isEndOfWord;
    map<char, TrieNode *> children;
    TrieNode() : isEndOfWord(false) {}
};
void addWord(string word, TrieNode *root)
{
    TrieNode *p = root;
    int i = 0;
    for (auto c : word)
    {
        if (p->children.count(c) == 0)
            p->children[c] = new TrieNode();
        p = p->children[c];
        if (++i > 6)
        {
            return;
        }
    }
    p->isEndOfWord = true;
}
void display(vector<string> &pq, TrieNode *root, string str, int &k)
{
    if (root->isEndOfWord)
    {
        pq.push_back(str);
    }
    for (auto child : root->children)
    {
        str += child.first;
        display(pq, child.second, str, k);
    }
}
int main()
{
    auto r = freopen("input.txt", "r", stdin);
    TrieNode *root = new TrieNode();
    string s;
    cin >> s;
    int k;
    cin >> k;
    int l = s.length();
    vector<string> pq;
    for (int i = 0; i < l; ++i)
    {
        for (int j = 1; j <= l - i; ++j)
        {
            addWord(s.substr(i, j), root);
        }
    }
    display(pq, root, "", k);
    cout << pq[k - 1] << endl;
    return 0;
}