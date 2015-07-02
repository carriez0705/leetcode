struct Number{
    int val, pos;
    Number(int x, int y):val(x),pos(y){}
};
class Comp{
public:
    bool operator() (Number &x, Number &y){
        return x.val<y.val;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        vector<int> result;
        vector<Number> numvec;
        for(int k = 0; k<nums.size(); k++){
            numvec.push_back(Number(nums[k],k+1));
        }
        sort(numvec.begin(), numvec.end(), Comp());
        while(i<j){
            int sum = numvec[i].val+numvec[j].val;
            if(sum==target){
                int index1 = min(numvec[i].pos, numvec[j].pos);
                int index2 = max(numvec[i].pos, numvec[j].pos);
                result.push_back(index1);
                result.push_back(index2);
                return result;
            }
            else if(sum>target) j--;
            else i++;
        }
        return result;
    }
};
