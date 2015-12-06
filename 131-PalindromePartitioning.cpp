class Solution {
    int palindrome(const string &s, int i, int j, vector<vector<int> > &palin){
        if(palin[i][j]!=0)
            return palin[i][j];
        if(i==j){
            palin[i][j] = 1;
        }
        else if(i+1==j){
            palin[i][j] = s[i]==s[j]? 1: 2;
        }
        else{
            palin[i][j] = (s[i]==s[j] && palindrome(s, i+1, j-1, palin)==1) ? 1:2;
        }
        return palin[i][j];
    }
    void helper(const string &s, int begin, vector<string> &vec, vector<vector<string> > &ans, vector<vector<int> > &palin){
        if(begin==s.size()){
            ans.push_back(vec);
            return;
        }
        for(int i = begin; i<s.size(); i++){
            if(palindrome(s, begin, i, palin)==1){
                vec.push_back(s.substr(begin, i-begin+1));
                helper(s, i+1, vec, ans, palin);
                vec.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string> > ans;
        if(!n) return ans;
        vector<string> vec;
        vector<vector<int> > palin(n, vector<int>(n, 0));
        helper(s, 0, vec, ans, palin);
        return ans;
    }
};
