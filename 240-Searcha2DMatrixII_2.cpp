class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        int x = matrix.size()-1, y = 0;
        while(x>=0 && y<matrix[0].size()){
            if(matrix[x][y]==target) return true;
            else if(matrix[x][y]>target) x--;
            else y++;
        }
        return false;
    }
};
