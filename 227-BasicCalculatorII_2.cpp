class Solution {
public:
    int calculate(string s) {
        int tot = 0, prev = 0;
        int i = 0;
        char op = '+';
        while(i<s.size()){
            while(i<s.size() && s[i]==' ')
                i++;
            if(i<s.size() && !isdigit(s[i])){
                op = s[i];
                i++;
                while(i<s.size() && s[i]==' ')
                    i++;
            }
            if(i<s.size() && isdigit(s[i])){
                int st = i;
                while(i<s.size() && isdigit(s[i])){
                    i++;
                }
                int num = stoi(s.substr(st, i-st));
                switch(op){
                    case '+': tot += prev; prev = num; break;
                    case '-': tot += prev; prev = -num; break;
                    case '*': prev *= num; break;
                    case '/': prev /= num; break;
                }
            }
        }
        return tot+prev;
    }
};
