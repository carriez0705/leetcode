class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size()==0) return 0;
        stack<int> num;
        set<char> ops;
        ops.insert('+');
        ops.insert('-');
        ops.insert('*');
        ops.insert('/');
        for(int i = 0; i<tokens.size(); i++){
            if(tokens[i].size()==1 && ops.find(tokens[i][0])!=ops.end()){
                if(num.empty()) return 0;
                int second = num.top();
                num.pop();
                if(num.empty()) return tokens[i][0]=='-'? 0-second :second;
                int first = num.top();
                num.pop();
                int res = first;
                switch(tokens[i][0]){
                    case '+':
                        res += second;
                        break;
                    case '-':
                        res -= second;
                        break;
                    case '*':
                        res *= second;
                        break;
                    case '/':
                        res = second==0? 0: res/second;
                        break;
                }
                num.push(res);
            }
            else{
                num.push(stoi(tokens[i]));
            }
        }
        return num.empty() ? 0: num.top();
    }
};
