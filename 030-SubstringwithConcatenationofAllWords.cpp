class Solution {
    void build(vector<string> &words, unordered_map<string, int> &used){
        used.clear();
        for(string word:words){
            if(used.find(word)==used.end())
                used[word] = 1;
            else
                used[word] += 1;
        }
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(!words.size() || !words[0].size()){result.push_back(0); return result;}
        int n = words.size();
        int m = words[0].size();
        if(s.size()<m*n) return result;
        unordered_map<string, int> used;
        for(int i = 0; i<m; i++){
            build(words, used);
            int count = 0;
            int start = -1;
            for(int j = i; j<=s.size()-m; j+=m){
                string temp = s.substr(j, m);
                if(used.find(temp)!=used.end() && used[temp]!=0){
                    if(start == -1) start = j;
                    count++;
                    used[temp]--;
                }
                else if(used.find(temp)==used.end()){
                    if(count>0){
                    for(int k = start; k<j; k+=m){
                        string del = s.substr(k, m);
                        used[del]++;
                    }
                    count = 0;
                    start = -1;
                    }
                }
                else{
                    for(int k = start; k<j; k+=m){
                        string del = s.substr(k, m);
                        start += m;
                        if(del != temp){
                            count--;
                            used[del]++;
                        }
                        else
                            break;
                    }
                }
                if(count==n) {
                    result.push_back(start);
                    string del = s.substr(start, m);
                    used[del]++;
                    start += m;
                    count -= 1;
                }
            }
        }
        return result;
    }
};
