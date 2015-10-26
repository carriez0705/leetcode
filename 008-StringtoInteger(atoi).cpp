class Solution {
    int overflow(int num, int p, bool neg){
        int a1 = INT_MAX/10;
        int b1 = INT_MAX%10;
        if(num>a1 || (!neg && num==a1 &&p>b1) || (neg && num==a1 &&p>b1+1))
            return 0;
        else if(neg && num==a1 && p==b1+1)
            return -1;
        else
            return 1;
    }
public:
    int myAtoi(string str) {
        int n = str.size();
        if(!n) return 0;
        int start = 0;
        bool neg = false;
        while(str[start]==' ')
            start++;
        if(str[start]<'0'||str[start]>'9'){
            if(str[start]=='-')
                neg = true;
            else if(str[start]!='+')
                return 0;
            start += 1;
        }
        int num = 0;
        int count = 0;
        int i = start;
        for(; i<str.size() && count<10; i++){
            //if(str[i]==' ')
            //    continue;
            if(str[i]<'0'||str[i]>'9')
                return neg?-num:num;
            int p = str[i]-'0';
            if(count==9){
                int status = overflow(num, p, neg);
                if(!status) return neg?INT_MIN:INT_MAX;
                else if(status ==-1 ) return INT_MIN;
            }
            num = num*10 + p;
            count+=1;
        }
        if(i<str.size()&&str[i]>='0' && str[i]<='9') return neg?INT_MIN:INT_MAX;
        return neg? -num: num;
    }
};
