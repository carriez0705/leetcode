//solution 1- brute force 
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(!needle.size()) return 0;
        if(!haystack.size() || needle.size()>haystack.size()) return -1;
        for(int i = 0; i<=haystack.size()-needle.size(); i++){
            if(haystack[i]==needle[0]){
                int p = i+1;
                int q = 1;
                while(p<haystack.size() && q<needle.size() && haystack[p]==needle[q]){
                    p++;
                    q++;
                }
                if(q==needle.size())
                    return i;
            }
        }
        return -1;
    }
};
