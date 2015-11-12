class NumMatrix {
    vector<vector<int> > subsum;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        subsum.clear();
        int n = matrix.size();
        if(n){
            int m = matrix[0].size();
            vector<vector<int> > sub(n, vector<int>(m,0));
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    int up = i-1<0? 0 : sub[i-1][j];
                    int left = j-1<0? 0: sub[i][j-1];
                    int corner = (i-1<0 || j-1<0)? 0 : sub[i-1][j-1];
                    sub[i][j] = up+left-corner + matrix[i][j];
                }
            }
            subsum = sub;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int all = subsum[row2][col2];
        int sub1 = row1-1<0 ? 0 :subsum[row1-1][col2];
        int sub2 = col1-1<0 ? 0: subsum[row2][col1-1];
        int sub3 = (row1-1<0 || col1-1<0)? 0 :subsum[row1-1][col1-1];
        return all-sub1-sub2+sub3;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
