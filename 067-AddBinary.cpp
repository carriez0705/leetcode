class Solution {
    int add(int a, int b, int &carrie){
        int num = a+b+carrie;
        if(num>1){
            carrie = 1;
            num -= 2;
        }
        else
            carrie = 0;
        return num;
    }
public:
    string addBinary(string a, string b) {
        if(!a.size()) return b;
        if(!b.size()) return a;
        int i = a.size()-1;
        int j = b.size()-1;
        string s = "";
        int carrie = 0;
        while(i>=0 && j>=0){
            int num = add(a[i]-'0', b[j]-'0', carrie);
            s.push_back('0'+num);
            i--;
            j--;
        }
        while(i>=0){
            int num = add(a[i]-'0', 0, carrie);
            s.push_back(num+'0');
            i--;
        }
        while(j>=0){
            int num = add(0,b[j]-'0', carrie);
            s.push_back(num+'0');
            j--;
        }
        if(carrie)
            s.push_back('1');
        i = 0;
        j = s.size()-1;
        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};
