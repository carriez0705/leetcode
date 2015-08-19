class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char charmap[128];
        char rcharmap[128];
        for(int i = 0; i<128; i++){
            charmap[i]=-1;
            rcharmap[i]=-1;
        }
        for(int i = 0; i<s.size();i++){
            if(charmap[s[i]]==-1&&rcharmap[t[i]]==-1){
                charmap[s[i]]=t[i];
                rcharmap[t[i]]=s[i];
            }
            else if(charmap[s[i]]!=t[i] ||rcharmap[t[i]]!=s[i])
                return false;
        }
        return true;
    }
};
