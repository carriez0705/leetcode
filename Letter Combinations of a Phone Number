class Solution {
    vector<string> vec;
    vector<string> re;
public:
    void dfs(int n, string &digits, string &result){
        if(n==digits.size()){
            re.push_back(result);
            return;
        }
            
        int c = digits[n]-'0';
        for(int i = 0; i<vec[c].size();i++){
            result.push_back(vec[c][i]);
            dfs(n+1,digits,result);
            result.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return re;
        string str[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i = 0;i<10;i++){
            vec.push_back(str[i]);
        }
        string result = "";
        dfs(0,digits,result);
        return re;
    }
};
