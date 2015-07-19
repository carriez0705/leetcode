class Solution {
public:
    void mst(vector<string> &nums, int lo, int hi, int p){
        if(lo>=hi) return;
        vector<int> aux(10,0);
        vector<string> vec(nums);
        for(int i = lo; i<=hi; i++){
            char temp = p<nums[i].size() ? nums[i][p] : nums[i][0];
            temp -= '0';
            aux[temp] += 1;
        }
        for(int i = 0; i<aux.size()-1; i++){
            aux[i+1] += aux[i];
        }
        for(int i = hi; i>=lo; i--){
            char temp = p<vec[i].size() ? vec[i][p] : nums[i][0];
            temp -= '0';
            nums[hi+1-aux[temp]] = vec[i];
            aux[temp] -= 1;
        }
        int start = lo, end = lo;
        for(int i = lo; i<=hi; i++){
            if(nums[i].length()==p){
                start = i+1;
            }
            if(i==hi || i<hi && (nums[i+1].length()==p || nums[i+1][p]!=nums[i][p])){
                end = i;
                mst(nums, start, end, p+1);
                start = i+1;
            }
        }
    }
    string toString(int n){
        if(!n) return "0";  //edge case
        string ret = "";
        while(n){
            ret.push_back(n%10+'0');
            n /= 10;
        }
        int i = 0, j = ret.size()-1;
        while(i<j){
            swap(ret[i], ret[j]);
            i++;
            j--;
        }
        return ret;
    }
    bool compare(string s1, string s2){
        s1.append(s2);
        s2.append(s1);
        return s1.compare(s2)>=0;
    }
    void check(vector<string> &nums){
        for(int i= 0; i<nums.size()-1; i++){
            if(nums[i+1].length()!=nums[i].length()){
                bool c =compare(nums[i], nums[i+1]);
                if(!c) swap(nums[i], nums[i+1]);
            }
        }
    }
    string largestNumber(vector<int>& nums) {
        vector<string> strvec(nums.size(), "");
        for(int i = 0; i<nums.size(); i++)
            strvec[i] = toString(nums[i]);
        mst(strvec, 0, strvec.size()-1, 0);
        check(strvec);
        string ret = "";
        for(int i = 0; i<strvec.size(); i++){
            ret.append(strvec[i]);
        }
        while(ret.size()>1 && ret[0]=='0'){
            ret.pop_back();
        }
        return ret;
    }
};
