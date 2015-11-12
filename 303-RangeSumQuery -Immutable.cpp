class NumArray {
    vector<int> sum;
public:
    NumArray(vector<int> &nums) {
        sum.clear();
        sum.resize(nums.size()+1);
        sum[0] = 0;
        for(int i = 0; i<nums.size(); i++){
            sum[i+1] = sum[i]+nums[i];
        }
    }

    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
