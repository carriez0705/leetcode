class Solution {
public:
    int calculate(string s) {
        if(!s.size()) return 0;
        stack<char> op;
        stack<int> nums;
        s.insert(0,1,'(');
        s.push_back(')');
        int i = 0;
        while(i<s.size()){
            if(s[i]==' '){
                i++;
                continue;
            }
            if(s[i]=='(' || s[i]=='+' || s[i]=='-'){
                op.push(s[i]);
                i++;
            }
            else if(s[i]==')'){
                int sum = 0;
                while(op.top()!='('){
                    char oper = op.top();
                    op.pop();
                    int num = nums.top();
                    nums.pop();
                    switch(oper){
                        case '+':sum += num; break;
                        case '-':sum -= num; break;
                    }
                }
                op.pop();
                sum += nums.top();
                nums.pop();
                nums.push(sum);
                i++;
            }
            else{
                int st = i;
                while(i<s.size() && s[i]>='0' && s[i]<='9'){
                    i++;
                }
                int num = stoi(s.substr(st, i-st));
                nums.push(num);
            }
        }
        return nums.top();
    }
};
