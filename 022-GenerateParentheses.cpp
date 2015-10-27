class Solution {
    void generate(int n, vector<set<string> > &dp){
	if(dp[n].size()){ return;}
	if(n==0) dp[n].insert("");
	else{
	for(int i = 0; i<n-1; i++){
	    generate(i+1, dp);
	    generate(n-i-1, dp);
	    for(auto p = dp[i+1].begin(); p!=dp[i+1].end(); p++){
		for(auto q = dp[n-i-1].begin(); q!=dp[n-i-1].end(); q++){
		    dp[n].insert(*p+*q);
		}
	    }
	}
	
	for(auto p = dp[n-1].begin(); p!=dp[n-1].end();p++){
	    dp[n].insert("("+ *p + ")");
	}
	}
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<set<string> > dp(n+1, set<string>());
        generate(0, dp);
	    generate(n, dp);
	    vector<string> result(dp[n].begin(), dp[n].end());
	    return result;
    }
};
