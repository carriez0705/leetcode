class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > dict;
        vector<vector<string> > group;
        for(int i = 0; i<strs.size(); i++){
            string code(26,'0');
            for(int j = 0; j<strs[i].size(); j++){
                code[strs[i][j]-'a'] += 1;
            }
            if(dict.find(code)==dict.end()){
                dict[code] = vector<string>(1,strs[i]);
            }
            else
                dict[code].push_back(strs[i]);
        }
        for(auto iter = dict.begin(); iter!= dict.end(); iter++){
            sort(iter->second.begin(), iter->second.end());
            group.push_back(iter->second);
        }
        return group;
    }
};
