class Solution {
    void itos(int n, string &result){
        while(n){
            int b = n%10;
            result.push_back('0'+b);
            n /= 10;
        }
        int i = 0, j = result.size()-1;
        while(i<j){
            swap(result[i], result[j]);
            i++;
            j--;
        }
    }
    void say(string &s){
        int i = 0;
        string result = "";
        while(i<s.size()-1){
            int count = 1;
            while(s[i+1]==s[i]){
                i++;
                count++;
            }
            string c = "";
            itos(count, c);
            result.append(c);
            result.push_back(s[i]);
            i++;
        }
        if(i<s.size()){
            result.push_back('1');
            result.push_back(s[i]);
        }
        s = result;
    }
public:
    string countAndSay(int n) {
        string result = "";
        itos(1, result);
        for(int i = 1; i<n; i++){
            say(result);
        }
        return result;
    }
};
