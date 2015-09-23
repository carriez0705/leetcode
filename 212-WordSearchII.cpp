int xstep[] = {0,1,0,-1};
int ystep[] = {1,0,-1,0};
class TrieNode{
    
public:
    char c;
    bool isWord;
    unordered_map<char, TrieNode*> adj;
    bool isComplete;
    TrieNode(char ch,bool word):c(ch),isWord(word), isComplete(false){
        adj.clear();
    }
    ~TrieNode(){
        adj.clear();
    }
    void setWord(){
        isWord = true;
    }
};
class Trie{
    TrieNode *root;
    void addHelper(TrieNode *node, string &s, int p){
        bool word = (p==s.size()-1)?true:false;
        if(node->adj.find(s[p])==node->adj.end()){
            node->adj[s[p]] = new TrieNode(s[p],false);
        }
        if(word){
            node->adj[s[p]]->setWord();
        }
        else{
            addHelper(node->adj[s[p]],s,p+1);
        }
    }
    void deleteHelper(TrieNode *node){
        for(auto iter = node->adj.begin(); iter!=node->adj.end(); iter++){
            deleteHelper(iter->second);
        }
        delete node;
    }
public:
    Trie(){
        root = new TrieNode(-1,false);
    }
    ~Trie(){
        deleteHelper(root);
    }
    void add(string &s){
        addHelper(root,s,0);
    }
    TrieNode* getRoot(){
        return root;
    }
};
class Solution {
//	vector<string> result;
	bool dfs(int x, int y, vector<vector<char> > &board, vector<vector<bool> > &marked, TrieNode* &node, string &s, set<string> &result){
		marked[x][y] = true;
		s.push_back(node->c);
		if(node->isWord && !node->isComplete){
			result.insert(s);
			node->isComplete = true;
			if(node->adj.empty()){
				s.pop_back();
				marked[x][y] = false;
				return true;
			}
		}

		vector<char> candidate(4,-1);
		for(int i = 0; i<4; i++){
			int newx = x+xstep[i];
			int newy = y+ystep[i];
			if(newx<board.size()&&newx>=0&&newy<board[0].size()&&newy>=0&& !marked[newx][newy])
				candidate[i] = board[newx][newy];
		}
		int match = 0;
		for(auto iter = node->adj.begin(); iter!=node->adj.end(); iter++){
			if(iter->second->isComplete){
				match += 1;
				continue;
			}
			bool complete = false;
			for(int i = 0; i<4 && !complete; i++){
				if(iter->first==candidate[i]){
					int newx = x+xstep[i];
					int newy = y+ystep[i];
					complete = dfs(newx, newy, board, marked, iter->second,s,result);
				}
			}

			if(complete) match += 1;
		}
		node->isComplete= match==node->adj.size();
		s.pop_back();
		marked[x][y] = false;
		return node->isComplete;
	}
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		set<string> result;
		vector<string> rett;
		Trie tr;
		for(int i = 0; i<words.size(); i++){
			tr.add(words[i]);
		}
		int n = board.size();
		int m = n?board[0].size():0;
		if(!n||!m||!words.size()) return rett;
		vector<vector<bool> > marked(n, vector<bool>(m, false));
		TrieNode *root = tr.getRoot();
		for(int i = 0; i<n; i++)
			for(int j = 0; j<m; j++){
				for(auto iter = root->adj.begin(); iter!=root->adj.end(); iter++){
					if(board[i][j]==iter->first && !iter->second->isComplete){
						string s = "";
						dfs(i,j,board,marked,iter->second,s, result);
					}
				}
			}
			for(auto iter = result.begin();iter!=result.end(); iter++)
				rett.push_back(*iter);
			return rett;
	}
};
