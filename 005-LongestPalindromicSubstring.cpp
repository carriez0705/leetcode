char p[1001][1000];
class Solution {
public:
    char ispali(int i, int len, string &s){
        if(!p[len][i]){
        if(len==0|| len==1 ||(s[i]==s[i+len-1]&&ispali(i+1,len-2,s)==1)){
            p[len][i] = 1;
        }
        else p[len][i] = 2;
        }
        return p[len][i];
    }
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
        //0:uncalculate, 1:true, 2:false
        for(int len = 0; len<=s.size(); len++)
            for(int i = 0; i<=s.size()-len; i++)
                p[len][i] = 0;
        for(int len = s.size(); len>1; len--)
            for(int i = 0; i<=s.size()-len; i++){
                if(ispali(i,len,s)==1){
                    return s.substr(i,len);
                } 
            }
        return s.substr(0,1);
    }
};
