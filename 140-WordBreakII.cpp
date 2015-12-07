class Solution {
    void dfs(vector<vector<int> > &table, vector<string> &vec, vector<string> &ans, const string &s, int begin){
        if(begin==s.size()){
            string temp = "";
            for(int i = 0; i<vec.size()-1; i++){
                temp.append(vec[i]);
                temp.append(" ");
            }
            temp.append(vec[vec.size()-1]);
            ans.push_back(temp);
            return;
        }
        for(int i = begin; i<s.size(); i++){
            if(table[begin][i]==1 && (i==s.size()-1 || table[i+1][s.size()-1])){
                vec.push_back(s.substr(begin, i-begin+1));
                dfs(table, vec, ans, s, i+1);
                vec.pop_back();
            }
        }
    }
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n= s.size();
        vector<string> ans;
        if(!n){
            if(wordDict.find("")!=wordDict.end()){
                ans.push_back("");
            }
            return ans;
        }
        vector<string> vec;
        vector<vector<int> > table(n, vector<int>(n, 0));//1-single word, 2-combination
        for(int len = 1; len<=n; len++){
            for(int i = 0; i<=n-len; i++){
                if(wordDict.find(s.substr(i, len))!=wordDict.end()){
                    table[i][i+len-1] = 1;
                }
                else{
                    for(int cut = i; cut<i+len-1; cut++){
                        if(table[i][cut] && table[cut+1][i+len-1]){
                            table[i][i+len-1] = 2;
                            break;
                        }
                    }
                }
            }
        }
        dfs(table, vec, ans, s, 0);
        return ans;
    }
};
