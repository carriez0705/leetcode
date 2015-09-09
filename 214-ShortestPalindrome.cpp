class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if(n<2) return s;
        int M = 26;
        vector<vector<int> > dfa(M, vector<int>(n/2+1,0));
        for(int k = 0; k<M; k++)
            dfa[k][0] = 0;
        dfa[s[0]-'a'][0] = 1;
        int X = 0;
        int j = 0, i= n-1;
        int cur = 0;
        for(;i>j;i--){
            if(j>cur){
                for(int k = 0; k<M;k++)
                    dfa[k][j] = dfa[k][X];
                dfa[s[j]-'a'][j] = j+1;
                X = dfa[s[j]-'a'][X];
                cur = j;
            }
            j = dfa[s[i]-'a'][j];
        }
        string sub = "";
        if(j==0)
            sub = s.substr(1,n-1);
        else{
            if(i==j) sub = s.substr(i+j+1, n-2*j-1);
            else sub = s.substr(i+j+1, n-2*j);
        }
        int p = 0, q= sub.size()-1;
        while(p<q){
            swap(sub[p], sub[q]);
            p++;
            q--;
        }
        return sub+s;
    }
};
