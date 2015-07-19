class Solution {
public:
    string toString(long long n){ //long long
        string ret="";
        while(n>0){
            ret.push_back(n%10+'0');
            n /= 10;
        }
        int i = 0, j= ret.size()-1;
        while(i<j){
            swap(ret[i], ret[j]);
            i++;
            j--;
        }
        return ret;
    }
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator || !denominator) return "0";
        bool neg = true; //consider negtive situation
        if((numerator>0&&denominator>0) || (numerator<0&&denominator<0)) neg = false;
        long long num = abs((long long)numerator); //be careful about INT_MIN
        long long denom = abs((long long)denominator);
        long long a = 0, b = 0;
        string ret = neg? "-" : "";
        if(num<denom){
            ret.append("0.");
        }
        else{
            ret.append(toString(num/denom));
            num %= denom;
            if(num) ret.push_back('.');
        }
        vector<int> vec;
        unordered_map<int,int> umap;
        int loop = -1;
        int count = 0;
        while(num){
            umap[num] = count;
            num *= 10;
            a = num/denom;
            vec.push_back(a);
            count++;
            num %= denom;
            if(umap.find(num)!=umap.end()){
                loop = umap[num]; break;
            }
        }
        if(loop!=-1){
            int i = 0;
            while(i<loop)
                ret.push_back(vec[i++]+'0');
            ret.push_back('(');
            while(i<vec.size()){
                ret.push_back(vec[i++]+'0');
            }
            ret.push_back(')');
        }
        else{
            for(int i = 0; i<vec.size(); i++)
                ret.push_back(vec[i]+'0'); 
        }
        return ret;
    }
};
