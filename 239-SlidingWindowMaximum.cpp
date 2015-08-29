class Solution {
public:
    void indeque(deque<int> &dq, deque<int> &pos, int num, int no, int k){
        if(dq.empty()){
            dq.push_back(num);
            pos.push_back(no);
        }
        else{
            int p = pos.front();
            if(no-p+1>k){
                pos.pop_front();
                dq.pop_front();
            }
            while(!dq.empty()&&dq.back()<=num){
                dq.pop_back();
                pos.pop_back();
            }
            dq.push_back(num);
            pos.push_back(no);
        }
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxvec;
        if(!nums.size()) return maxvec;
        deque<int> dq;
        deque<int> pos;
        for(int i = 0; i<k-1; i++){
            indeque(dq,pos,nums[i],i,k);
        }
        for(int i = k-1; i<nums.size(); i++){
            indeque(dq,pos,nums[i],i,k);
            maxvec.push_back(dq.front());
        }
        return maxvec;
    }
};
