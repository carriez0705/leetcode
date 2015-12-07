class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        if(!n) return wordDict.find("")!=wordDict.end();
        vector<vector<bool> > table(n, vector<bool>(n, false));
        unordered_map<char, vector<int> > charTab;
        for(int i = 0; i<n; i++){
            if(charTab.find(s[i])==charTab.end()){
                vector<int> pos(1, i);
                charTab[s[i]] = pos;
            }
            else{
                charTab[s[i]].push_back(i);
            }
        }
        for(auto iter = wordDict.begin(); iter!=wordDict.end(); iter++){
            if((*iter).size()>0 && charTab.find((*iter)[0])!=charTab.end()){
                char c = (*iter)[0];
                int len = (*iter).size();
                for(int j = 0; j<charTab[c].size(); j++){
                    if(charTab[c][j]+len-1<=n-1 && s.substr(charTab[c][j], len)==*iter){
                        table[charTab[c][j]][charTab[c][j]+len-1] = true;
                    }
                }
            }
        }
        vector<bool> f(n, false);
        for(int i = 0; i<n; i++){
            if(table[0][i])
                f[i] = true;
            else{
                for(int j = 0; j<=i; j++)
                    if(f[j]&&table[j+1][i]){
                        f[i] = true;
                        break;
                    }
            }
        }
        return f[n-1];
    }
};
