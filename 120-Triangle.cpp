class Solution {
    void path(vector<vector<int> > &triangle, int i, vector<int> &vec){
        int temp = vec[0];
        for(int j = 0; j<=i; j++){
            int last = vec[j];
            if(j==0)
                vec[j] += triangle[i][j];
            else if(j==i)
                vec[j] = temp + triangle[i][j];
            else{
                vec[j] = min(vec[j], temp)+triangle[i][j];
            }
            temp = last;
            //cout<<vec[j]<<" ";
        }
        //cout<<endl;
        if(i!=vec.size()-1)
            path(triangle, i+1, vec);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int minpath = INT_MAX;
        vector<int> vec(n, 0);
        path(triangle,0,vec);
        for(int j = 0; j<n; j++)
            minpath = min(minpath, vec[j]);
        return minpath;
    }
};
