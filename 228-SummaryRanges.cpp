class Solution {
public:
    string convert(int num){
        if(num==0) return "0";
        if(num==INT_MIN) return "-2147483648";
        string r = "";
        int i = 0;
        if(num<0){
            r.push_back('-');
            num = abs(num);
            i = 1;
        }
        while(num){
            r.push_back('0'+num%10);
            num /= 10;
        }
        int j = r.size()-1;
        while(i<j){
            swap(r[i],r[j]);
            i++;
            j--;
        }
        return r;
    }
    string print(vector<int> &nums, int low, int high){
        string result = "";
        if(low==high)
            result += convert(nums[low]);
        else{
            result += convert(nums[low]);
            result += "->";
            result += convert(nums[high]);
        }
        return result;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int low = 0;
        for(int i = 0;i<nums.size();i++){
            if(i==nums.size()-1||nums[i+1]!=nums[i]+1){
                string r = print(nums, low, i);
                low = i+1;
                result.push_back(r);
            }
        }
        return result;
    }
};
