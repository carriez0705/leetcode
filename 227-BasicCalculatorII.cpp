class Solution {
    int ctoi(vector<char> &num){
        int n = 0;
        for(int i = 0; i<num.size(); i++){
            n = n*10+num[i]-'0';
        }
        return n;
    }
    void cal(stack<char> &ops, stack<int> &nums){
        int c = ops.top();
        ops.pop();
        int n2 = nums.top();
        nums.pop();
        if(c=='-'){
            n2 = -n2;
            c = '+';
        }
        int n1 = nums.top();
        nums.pop();
        if(!ops.empty() && ops.top()=='-'){
            n1 = -n1;
            ops.pop();
            ops.push('+');
        }
        switch(c){
            case '+': n1 += n2; break;
            case '-': n1 -= n2; break;
            case '*': n1 *= n2; break;
            case '/': n1 /= n2; break;// zero judge
        }
        nums.push(n1);
    }
public:
    int calculate(string s) {
        unordered_set<char> opset;
        opset.insert('+');
        opset.insert('-');
        opset.insert('*');
        opset.insert('/');
        stack<char> ops;
        stack<int> nums;
        for(int i = 0; i<s.size(); i++){;
            if(s[i]==' ')
                continue;
            else{
                if(opset.find(s[i])!=opset.end()){
                    ops.push(s[i]);
                }
                else{
                    vector<char> num;
                    while(i+1<s.size()&&s[i+1]!=' '&&opset.find(s[i+1])==opset.end()){
                        num.push_back(s[i]);
                        i++;
                    }
                    num.push_back(s[i]);
                    nums.push(ctoi(num));
                    if(!ops.empty() && (ops.top()=='*'||ops.top()=='/')){
                        cal(ops, nums);
                    }
                }
                
            }
        }
        while(!ops.empty()){
            cal(ops,nums);
        }
        return nums.size()==1?nums.top():-1;
    }
};
