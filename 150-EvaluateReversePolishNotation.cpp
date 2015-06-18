class Solution {
public:
    int toint(const string &s){
        bool neg = false;
        int m = 0;
        int i = 0;
        //negtive number
        if(s[0]=='-'){
            neg=true;
            i = 1;
        }
        for(; i<s.size(); i++){
            int a = s[i]-'0';
            m = m*10+a;
        }
        return neg?(0-m):m;
    }
    int evalRPN(vector<string>& tokens) {
        map<string,int> mmap;
        mmap["+"] = 1;
        mmap["-"] = 2;
        mmap["*"] = 3;
        mmap["/"] = 4;
        stack<int> st;
        
        for(int i = 0; i<tokens.size(); i++){
            string s = tokens[i];
           
            if(mmap.find(s)!=mmap.end()&&st.size()>1){
                int sum = 0;
                //oder of numbers
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                switch(mmap[s]){
                    case 1: sum = a+b; break;
                    case 2: sum = a-b; break;
                    case 3: sum = a*b; break;
                    case 4: sum = a/b; break;
                }
                st.push(sum);
            }
            else{
                st.push(toint(s));
            }
        }
        return st.top();
    }
};
