class Solution {
public:
    string convertToTitle(int n) {
        string ret = "";
        int a = 0, b = 0;
        while(n>0){
            b = n%26;
            if(b) ret.push_back('A'+b-1);
            else ret.push_back('Z');
            n /= 26;
            if(!b) n -= 1;
        }
        int i = 0, j = ret.size()-1;
        while(i<j){
            swap(ret[i],ret[j]);
            i++;
            j--;
        }
        return ret;
    }
};
