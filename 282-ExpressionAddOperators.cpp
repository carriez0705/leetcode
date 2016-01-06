class Solution {
    bool valid(string s){
        return s.size()<2 || s[0]!='0';
    }
    void dfs(string num, int target, int index, long long tot, long long prev, string s, vector<string> &ans){
        if(index>=num.size()){
            if(tot+prev==target)
                ans.push_back(s);
            return;
        }
        for(int i = index; i<num.size(); i++){
            string sub = num.substr(index, i-index+1);
            if(!valid(sub))
                continue;
            long long number = stoll(sub);
            if(number>INT_MAX) continue;
            dfs(num, target, i+1, tot+prev, number, s+"+"+sub, ans);
            dfs(num, target, i+1, tot+prev, -number, s+"-"+sub, ans);
            dfs(num, target, i+1, tot, prev*number, s+"*"+sub, ans);
            //dfs(num, target, i+1, tot, prev/number, s+"/"+sub, ans);
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        for(int i = 0; i<num.size(); i++){
            string sub = num.substr(0, i+1);
            if(!valid(sub))
                continue;
            //long long, long long, long long, important thing goes 3 times
            long long number = stoll(sub);
            if(number>INT_MAX) continue;
            long long tot = 0, prev = number;
            dfs(num, target, i+1, tot, prev,  sub, ans);
        }
        return ans;
    }
};
