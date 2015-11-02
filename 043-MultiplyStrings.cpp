class Solution {
    vector<string> muls;
    int maxlen;
    void mul(string &num1, char m, int zeros){
        string s = "";
        if(m=='0'){
            muls.push_back("0");
            maxlen = max(maxlen, 1);
            return;
        }
        int mm = m-'0';
        while(zeros>0){
            s.push_back('0');
            zeros--;
        }
        int inc = 0;
        for(int i = num1.size()-1; i>=0; i--){
            int ans = (num1[i]-'0')*mm+inc;
            int a = ans/10;
            int b = ans%10;
            s.push_back(b+'0');
            inc = a;
        }
        if(inc)
            s.push_back(inc+'0');
        int i = 0, j = s.size()-1;
        /*
        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        */
        muls.push_back(s);
        maxlen = max(maxlen, (int)s.size());
    }
    void add(string &result){
        int n = muls.size();
        int inc = 0;
        for(int i = 0; i<maxlen; i++){
            int sum = 0;
            for(int j = 0; j<n; j++){
                if(i<muls[j].size()){
                    sum += muls[j][i]-'0';
                }
            }
            sum += inc;
            int a = sum/10;
            int b = sum%10;
            result.push_back(b+'0');
            inc = a;
        }
        while(inc){
            int b = inc%10;
            inc /= 10;
            result.push_back(b+'0');
        }
        int i = 0, j=result.size()-1;
        while(i<j){
            swap(result[i], result[j]);
            i++;
            j--;
        }
    }
public:
    string multiply(string num1, string num2) {
        if(num1.size()<num2.size()) return multiply(num2, num1);
        if(!num2.size()) return "";
        int n2 = num2.size();
        muls.clear();
        maxlen = 0;
        for(int i = 0; i<num2.size(); i++){
            mul(num1, num2[i], n2-i-1);
        }
        string result = "";
        add(result);
        return result;
    }
};
