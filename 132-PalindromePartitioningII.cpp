class Solution {
    int palindrome(const string &s, int i, int j, vector<vector<int> > &palin){
        if(palin[i][j]!=0)
            return palin[i][j];
        if(i==j)
            palin[i][j] = 1;
        else if(i+1 == j)
            palin[i][j] = s[i]==s[j] ? 1: 2;
        else
            palin[i][j] = (s[i]==s[j] && palindrome(s, i+1, j-1, palin)==1) ? 1:2;
        return palin[i][j];
    }
    //O(n^3)
    int helper(const string &s, int begin, vector<vector<int> > &palin){
        if(palindrome(s, begin, s.size()-1, palin)==1)
            return 0;
        int minc = s.size();
        for(int i = begin; i<s.size()-1; i++){
            if(palindrome(s, begin, i, palin)==1){
                minc = min(minc, 1+helper(s, i+1, palin));
            }
        }
        return minc;
    }
    //O(n^2)
    int cut(const string &s, vector<vector<int> > &palin){
        int n = s.size();
        vector<int> mincut(n, n);
        for(int i = 0; i<n; i++){
            if(palindrome(s, 0, i, palin)==1){
                mincut[i] = 0;
            }
            else{
                for(int j = i-1; j>=0; j--){
                    if(palindrome(s, j+1, i, palin)==1)
                        mincut[i] = min(mincut[i], 1+ mincut[j]);
                }
            }
        }
        return mincut[n-1];
    }
public:
    int minCut(string s) {
        if(s.size()<=1) return 0;
        int n = s.size();
        vector<vector<int> > palin(n, vector<int>(n, 0));
        return cut(s, palin);
    }
};
