class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(!n) return 0;
        int m = matrix[0].size();
        int maxs = 0;
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++){
                if(matrix[i][j]-'0'){
                    int k = 1;
                    int imax = 1;
                    maxs = max(maxs, imax);
                    bool flag = true;
                    while((i+k<n)&&(j+k<m)&&(matrix[i][j+k]-'0')&&(matrix[i+k][j]-'0')){
                        for(int p = 1; p<=k; p++){
                            if(!(matrix[i+p][j+k]-'0')||!(matrix[i+k][j+p]-'0')){
                                flag = false;
                                break;
                            }
                        }
                        if(!flag)
                            break;
                        imax = (k+1)*(k+1);
                        maxs = max(maxs,imax);
                        k++;
                    }
                }
            }
        return maxs;
    }
};
