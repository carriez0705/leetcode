class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i<j){
            while(i<j && !((s[i]>='a' && s[i]<='z') ||(s[i]>='A' && s[i]<='Z') ||(s[i]>='0'&&s[i]<='9'))){
                i++;
            }
            if(s[i]>='A' && s[i]<='Z')
                s[i] += 'a'-'A';
            while(j>i && !((s[j]>='a' && s[j]<='z') ||(s[j]>='A' && s[j]<='Z') || (s[j]>='0' && s[j]<='9'))){
                j--;
            }
            if(s[j]>='A' && s[j]<='Z')
                s[j] += 'a'-'A';
            if(i>=j) return true;
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true; 
    }
};
