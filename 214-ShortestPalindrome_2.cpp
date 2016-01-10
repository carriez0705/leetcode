class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if(!n) return s;
        int i = 0, j = n-1;
        vector<int> lps;
        lps.push_back(0);
        int len = 0;
        while(i<j){
            if(i+1>lps.size()){
                int p = i;
                while(true){
                if(s[p]==s[len]){
                    len++;
                    lps.push_back(len);
                    break;
                }
                else{
                    if(len>0){
                        len = lps[len-1];
                    }
                    else{
                        lps.push_back(0);
                        break;
                    }
                }
                }
            }
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                if(i>0){
                    i = lps[i-1];
                }
                else{
                    j--;
                }
            }
        }
        string sub = "";
        if(i+j+1<n){
            sub = s.substr(i+j+1);
            reverse(sub.begin(), sub.end());
        }
        return sub+s;
    }
};
