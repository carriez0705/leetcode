class Solution {
    vector<int> line;
    vector<int> column;
    vector<int> square;
    int N; 
    vector<pair<int, int> > available;
    bool check(int &line, int val){
        if(line &(1<<val)) return false;
        line |= 1<<val;
        return true;
    }
    bool solvable(vector<vector<char> > &board){
        line.clear();
        line.resize(N);
        column.clear();
        column.resize(N);
        square.clear();
        square.resize(N);
        available.clear();
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                if(board[i][j]=='.'){
                    available.push_back(pair<int, int>(i,j));
                }
                else{
                    int val = board[i][j]-'1';
                    if(!check(line[i], val)) return false;
                    if(!check(column[j], val)) return false;
                    int cube = (i/3)*3+j/3;
                    if(!check(square[cube], val)) return false;
                }
            }
        }
        return true;
    }
    bool onestep(vector<vector<char> > &board, int n){
        if(n==available.size()) return true;
        int x = available[n].first;
        int y = available[n].second;
        int cube = (x/3)*3 + y/3;
        int possible = (~line[x]) & (~column[y]) & (~square[cube]) & 0x1FF;
        if(!possible) return false;
        int solved = false;
        for(int i = 0; i<N && !solved; i++){
            if(possible & (1<<i)){
                line[x] |= 1<<i;
                column[y] |= 1<<i;
                square[cube] |= 1<<i;
                solved = onestep(board,n+1);
                if(!solved){
                    line[x] &= ~(1<<i);
                    column[y] &= ~(1<<i);
                    square[cube] &= ~(1<<i);
                }
                else{
                    board[x][y] = i+'1';
                }
            }
        }
        return solved;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        N = 9;
        if(board.size()!=N || board[0].size()!=9) return;
        if(!solvable(board)) return;
        onestep(board,0);
        
    }
};
