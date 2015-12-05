//stack overflow for dfs because of deep recursion
//use bfs
class Solution {
    bool addNode(int i, int j, vector<vector<char> > &board, queue<int> &xque, queue<int> &yque){
        if(i<0 || i>board.size()-1 || j<0 ||j>board[0].size()-1 || board[i][j]!='O')
            return false;
        board[i][j] = '#';
        xque.push(i);
        yque.push(j);
        return true;
    }
    void fill(vector<vector<char> > &board, queue<int> &xque, queue<int> &yque){
        static int stepi[] = {0,1,0,-1};
        static int stepj[] = {1,0,-1,0};
        while(!xque.empty()){
            int x = xque.front();
            xque.pop();
            int y = yque.front();
            yque.pop();
            for(int k = 0; k<4; k++){
                int nextx = x+stepi[k];
                int nexty = y+stepj[k];
                addNode(nextx, nexty, board, xque, yque);
            }
        }
    }
public:
    void solve(vector<vector<char>> &board) {
        int m = board.size();
        int n = m? board[0].size() : 0;
        if(!m || !n) return ;
        queue<int> xque;
        queue<int> yque;
        for(int i = 0; i<m; i++){
            if(addNode(i, 0, board, xque, yque))
                fill(board, xque, yque);
            if(addNode(i, n-1, board, xque, yque))
                fill(board, xque, yque);
        }
        for(int j = 0; j<n; j++){
            if(addNode(0,j,board, xque, yque))
                fill(board, xque, yque);
            if(addNode(m-1, j, board, xque, yque))
                fill(board, xque, yque);
        }
        for(int i = 0; i<m; i++)
            for(int j = 0; j<n; j++){
                if(board[i][j]=='#')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
    }
};
