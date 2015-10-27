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

//solution 2- pattern search
//not suitable for this one- needle search, O(n) space complexity
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(!needle.size()) return 0;
        if(!haystack.size() || haystack.size()<needle.size()) return -1;
        int N = 256;
        vector<vector<int> > dfa(N, vector<int>(needle.size(),0));
        for(int j = 0; j<N; j++){
            dfa[j][0] = 0;
        }
        dfa[needle[0]][0] = 1;
        int X = 0;
        for(int i = 1; i<needle.size(); i++){
            for(int j = 0; j<N; j++)
                dfa[j][i] = dfa[j][X];
            dfa[needle[i]][i] = i+1;
            X = dfa[needle[i]][X];
        }
        int k = 0;
        for(int i = 0; i<haystack.size(); i++){
            k = dfa[haystack[i]][k];
            if(k==needle.size())
                return i-k+1;
            if(haystack.size()-i<=needle.size()-k)
                break;
        }
        return -1;
    }
};
