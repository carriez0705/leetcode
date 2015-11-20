class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m==0? 0: matrix[0].size();
        if(!m || !n) return;
        bool col0 = false;
        bool row0 = false;
        for(int i = 0; i<m && !col0; i++)
            if(matrix[i][0]==0)
                col0 = true;
       
            for(int j = 0; j<n && !row0; j++)
                if(matrix[0][j]==0)
                    row0 = true;
        
        
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(!matrix[i][j]){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i<m; i++)
            for(int j = 1; j<n; j++){
                if(!matrix[0][j] || !matrix[i][0])
                    matrix[i][j] = 0;
            }
        if(col0){
            for(int i = 0; i<m; i++)
                matrix[i][0] = 0;
        }
        if(row0){
            for(int j = 0; j<n; j++)
                matrix[0][j] = 0;
        }
    }
};
