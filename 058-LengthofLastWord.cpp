class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        while(i>=0 && s[i]==' ')
            i--;
        if(i<0) return 0;
        int end = i;
        while(i>=0 && s[i]!=' ')
            i--;
        return end-i;
    }
};
