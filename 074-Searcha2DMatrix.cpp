//O(logmn)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = m? matrix[0].size(): 0;
        int left = 0, right = m*n-1;
        while(left<=right){
            int mid = (left+right)>>1;
            int i = mid/n;
            int j = mid%n;
            if(matrix[i][j]==target)
                return true;
            else if(matrix[i][j]<target)
                left = mid+1;
            else
                right = mid-1;
        }
        return false;
    }
};

//O(m+n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = m? matrix[0].size(): 0;
        int row = 0, col = n-1;
        while(row<m && col>=0){
            if(matrix[row][col]== target)
                return true;
            else if(matrix[row][col]< target)
                row++;
            else
                col--;
        }
        return false;
    }
};
