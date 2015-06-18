class Solution {
public:
    int str2num(string &str){
        int sum = 0;
        for(int i = 0;i<str.size(); i++){
            int num = str[i]-'0';
            sum = sum*10+num;
        }
        return sum;
    }
    int inner(string &s, int i, int &j){
        int count = 0;
        char op;
        stack<int> st;
        string temp = "";
        while(i!=s.size()){
            if(s[i]==')'){
                int re = st.top();
                st.pop();
                j = i;
                return re;
            }
            if(s[i]==' '){
                ++i;
                continue;
            }
            if(s[i]>='0'&&s[i]<='9'){
                temp.push_back(s[i]);
                if(i==s.size()-1 ||s[i+1]<'0'||s[i+1]>'9'){
                    st.push(str2num(temp));
                    temp.clear();
                    ++count;
                }
            }
            else if(s[i]=='+'||s[i]=='-'){
                op = s[i];
                ++count;
            }
            else if(s[i]=='('){
                int in = inner(s,i+1,j);
                st.push(in);
                i = j;
                ++count;
            }
            if(count==3){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int sum = 0;
                switch(op){
                    case '+': sum = a+b; break;
                    case '-': sum = a-b; break;
                }
                st.push(sum);
                count=1;
            }
            ++i;
        }
        return st.top();
    }
    int calculate(string s) {
        if(!s.size()) return 0;
        int j = 0;
        return inner(s,0,j);
    }
};
