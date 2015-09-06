class TrieNode{
public:
    char c;
    unordered_map<char, TrieNode*> dict;
    bool isWord;
    TrieNode(char ch):c(ch),isWord(false){dict.clear();}
    ~TrieNode(){dict.clear();}
};
class WordDictionary {
    TrieNode *root;
    bool helper(string &word, TrieNode *node, int i){
        if(i==word.size()) return node->isWord;
        if(word[i]=='.'){
            for(auto j = node->dict.begin(); j!=node->dict.end(); j++){
                if(helper(word, j->second, i+1)) return true;
            }
            return false;
        }
        if(node->dict.find(word[i])!=node->dict.end()){
            return helper(word, node->dict[word[i]], i+1);
        }
        return false;
    }
    void deleteHelper(TrieNode *node){
        if(!node) return ;
        for(auto j = node->dict.begin(); j!=node->dict.end(); j++){
            deleteHelper(j->second);
        }
        node->dict.clear();
        delete node;
    }
public:
    WordDictionary(){
        root = new TrieNode(-1);
    };
    ~WordDictionary(){
        deleteHelper(root);
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *node = root;
        for(int i = 0; i<word.size(); i++){
            if(node->dict.find(word[i])==node->dict.end()){
                TrieNode *child = new TrieNode(word[i]);
                node->dict[word[i]]=child;
            }
            node = node->dict[word[i]];
            if(i==word.size()-1)
                node->isWord = true;
        }
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return helper(word, root, 0);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
