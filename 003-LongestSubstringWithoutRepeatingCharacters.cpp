class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(256,-1);
        int maxlen = 0;
        int start = 0;
        for(int i = 0; i<s.size(); i++){
            if(pos[s[i]]>=start){
                maxlen = max(maxlen, i-start);
                start = pos[s[i]]+1;
            }
            pos[s[i]] = i;
        }
        maxlen = max(maxlen, (int)s.size()-start);
        return maxlen;
    }
};
