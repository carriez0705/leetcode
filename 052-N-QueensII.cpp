
class Solution {
    bool valid(int line, int col, vector<int> &permutation){
        for(int i = 0; i<line; i++){
            if(abs(permutation[i]-permutation[line]) == line-i)
                return false;
        }
        return true;
    }
    void solve(int n, int line, int &used, vector<int> &permutation, int &result){
        if(line==n){
            result += 1;
            return;
        }
        for(int i = 0; i<n; i++){
            if(!(used & (1<<i))){
                used |= 1<<i;
                permutation[line] = i;
                if(valid(line, i, permutation))
                    solve(n, line+1, used, permutation, result);
                used &= ~(1<<i);
            }
        }
    }
public:
    int totalNQueens(int n) {
        int result = 0;
        int used = 0;
        vector<int> permutation(n, 0);
        solve(n, 0, used, permutation, result);
        return result;
    }
};
