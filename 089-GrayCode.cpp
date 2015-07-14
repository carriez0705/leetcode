class Solution {
public:
    void helper(int i,stack<int> &left, stack<int> &right, vector<int> &result, bool &onleft){
        vector<int> temp, rvec;
        while(!left.empty()){
            int t = left.top();
            temp.push_back(t);
            t += pow(2,i);
            left.pop();
            rvec.push_back(t);
            result.push_back(t);
        }
        for(int i = 0; i<temp.size(); i++)
            rvec.insert(rvec.begin(), temp[i]);
        for(int i = 0; i<rvec.size();i++)
            right.push(rvec[i]);
        onleft = !onleft;
    }
    vector<int> grayCode(int n) {
        stack<int> left, right;
        vector<int> result;
        
        left.push(0);
        left.push(1);
        bool onleft = true;
        result.push_back(0);
        if(!n) return result;//if n==0, return 0
        result.push_back(1);
        int i = 1;
        while(i<n){
            if(onleft)
                helper(i,left, right, result, onleft);
            else
                helper(i,right, left, result, onleft);
            i++;
        }
        return result;
    }
};
