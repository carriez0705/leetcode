class Solution {
    void dfs(int begin, int end, vector<vector<int> > &count){
        if(count[begin][end]!= -1) return;
        if(begin>=end){
            count[begin][end] = 1;
            return;
        }
        int sum = 0;
        for(int i = begin; i<=end; i++){
            if(count[begin][i-1]==-1)
                dfs(begin, i-1, count);
            if(count[i+1][end]==-1)
                dfs(i+1, end, count);
            sum += count[begin][i-1]*count[i+1][end];
        }
        count[begin][end] = sum;
    }
public:
    int numTrees(int n) {
        if(n==0 || n==1) return 1;
        vector<vector<int> > count(n+2, vector<int>(n+1, -1));
        dfs(1, n, count);
        return count[1][n];
    }
};
