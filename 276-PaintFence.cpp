class Solution {
public:
    int numWays(int n, int k) {
        if(n<=0 || k<=0) return 0;
        vector<vector<int> > post(n, vector<int>(2,0));
        post[0][0] = k;
        for(int i = 1; i<n; i++){
            post[i][0] = (post[i-1][0]+post[i-1][1])*(k-1);
            post[i][1] = post[i-1][0];
        }
        return post[n-1][0]+post[n-1][1];
    }
};
