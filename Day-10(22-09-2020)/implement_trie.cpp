class TrieNode{
public:
        TrieNode* next[26] = {};
        bool isword = false;
};

class Trie {
    TrieNode* root;
     void insert(TrieNode* root,string word) {
        TrieNode* node = root;
        for (char ch : word) {
            ch -= 'a';
            if (node->next[ch] == NULL) { node->next[ch] = new TrieNode(); }
            node = node->next[ch];
        }
        node->isword = true;
    }

    bool search(TrieNode* root,string word) {
        TrieNode* node = root;
        for (char ch : word) {
            ch -= 'a';
            if (node->next[ch] == NULL) { return false; }
            node = node->next[ch];
        }
        return node->isword;
    }

    bool startsWith(TrieNode* root,string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->next[ch] == NULL) { return false; }
            node = node->next[ch];
        }
        return true;
    }
    
public:
    Trie() {
        root = new TrieNode();
    }

  
    void insert(string word) {
        insert(root, word);
    }

    bool search(string word) {
        return search(root, word);
    }

    bool startsWith(string prefix) {
        return startsWith(root, prefix);
    }



};

