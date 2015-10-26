class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(!n) return "";
        sort(strs.begin(), strs.end());
        int i = 0;
        int min_ = min(strs[0].size()-1, strs[n-1].size()-1);
        while(i<=min_ && strs[0][i]==strs[n-1][i]){
            i++;
        }
        return strs[0].substr(0, i);
    }
};
