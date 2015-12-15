class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(!s1.size() && !s2.size()) return true;
        if(s1.size()!=s2.size()) return false;
        int n = s1.size();
        vector<vector<vector<bool> > > f(n+1, vector<vector<bool> >(n, vector<bool>(n, false)));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++)
                f[1][i][j] = s1[i]==s2[j];
        }
        for(int k = 2; k<=n; k++){
            for(int i = 0; i<=n-k; i++){
                for(int j = 0; j<=n-k; j++){
                    int k1 = 1, k2 = k-k1;
                    for(; k1<k; k1++){
                        k2 = k-k1;
                        if((f[k1][i][j] && f[k2][i+k1][j+k1]) || (f[k1][i][j+k2] && f[k2][i+k1][j])){
                            f[k][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return f[n][0][0];
    }
};
