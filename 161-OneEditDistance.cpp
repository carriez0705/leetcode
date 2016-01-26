class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(abs(m-n)>1) return false;
        if(m>n) return isOneEditDistance(t,s);
        if(m==n){
            int count = 0;
            for(int i = 0; i<s.size()&&count<2; i++){
                if(s[i]!=t[i]) count++;
            }
            return count==1;
        }
        else{
            int count = 0;
            int j = 0;
            for(int i = 0; i<s.size()&&j<t.size()&&count<2; i++, j++){
                if(s[i]!=t[j]){
                    i--;
                    count++;
                }
            }
            if(j==t.size()-1) count += 1;
            return count==1;
        }
    }
};
