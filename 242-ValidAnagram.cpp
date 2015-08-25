class Solution {
public:
    bool isAnagram(string s, string t) {
        if(!s.size() && !t.size()) return true;
        if(s.size()!=t.size()) return false;
        vector<int> vec1(26,0);
        vector<int> vec2(26,0);
        for(int i = 0;i<s.size();i++){
            vec1[s[i]-'a'] +=1;
            vec2[t[i]-'a'] +=1;
        }
        for(int i = 0; i<vec1.size(); i++)
            if(vec1[i]!=vec2[i]) return false;
        return true;
    }
};
