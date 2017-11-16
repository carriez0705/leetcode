class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ret;
        helper(0, -1, 0, s, ret);
        if(ret.empty()) ret.push_back("");
        return ret;
    }
private:
    string reverseParentheses(string s)
    {
        string ret;
        for(char c : s)
        {
            if(c=='(') ret.push_back(')');
            else if(c==')') ret.push_back('(');
            else ret.push_back(c);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    void helper(int i, int valid, int cnt, string cur, vector<string> &ret)
    {
        if(i == cur.size())
        {
            if(cnt)
            {
                vector<string> reverseRet;
                string rstr = reverseParentheses(cur);
                helper(0, -1, 0, rstr, reverseRet);
                for(string str : reverseRet)
                {
                    ret.push_back(reverseParentheses(str));
                }
            }
            else
            {
                ret.push_back(cur);
            }
            return;
        }
        if(cur[i] == '(')
        {
            cnt++;
            helper(i+1, valid, cnt, cur, ret);
        }
        else if(cur[i] == ')')
        {
            cnt--;
            if(cnt < 0)
            {
                for(int j = valid + 1; j <=i; ++j)
                {
                    if(cur[j] == ')')
                    {
                        string str(cur);
                        str.erase(str.begin() + j);
                        helper(i, j-1, 0, str, ret);
                        int k = j+1;
                        while(k <= i && cur[k] == ')')
                        {
                            k++;
                        }
                        j = k-1;
                    }                  
                }
            }
            else
            {
                helper(i+1, valid, cnt, cur, ret);
            }
        }
        else
        {
            helper(i+1, valid, cnt, cur, ret);
        }
    }
};
