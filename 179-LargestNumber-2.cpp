bool compare(string s1, string s2){
        s1.append(s2);
        s2.append(s1);
        return s1.compare(s2)>=0;
    }
class Solution {
public:
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
    
    
    string largestNumber(vector<int>& nums) {
        vector<string> strvec(nums.size(), "");
        for(int i = 0; i<nums.size(); i++)
            strvec[i] = toString(nums[i]);
        sort(strvec.begin(), strvec.end(), compare);
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
