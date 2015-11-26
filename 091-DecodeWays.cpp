class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(!n) return 0;
        vector<int> c(n+1, 0);
        c[0] = 1;
        if(s[0]!='0')
            c[1] = 1;
        for(int i = 1; i<n; i++){
            if(s[i]!='0')
                c[i+1] += c[i];
            if(s[i-1]=='1' ||(s[i-1]=='2' && s[i]<='6'))
                c[i+1] += c[i-1];
        }
        return c[n];
    }
};
