
class Solution {
    int helper(string s, string p, int i, int j, vector<vector<int> > &dp){
        //both -1, initial state- true
        if(i<0 && j<0) return 2;
        //no more pattern while string still holds charater waiting to match - false
        if(j<0 && i>=0) return 1;
        //no more string & still has pattern remained
        //check if pattern[j]=='*', if so , it deserves a second chance
        if(i<0){
            if(p[j]=='*') return helper(s, p, i, j-2, dp);
            else return 1;
        }
        if(dp[i][j]!=0) return dp[i][j];
        if(p[j]!='*'){
            //not '*' case:
            //dp[i][j] = (p[j]=='.'||p[j]==s[i])&&dp[i-1][j-1]
            if((p[j]=='.'|| p[j]==s[i]) && helper(s, p, i-1, j-1, dp)==2)
                dp[i][j] = 2;
            else
                dp[i][j] = 1;
        }
        else{
            int temp = i;
            //match one or more preceding character
            while(temp>=0 && (p[j-1]=='.' || s[temp]==p[j-1]) && dp[i][j]!=2){
                dp[i][j] = helper(s,p, temp, j-1, dp);
                temp--;
            }
            //match zero preceding character
            if(j>1 && dp[i][j]!=2)
                dp[i][j] = helper(s, p, i, j-2, dp);
        }
        return dp[i][j];
    }
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        if(!n) return !m;
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));//0-unsigned, 1-false, 2-true
        return helper(s, p,m-1, n-1, dp)==2;
    }
};
