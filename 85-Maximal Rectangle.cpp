class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(!n) return 0;
        int m = matrix[0].size();
        vector<vector<int> > nodvec;
        for(int i = 0; i<n; i++){
            vector<int> nod;
            for(int j = 0; j<m; j++){
                nod.push_back(-1);
            }
            nodvec.push_back(nod);
        }
        for(int i = 0; i<n; i++){
            int le = -1;
            for(int j = 0; j<m; j++){
                if(matrix[i][j]-'0'){
                    le = (le==-1)?j:le;
                }
                else
                    le = -1;
                nodvec[i][j] = le;
            }
        }
        int maxs = 0;
        for(int i = 0; i<n; i++){
            for(int j = m-1; j>=0; j--){
                if(matrix[i][j]-'0'){
                    int minle = nodvec[i][j];
                    int imax = j-nodvec[i][j]+1;
                    for(int p = i+1; p<n; p++){
                        if(matrix[p][j]-'0'){
                            minle = max(minle,nodvec[p][j]);
                            int area = (p-i+1)*(j-minle+1);
                            imax = max(imax, area);
                        }
                        else{
                            break;
                        }
                    }
                    maxs = max(maxs,imax);
                }
            }
        }
        return maxs;
    }
};
