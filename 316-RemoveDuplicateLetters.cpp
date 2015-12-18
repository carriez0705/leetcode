class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastOcc(26, 0);
        for(int i = 0; i<s.size(); i++){
            lastOcc[s[i]-'a'] = i;
        }
        stack<int> pos;
        vector<bool> exist(26, false);
        for(int i = 0; i<s.size(); i++){
            if(!pos.empty() && exist[s[i]-'a'])
                continue;
            while(!pos.empty() && s[pos.top()]>=s[i] && pos.top()!=lastOcc[s[pos.top()]-'a']){
                if(lastOcc[s[pos.top()]-'a']<i){
                    char c = s[pos.top()];
                    pos.pop();
                    pos.push(lastOcc[c-'a']);
                    break;
                }
                else{
                    exist[s[pos.top()]-'a'] = false;
                    pos.pop();
                }
            }
            pos.push(i);
            exist[s[i]-'a'] = true;
        }
        string ans(pos.size(), 'a');
        int i = pos.size()-1;
        while(!pos.empty()){
            ans[i] = s[pos.top()];
            pos.pop();
            i--;
        }
        return ans;
    }
};
