class Solution {
    int find(int b, vector<bool> &used){
        int i = 0, count = 0;
        while(count<b){
            while(used[i])
                i++;
            i++;
            count++;
        }
        used[i-1] = true;
        return i;
    }
    
public:
    string getPermutation(int n, int k) {
        if(n==1) return "1";
        //vector<bool> used(n, false);
        set<int> available;
        for(int i = 1; i<=n; i++){
            available.insert(i);
        }
        vector<int> factorial(n-1, 1);
        for(int i = 1; i<n-1; i++){
            factorial[i] = factorial[i-1]*(i+1);
        }
        int order = n-2;
        string ans = "";
        k = k-1;
        while(ans.size()<n){
            int b = order>=0? k/factorial[order] : 0;
            k -= b*factorial[order];
            order--;
            int num = find(b+1, used);
            ans.push_back(num+'0');
        }
        return ans;
    }
};
