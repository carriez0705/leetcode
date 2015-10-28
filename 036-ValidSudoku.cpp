class Solution {
    bool check(int &line, int val){
        if(line&(1<<val))
            return false;
        line |= 1<<val;
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        if(board.size()!=n || board[0].size()!=n) return false;
        vector<int> column(n, 0);
        vector<int> square(n, 0);
        for(int i = 0; i<n; i++){
            int line = 0;
            for(int j = 0; j<n; j++){
                if(board[i][j]=='.')
                    continue;
                int val = board[i][j]-'0';
                if(!check(line, val))
                    return false;
                if(!check(column[j], val))
                    return false;
                int cube = (i/3)*3 + j/3;
                if(!check(square[cube], val))
                    return false;
            }
        }
        return true;
    }
};
