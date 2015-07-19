class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;
        for(int i = 0; i<s.size(); i++)
            num += pow(26,s.size()-i-1)*(s[i]-'A'+1);
        return num;
    }
};
