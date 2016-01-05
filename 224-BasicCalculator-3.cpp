class Solution {
public:
    int calculate(string s) {
        if(!s.size()) return 0;
        stack<int> ops;
        ops.push(1);
        int i = 0;
        int sign = 1;
        int sum = 0;
        while(i<s.size()){
            if(s[i]==' '){
                i++;
                continue;
            }
            if(isdigit(s[i])){
                int st = i;
                while(isdigit(s[i])){
                    i++;
                }
                int num = stoi(s.substr(st, i-st));
                sum += sign*ops.top()*num;
            }
            else{
                switch(s[i]){
                    case '(': ops.push(sign*ops.top()); sign = 1; break;
                    case '+': sign = 1;break;
                    case '-': sign = -1; break;
                    case ')': ops.pop(); sign = 1; break;
                }
                i++;
            }
        }
        return sum;
    }
};
