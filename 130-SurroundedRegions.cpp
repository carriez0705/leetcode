int stepi[] = {0,1,0,-1};
int stepj[] = {1,0,-1,0};
class Solution {
    void fill(int i, int j, vector<vector<char> > &board, vector<vector<int> > &color){
        int m = board.size();
        int n = m? board[0].size() : 0;
        color[i][j] = 1;
        for(int k = 0; k<4; k++){
            int nexti = i+stepi[k];
            int nextj = j+stepj[k];
            if(nexti>=0 && nexti<m && nextj>=0 && nextj<n && board[nexti][nextj]=='O' && color[nexti][nextj]==0)
                fill(nexti, nextj, board, color);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = m? board[0].size() : 0;
        if(!m || !n) return ;
        vector<vector<int> > color(m, vector<int>(n, 0));//0-untouched, 1-touched
        for(int i = 0; i<m; i++){
            if(board[i][0]=='O' && color[i][0]==0)
                fill(i, 0, board, color);
            if(board[i][n-1]=='O' && color[i][n-1]==0)
                fill(i, n-1, board, color);
        }
        for(int j = 0; j<n; j++){
            if(board[0][j]=='O' && color[0][j]==0)
                fill(0, j, board, color);
            if(board[m-1][j]=='O' && color[m-1][j]==0)
                fill(m-1, j, board, color);
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j]=='O' && color[i][j]==0)
                    board[i][j] = 'X';
            }
        }
    }
};
