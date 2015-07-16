class Solution {
public:
    void reverseWords(string &s) {
        //char sym[] = {'.','!'};
        //unordered_set<char> symbol(sym, sym+2);
        int i = 0; 
        while(s[i]==' '){
            s.erase(i,1);
        }
        int j = s.length()-1;
        while(s[j]==' '){
            s.pop_back();
            j--;
        }
        //if(symbol.find(s[j])!=symbol.end())
        //    j--;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        i = 0;
        for(int j= 1;j<=s.length();j++){
            //if(j==s.length() ||s[j]==' ' || (j==s.length()-1 && symbol.find(s[j])!=symbol.end())){
            if(j==s.length() ||s[j]==' '){
                int k = j;
                j--;
                while(i<j){
                    swap(s[i],s[j]);
                    i++;
                    j--;
                }
                j = k;
                while(j<s.length()-1 && s[j+1]==' '){
                    s.erase(j+1,1);
                }
                i = j+1;
            }
        }
    }
};
