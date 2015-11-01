class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> left;
        stack<pair<int, int> > right;
        int maxlen = 0;
        int curlen = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='(')
                left.push(i);
            else{
                if(!left.empty()){
                    int start = left.top();
                    left.pop();
                    while(!right.empty() && right.top().first>start){
                        right.pop();
                    }
                    if(!right.empty() && right.top().first==start-1){
                        curlen = right.top().second + i-start+1;
                        right.pop();
                    }
                    else{
                        curlen = i-start+1;
                    }
                    maxlen = max(maxlen, curlen);
                    right.push(pair<int, int>(i, curlen));
                }
            }
        }
        return maxlen;
    }
};
