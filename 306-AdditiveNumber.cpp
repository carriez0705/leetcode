class Solution {
    bool sequal(string &s1, string &s2, string &num, int begin, int &next){
        int i = s1.size()-1;
        int j = s2.size()-1;
        int carrier = 0;
        string s3 = "";
        while(i>=0 && j>=0){
            int n1 = s1[i]-'0';
            int n2 = s2[j]-'0';
            int n3 = n1+n2+carrier;
            carrier = n3/10;
            n3 = n3%10;
            s3.push_back(n3+'0');
            i--;
            j--;
        }
        while(i>=0){
            int n1 = s1[i]-'0';
            int n3 = n1+carrier;
            carrier = n3/10;
            n3 = n3%10;
            s3.push_back(n3+'0');
            i--;
        }
        while(j>=0){
            int n2 = s2[j]-'0';
            int n3 = n2+carrier;
            carrier = n3/10;
            n3 = n3%10;
            s3.push_back(n3+'0');
            j--;
        }
        if(carrier){
            s3.push_back(carrier+'0');
        }
        int n3 = s3.size();
        for(int k = 0; k<s3.size(); k++){
            if(begin+k>=num.size() || s3[n3-k-1]!=num[begin+k])
                return false;
        }
        next = begin+s3.size();
        return true;
    }
    bool isAdditive(string &num, int begin, string &s1, string &s2){
        if(begin==num.size()) return true;
        int n1 = s2.size(), n2 = s2.size(), n = num.size();
        if(n-begin<max(n1,n2)) return false;
        int next = begin;
        if(sequal(s1, s2, num, begin, next)){
            string s3 = num.substr(begin, next-begin);
            return isAdditive(num, next, s2, s3);
        }
        else
            return false;
    }
public:
    bool isAdditiveNumber(string num) {
        if(num.size()<3) return false;
        int n = num.size();
        for(int len1 = 1; len1<=n/2; len1++){
            for(int len2 = 1; len2<=(n-len1)/2; len2++){
                if((num[len1]=='0' && len2!=1) || num[len1+len2]=='0')
                    continue;
                string s1 = num.substr(0,len1);
                string s2 = num.substr(len1, len2);
                if(len1+len2<num.size() && isAdditive(num, len1+len2, s1, s2))
                    return true;
            }
        }
        return false;
    }
};
