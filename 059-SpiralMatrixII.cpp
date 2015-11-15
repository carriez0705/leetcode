class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(!n) return vector<vector<int> >();
        int num = n*n;
        vector<vector<int> > ans(n, vector<int>(n,0));
        int count = 1;
        int left = 0, right = n-1;
        int up = 1, down = n-1;
        int direction = 0;// 0-right, 1-down, 2-left, 3-up
        int i = 0, j = 0;
        while(count<=num){
            ans[i][j] = count;
            count += 1;
            switch(direction){
                case 0:
                    j++;
                    if(j>right){
                        j = right;
                        i += 1;
                        right -= 1;
                        direction =1;
                    }
                    break;
                case 1:
                    i++;
                    if(i>down){
                        i = down;
                        j -=1;
                        down -=1;
                        direction = 2;
                    }
                    break;
                case 2:
                    j--;
                    if(j<left){
                        j = left;
                        i -= 1;
                        left += 1;
                        direction = 3;
                    }
                    break;
                case 3:
                    i--;
                    if(i<up){
                        i = up;
                        j += 1;
                        up += 1;
                        direction = 0;
                    }
            }
        }
        return ans;
    }
};
