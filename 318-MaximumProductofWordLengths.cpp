class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if(!n) return 0;
        vector<int> wordbit(n, 0);
        for(int i = 0; i<n; i++){
            int b = 0;
            for(int j = 0; j<words[i].size(); j++){
                b |= (1<<words[i][j]-'a');
            }
            wordbit[i] = b;
        }
        int maxlen = 0;
        for(int i = 0; i<n; i++)
            for(int j = i+1; j<n; j++){
                if(!(wordbit[i]&wordbit[j])){
                    maxlen = max(maxlen, (int)(words[i].size()*words[j].size()));
                }
            }
        return maxlen;
    }
};
