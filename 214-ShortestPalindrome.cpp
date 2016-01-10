class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if(!n) return s;
        int i = 0, j = n-1;
        int k = 26;
        vector<vector<int> > dfa(k, vector<int>(1, 0));
        int X = 0;
        dfa[s[0]-'a'][0] = 1;
        while(i<j){
            if(i+1>dfa[0].size()){
                //continue construct dfa
                for(int p = 0; p<k; p++){
                    dfa[p].push_back(dfa[p][X]);
                }
                dfa[s[i]-'a'][i] = i+1;
                X = dfa[s[i]-'a'][X];
            }
            i = dfa[s[j]-'a'][i];
            j--;
        }
        string sub = "";
        if(i+j+1<n)
        {sub = s.substr(i+j+1);
        reverse(sub.begin(), sub.end());
        }
        return sub+s;
    }
};
