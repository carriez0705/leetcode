class Solution {
public:
    int uniquePaths(int m, int n) {
       if(!m || !n) return 0;
       vector<int> ans(n, 1);
       for(int i = 1; i<m; i++){
           for(int j = 0; j<n; j++){
               int left = j==0? 0: ans[j-1];
               ans[j] += left;
           }
       }
       return ans[n-1];
    }
};
