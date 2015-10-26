class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0, right = height.size()-1;
        while(left<right){
            int minh = 0;
            int width = right-left;
            if(height[left]<height[right]){
                minh= height[left];
                left++;
            }
            else{
                minh = height[right];
                right--;
            }
            maxArea = max(maxArea, minh*width);
        }
        return maxArea;
    }
};
