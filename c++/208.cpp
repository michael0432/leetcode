class TrieNode{
public:
    TrieNode* childs[26];
    bool isWord;
    TrieNode(){
        isWord = false;
        for (auto &a : childs) a = nullptr;
    }
};


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.size();i++){
            int x = word[i] - 'a';
            if(!p->childs[x]){
                p->childs[x] = new TrieNode();
            }
            p = p->childs[x];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.size();i++){
            int x = word[i] - 'a';
            if(!p->childs[x])
                return false;
            p = p->childs[x];
        }
        return p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (int i = 0; i < prefix.size(); i++){
            int x = prefix[i] - 'a';
            
            if (!p->childs[x])
                return false;
            p = p->childs[x];
        }
        return true;
    }
private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */