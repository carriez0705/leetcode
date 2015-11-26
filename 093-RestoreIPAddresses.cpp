class Solution {
    bool check(string &candidate){
        int n = candidate.size();
        if(n>3 || n<1) return false;
        if(candidate[0]=='0' && n>1) return false;
        if(stoi(candidate)>255) return false;
        return true;
    }
    void dfs(int index, string &s,int begin, string &ip, vector<string> &ans){
        if(index==4){
            string sub = s.substr(begin, s.size()-begin);
            if(check(sub)){
                ip.push_back('.');
                ip.append(s.substr(begin, s.size()-begin));
                ans.push_back(ip);
            }
            return;
        }
        int len = ip.size();
        for(int end = begin; end<min((int)(s.size()-4+index), begin+3); end++){
            string sub = s.substr(begin, end-begin+1);
            if(check(sub)){
                if(index!=1) ip.push_back('.');
                ip.append(sub);
                dfs(index+1, s, end+1, ip, ans);
                ip.erase(len, ip.size()-len);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if(s.size()<4) return ans;
        string ip = "";
        dfs(1, s, 0, ip, ans);
        return ans;
    }
};
