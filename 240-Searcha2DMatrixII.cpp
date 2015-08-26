class Solution {
public:
    bool search(vector<vector<int> > &matrix, int t, int top, int bot, int left, int right){
        if(top>bot || left>right) return false;
        int n = (top&bot)+((top^bot)>>1);
        int m = (left&right)+((left^right)>>1);
        if(matrix[n][m]==t) return true;
        else if(matrix[n][m]>t)
            return search(matrix, t, top, bot, left, m-1) ||search(matrix, t, top, n-1, m, right);
        else
            return search(matrix, t, n+1, bot, left, m) || search(matrix, t, top, bot, m+1, right);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        return search(matrix, target, 0, matrix.size()-1, 0, matrix[0].size()-1);
    }
};
