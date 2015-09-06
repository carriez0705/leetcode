class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(!citations.size()) return 0;
        vector<int> cnt(citations.size()+1,0);
        for(int i = 0; i<citations.size();i++){
            if(citations[i]<=citations.size())
                cnt[citations[i]] += 1;
        }
        int result = 0;
        int sum = 0;
        for(int i = 0; i<cnt.size()-1; i++){
            sum += cnt[i];
            if(citations.size()-sum>=i+1) result = i+1;
        }
        return result;
    }
};
