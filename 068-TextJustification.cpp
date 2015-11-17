class Solution {
    
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        if(maxWidth==0) return words;
        vector<int> wordLen(n, 0);
        for(int i = 0; i<words.size(); i++){
            wordLen[i] = words[i].size();
        }
        vector<string> ans;
        int i = 0;
        while(i<n){
            int start = i;
            int curLen = 0;
            int num = 0;
            while(i<n && curLen+wordLen[i]<=maxWidth){
                curLen += wordLen[i];
                curLen += 1;
                i++;
                num++;
            }
            curLen -= 1;
            int a = 0, b=0;
            if(i!=n){
                if(num>1 && curLen<maxWidth){
                    b = (maxWidth-curLen)/(num-1);
                    a = (maxWidth-curLen)%(num-1);
                }
            }
            string s = "";
            for(int j = 0; j<num-1; j++){
                s.append(words[start+j]);
                int k = 0;
                while(k<b+1){
                    s.push_back(' ');
                    k++;
                }
                if(j<a){
                    s.push_back(' ');
                }
            }
            s.append(words[i-1]);
            while(s.size()<maxWidth){
                s.push_back(' ');
            }
            ans.push_back(s);
        }
        return ans;
    }
};
