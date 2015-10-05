class Solution {
    int detect(vector<vector<int> > &board, int i, int j){
        int n = board.size();
        int m = board[0].size();
        int low = max(0,i-1);
        int high = min(n-1, i+1);
        int left = max(0,j-1);
        int right = min(m-1, j+1);
        int live = 0;
        for(int p = low; p<=high; p++)
            for(int q = left; q<=right; q++)
                live += board[p][q]&1;
        live -= board[i][j]&1;
        return live;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = n?board[0].size():0;
        if(!n||!m) return;
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++){
                int live = detect(board, i, j);
                if(board[i][j]&1){
                    if(live==2||live==3)
                        board[i][j]+=2;
                }
                else
                    if(live==3)
                        board[i][j] +=2;
            }
       for(int i =0; i<n; i++)
            for(int j = 0; j<m; j++){
                board[i][j] = board[i][j]>>1;
            }
    }
};
