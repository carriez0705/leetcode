class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        vector<int> exist(256,0);
        vector<int> find(256,0);
        for(int i = 0; i<256; i++){
            exist[i] = 0;
            find[i] = 0;
        }
        for(int i= 0; i<t.size(); i++)
            exist[t[i]] += 1;
        int n = t.size();
        int cur_start = 0;
        int start = -1, len = INT_MAX;
        int count = 0;
        for(int i = 0; i<s.size(); i++){
            if(exist[s[i]]){
                find[s[i]]++;
                if(find[s[i]]<=exist[s[i]])
                    count++;
                for(int j = cur_start; j<=i-n; j++){
                    if(!exist[s[j]])
                        cur_start++;
                    else if(find[s[j]]>exist[s[j]]){
                        cur_start++;
                        find[s[j]]--;
                    }
                    else
                        break;
                }
                if(count==n){
                    int cur_len = i-cur_start +1;
                    if(cur_len<len){
                        len = cur_len;
                        start = cur_start;
                    }
                }
            }
        }
        if(start ==-1) return "";
        return s.substr(start, len);
    }
};

//method 2
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size() || !t.size()) return "";
        unordered_map<char, int> exist;
        unordered_map<char, int> find;
        unordered_map<char, vector<int>> position;
        int count = 0;
        for(int i = 0; i<256; i++){
            exist[i] = 0;
        }
        for(int i= 0; i<t.size(); i++){
            exist[t[i]] += 1;
            find[t[i]] = 0;
            position[t[i]] = vector<int>();
        }
        int n = t.size();
        int start = -1;
        int cur_start = -1;
        int len = INT_MAX;
        for(int i = 0; i<s.size(); i++){
            if(exist[s[i]]){
                if(find[s[i]]<exist[s[i]]){
                    count++;
                    find[s[i]] += 1;
                    position[s[i]].push_back(i);
                    if(cur_start==-1) cur_start = i;
                }
                else{
                    int old = position[s[i]][0];
                    position[s[i]].erase(position[s[i]].begin());
                    if(old==cur_start){
                        cur_start = i;
                        for(auto iter= position.begin(); iter!=position.end(); iter++){
                            if(iter->second.size())
                                cur_start = min(cur_start, iter->second[0]);
                        }
                    }
                    
                    position[s[i]].push_back(i);
                }
                int cur_len = i-cur_start+1;
                if(count==n && (cur_len < len)){
                    start = cur_start;
                    len = cur_len;
                }
            }
        }
        if(start==-1)
            return "";
        return s.substr(start, len);
    }
};
