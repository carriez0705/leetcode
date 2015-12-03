class Solution {
    void printpath(string &cur, string &beginWord, unordered_map<string, vector<string> > &parent, vector<string> &vec, vector<vector<string> > &ans){
        if(cur==beginWord){
            vec.push_back(cur);
            ans.push_back(vec);
            vec.pop_back();
            return;
        }
        vec.push_back(cur);
        for(int i = 0; i<parent[cur].size(); i++){
            printpath(parent[cur][i], beginWord, parent, vec, ans);
        }
        vec.pop_back();
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string> > ans;
        if(endWord==beginWord){
            vector<string> vec(1,beginWord);
            ans.push_back(vec);
            return ans;
        }
        wordList.insert(endWord);
        wordList.erase(beginWord);
        queue<string> que;
        unordered_map<string, vector<string> > parent;
        que.push(beginWord);
        bool find = false;
        while(!que.empty() && !find){
            int quesize = que.size();
            vector<string> nextlevel;
            for(int k = 0; k<quesize; k++){
                string s = que.front();
                que.pop();
                string original = s;
                for(int i = 0; i<s.size(); i++){
                    char c = s[i];
                    for(char r = 'a'; r<='z'; r++){
                        if(r==c)
                            continue;
                        s[i] = r;
                        if(wordList.find(s)!=wordList.end()){
                            if(s==endWord){
                                find = true;
                            }
                            if(parent.find(s)==parent.end()){
                                vector<string> p(1,original);
                                parent[s] = p;
                                que.push(s);
                                nextlevel.push_back(s);
                            }
                            else{
                                parent[s].push_back(original);
                            }
                        }
                        s[i] = c;
                    }
                }
            }
            for(int i = 0; i<nextlevel.size(); i++)
                wordList.erase(nextlevel[i]);
        }
        vector<string> vec;
        printpath(endWord, beginWord, parent, vec, ans);
        for(int i = 0; i<ans.size(); i++){
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
