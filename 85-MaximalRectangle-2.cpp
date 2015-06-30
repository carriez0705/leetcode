class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!matrix.size()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int> > left(n,vector<int>(m));
        vector<vector<int> > right(n,vector<int>(m));
        vector<vector<int> > height(n,vector<int>(m));
        int ll = 0, rr = m-1;
        int maxarea = 0;
        //first line
        for(int i = 0; i<m; i++){
            if(matrix[0][i]-'0'){
                left[0][i] = ll;
                height[0][i] = 1;
            }
            else{
                left[0][i] = 0;
                right[0][i] = m-1;
                height[0][i] = 0;
                ll = i+1;
            }
        }
        for(int i = m-1; i>=0; i--){
            if(matrix[0][i]-'0'){
                right[0][i] = rr;
                maxarea = max(maxarea, (right[0][i]-left[0][i]+1)*height[0][i]);
            }
            else{
                rr = i-1;
            }
        }
        //others
        for(int i = 1; i<n; i++){
            ll = 0;
            rr = m-1;
            for(int j = 0; j<m; j++){
                if(matrix[i][j]-'0'){
                    left[i][j] = max(left[i-1][j], ll);
                    height[i][j] = height[i-1][j] + 1;
                }
                else{
                    left[i][j] = 0;
                    right[i][j] = m-1;
                    height[i][j] = 0;
                    ll = j+1;
                }
            }
            for(int j = m-1; j>=0; j--){
                if(matrix[i][j]-'0'){
                    right[i][j] = min(right[i-1][j], rr);
                    maxarea = max(maxarea, (right[i][j]-left[i][j]+1)*height[i][j]);
                }
                else{
                    rr = i-1;
                }
            }
        }
        return maxarea;
    }
};
