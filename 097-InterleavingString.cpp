class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if(!m ) return s3==s2;
        if(!n) return s3==s1;
        vector<vector<int> > count(n+1, vector<int>(m+1, 0));
        if(m+n != s3.size()) return false;
        for(int i = 1; i<=m; i++){
            if(s3[count[0][i-1]]==s1[i-1])
                count[0][i] = count[0][i-1] + 1;
        }
        for(int j = 1; j<=n; j++){
            if(s3[count[j-1][0]]==s2[j-1])
                count[j][0] = count[j-1][0] + 1;
        }
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s3[count[i-1][j]]==s2[i-1])
                    count[i][j] = count[i-1][j]+1;
                if(s3[count[i][j-1]]==s1[j-1])
                    count[i][j] = max(count[i][j], count[i][j-1]+1);
            }
        }
        return count[n][m] == s3.size();
    }
};
