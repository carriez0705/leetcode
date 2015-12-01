class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1, 1);
        if(rowIndex==0) return ans;
        for(int i = 0; i<=rowIndex; i++){
            int n1 = ans[0], n2 = ans[1];
            for(int j = 1; j<=i; j++){
                if(j==i){
                    ans[j] = 1;
                }
                else{
                    int num = n1 + n2;
                    n1 = n2;
                    n2 = ans[j+1];
                    ans[j] = num;
                }
            }
        }
        return ans;
    }
};
