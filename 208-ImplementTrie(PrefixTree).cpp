class TrieNode {
public:
    bool tail;
    vector<TrieNode*> adj;
    // Initialize your data structure here.
    TrieNode() {
        tail = false;
        adj.clear();
        adj.resize(26);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *node = root;
        for(int i = 0; i<word.size(); i++){
            int key = word[i]-'a';
            //node->tail = false;
            if(!node->adj[key]){
                TrieNode *next = new TrieNode();
                node->adj[key] = next;
            }
            node = node->adj[key];
        }
        node->tail = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *node = root;
        int i = 0;
        while(i<word.size()){
            if(!node->adj[word[i]-'a']) return false;
            node = node->adj[word[i]-'a'];
            i++;
        }
        return node->tail;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *node = root;
        int i = 0;
        while(i<prefix.size()){
            if(!node->adj[prefix[i]-'a']) return false;
            node = node->adj[prefix[i]-'a'];
            i++;
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
