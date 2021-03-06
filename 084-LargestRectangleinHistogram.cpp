class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int maxarea = 0;
        stack<int> pos;
        vector<int> left(height.size());
        vector<int> right(height.size());
        for(int i = 0; i<height.size(); i++){
            while(!pos.empty() && height[pos.top()]>=height[i]){
                pos.pop();
            }
            if(pos.empty()) left[i] = 0;
            else left[i] = pos.top()+1;
            pos.push(i);
        }
        while(!pos.empty()) pos.pop();
        for(int i = height.size()-1; i>=0; i--){
            while(!pos.empty() && height[pos.top()]>=height[i]){
                pos.pop();
            }
            if(pos.empty()) right[i] = height.size()-1;
            else right[i] = pos.top()-1;
            maxarea = max(maxarea, (right[i]-left[i]+1)*height[i]);
            pos.push(i);
        }
        return maxarea;
    }
};
