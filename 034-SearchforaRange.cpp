class Solution {
    int searchEdge(vector<int> &nums, int target, int begin, int end, bool frontEdge){
        if(begin>end)
            return -1;
        int mid = (begin+end)>>1;
        if(nums[mid]==target){
            if(frontEdge){
                if(mid==0 || nums[mid-1]!=target)
                    return mid;
                else
                    return searchEdge(nums, target, begin, mid-1, frontEdge);
            }
            else{
                if(mid==nums.size()-1 || nums[mid+1]!=target)
                    return mid;
                else
                    return searchEdge(nums, target, mid+1, end, frontEdge);
            }
        }
        else if(nums[mid]<target)
            return searchEdge(nums, target, mid+1, end, frontEdge);
        else
            return searchEdge(nums, target, begin, mid-1, frontEdge);
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int begin = searchEdge(nums, target, 0, nums.size()-1, true);
        result.push_back(begin);
        if(begin!=-1){
            int end = searchEdge(nums, target, 0, nums.size()-1, false);
            result.push_back(end);
        }
        else
            result.push_back(-1);
        return result;
    }
};
