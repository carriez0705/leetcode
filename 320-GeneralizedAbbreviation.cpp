class Solution {
    void dfs(string &word, int st, int num, string str, vector<string> &ans){
        if(st==word.size()){
            if(num>0){
                str += to_string(num);
            }
            ans.push_back(str);
            return;
        }
        dfs(word, st+1, num+1, str, ans);
        if(num>0)
            str+= to_string(num);
        str.push_back(word[st]);
        dfs(word, st+1, 0, str, ans);
    }
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        dfs(word, 0, 0, "", ans);
        return ans;
    }
};
