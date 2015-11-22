int step1[] = {0, 1, 0, -1};
int step2[] = {1, 0, -1, 0};
class Solution {
    bool valid(int i, int j, int m, int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    bool dfs(vector<vector<char> > &board, vector<vector<bool> > &used, int i, int j, string &word, int count){
        if(count==word.size())
            return true;
        used[i][j] = true;
        int next_i = 0, next_j = 0;
        for(int k = 0; k<4; k++){
            next_i = i+step1[k];
            next_j = j+ step2[k];
            if(valid(next_i, next_j, board.size(), board[0].size()) && board[next_i][next_j]==word[count] && !used[next_i][next_j]){
                if(dfs(board, used, next_i, next_j, word, count+1))
                    return true;
            }
        }
        used[i][j] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = m? board[0].size() : 0;
        if(!m || !n || !word.size()) return false;
        vector<vector<bool> > used(m, vector<bool>(n, false));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j]==word[0]){
                    if(dfs(board, used, i, j, word, 1))
                        return true;
                }
            }
        }
        return false;
    }
};
