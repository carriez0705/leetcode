class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int area = 0;
        for(int i = 0; i<height.size(); i++){
            while(!st.empty() && height[i]>height[st.top()]){
                int bot = height[st.top()];
                while(!st.empty() && height[st.top()]==bot)
                    st.pop();
                if(!st.empty())
                    area += (min(height[i], height[st.top()])-bot)*(i-st.top()-1);
            }
            st.push(i);
        }
        return area;
    }
};
