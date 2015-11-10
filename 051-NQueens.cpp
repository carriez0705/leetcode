class Solution {
    bool valid(vector<string> &svec, int line, int col){
        int c = col-1;
        int n = svec[0].size();
        for(int i = line-1; i>=0 && c>=0; i--, c--){
            if(svec[i][c]=='Q')
                return false;
        }
        c = col +1;
        for(int i = line-1; i>=0 && c<=n-1; i--, c++){
            if(svec[i][c]=='Q')
                return false;
        }
        return true;
    }
    void solve(int n, int line, int &column, vector<string> &svec, vector<vector<string> > &result){
        if(line==n){
            result.push_back(svec);
            return;
        }
        for(int i = 0; i<n; i++){
            if(!(column & (1<<i))){
                column |= 1<<i;
                svec[line][i] = 'Q';
                if(valid(svec, line, i))
                    solve(n, line+1, column, svec, result);
                column &= ~(1<<i);
                svec[line][i] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        int column = 0;
        vector<vector<string> > result;
        vector<string> svec(n, string(n,'.'));
        solve(n, 0, column, svec, result);
        return result;
    }
};
