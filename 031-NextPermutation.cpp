class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return;
        //find the last ascending order pair
        int low = -1;
        int high = -1;
        stack<int> st;
        st.push(n-1);
        for(int i = n-2; i>=0; i--){
            if(nums[i]==nums[st.top()])
                continue;
            else if(nums[i]>nums[st.top()])
                st.push(i);
            else{
                low = i;
                while(!st.empty() && nums[i]<nums[st.top()]){
                    high = st.top();
                    st.pop();
                }
                break;
            }
        }
       
        if(low!=-1)
            swap(nums[low], nums[high]);
        if(low+1<nums.size()-1)
            sort(nums.begin()+low+1, nums.end());
    }
};
