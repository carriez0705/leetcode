class Solution {
    
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if(endWord==beginWord) return 1;
        queue<string> que;
        wordList.insert(endWord);
        wordList.erase(beginWord);
        que.push(beginWord);
        int len = 1;
        while(!que.empty()){
            len++;
            int quesize = que.size();
            for(int k = 0; k<quesize; k++){
                string s = que.front();
                que.pop();
            for(int i = 0; i<s.size(); i++){
                char c = s[i];
                for(char r = 'a'; r<='z'; r++){
                    if(r==c)
                        continue;
                    s[i] = r;
                    if(wordList.find(s)!=wordList.end()){
                        que.push(s);
                        wordList.erase(s);
                        if(s==endWord)
                            return len;
                    }
                }
                s[i] = c;
            }
            }
        }
        return 0;
    }
};
