class Solution {
public:
    void decode(string &version1, vector<int> &vec){
        int i = 0, v = 0;
        while(i<version1.size()){
            if(version1[i]!='.'){
                v = v*10 +version1[i]-'0';
            }
            else{
                vec.push_back(v);
                v = 0;
            }
            i++;
        }
        vec.push_back(v);
    }
    int compareVersion(string version1, string version2) {
        if(!version1.length() || !version2.length()) return -1;
        vector<int> v1, v2;
        decode(version1,v1);
        decode(version2,v2);
        int i = 0, j = 0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i]>v2[j]) return 1;
            if(v1[i]<v2[j]) return -1;
            i++;
            j++;
        }
        if(i<v1.size() && v1[i]!=0) return 1;
        if(j<v2.size() && v2[j]!=0) return -1;
        return 0;
    }
};
