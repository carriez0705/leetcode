class Solution {
public:
    bool isValid(string s) {
        stack<char> stc;
        unordered_set<char> left;
        unordered_map<char, char> right;
        left.insert('(');
        left.insert('{');
        left.insert('[');
        right[')'] = '(';
        right['}'] = '{';
        right[']'] = '[';
        for(int i = 0; i<s.size(); i++){
            if(left.find(s[i])!=left.end())
                stc.push(s[i]);
            else if(right.find(s[i])!=right.end()){
                if(stc.empty() || stc.top()!=right[s[i]])
                    return false;
                stc.pop();
            }
        }
        return stc.empty();
    }
};
