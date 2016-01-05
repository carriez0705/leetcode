class Solution {
public:
    int calculate(string s) {
        if(!s.size()) return 0;
        vector<string> postorder;
        stack<char> ops;
        int i = 0;
        while(i<s.size()){
            if(s[i]==' '){
                i++;
                continue;
            }
            //if '(', just push it
            if(s[i]=='('){
                ops.push(s[i]);
                i++;
            }
            else if( s[i]=='+'|| s[i]=='-' || s[i]=='*' || s[i]=='/'){
                //precedence >= same order should calculate from left to right
                while(!ops.empty() && precedence(ops.top())>=precedence(s[i])){
                    postorder.push_back(string(1,ops.top()));
                    ops.pop();
                }
                ops.push(s[i]);
                i++;
            }
            else if(s[i]==')'){
                while(!ops.empty() && ops.top()!='('){
                    postorder.push_back(string(1,ops.top()));
                    ops.pop();
                }
                ops.pop();
                i++;
            }
            else{
                int st = i;
                while(isdigit(s[i])){
                    i++;
                }
                postorder.push_back(s.substr(st, i-st));
            }
        }
        while(!ops.empty() && ops.top()!='('){
            postorder.push_back(string(1, ops.top()));
            ops.pop();
        }
        return calculatepost(postorder);
    }
    int calculatepost(vector<string> &postorder){
        stack<int> operants;
        for(int i= 0; i<postorder.size(); i++){
            if(isdigit(postorder[i][0])){
                operants.push(stoi(postorder[i]));
            }
            else{
                int n2= operants.top();
                operants.pop();
                int n1 = operants.top();
                operants.pop();
                switch(postorder[i][0]){
                    case '+': n1 += n2; break;
                    case '-': n1 -= n2; break;
                }
                operants.push(n1);
            }
        }
        return operants.top();
    }
    int precedence(char c){
        switch(c){
            case '(':return 0;
            case '+':
            case '-': return 1;
            case '*':
            case '/':return 2;
        }
        return 0;
    }
};
