class Solution {
    string itoa(int n){
        if(!n) return "0";
        string s = "";
        while(n>0){
            int b = n%10;
            n /= 10;
            s.push_back('0'+b);
        }
        int i = 0, j = s.size()-1;
        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        vector<int> num1(10, 0);
        vector<int> num2(10, 0);
        int bull = 0;
        int cow = 0;
        for(int i = 0; i<secret.size(); i++){
            if(secret[i]==guess[i])
                bull++;
            else{
                num1[secret[i]-'0']++;
                num2[guess[i]-'0']++;
            }
        }
        for(int i = 0; i<10; i++){
            cow += min(num1[i], num2[i]);
        }
        string result = "";
        result.append(itoa(bull));
        result.push_back('A');
        result.append(itoa(cow));
        result.push_back('B');
        return result;
    }
};
