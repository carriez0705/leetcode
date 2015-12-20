class NumArray {
    vector<int> segmentvec;
    vector<int> num;
    int n;
    int getmid(int ss, int se){
        return ss + ((se-ss)>>1);
    }
    int construct(int ss, int se, int id){
        if(ss==se){
            segmentvec[id] = num[ss];
        }else{
            int mid = getmid(ss, se);
            segmentvec[id] = construct(ss, mid, 2*id+1) + construct(mid+1, se, 2*id+2);
        }
        return segmentvec[id];
    }
    int getsum(int qs, int qe, int ss, int se, int id){
        if(qs<=ss && qe>=se){
            return segmentvec[id];
        }
        else if(ss>qe || se<qs){
            return 0;
        }
        else{
            int mid = getmid(ss, se);
            return getsum(qs, qe, ss, mid, 2*id+1) + getsum(qs, qe, mid+1, se, 2*id+2);
        }
    }
    void updateHelper(int q, int diff, int ss, int se, int id){
        if(ss>q || se<q) return;
        segmentvec[id] += diff;
        if(ss==se) return;
        int mid = getmid(ss, se);
        updateHelper(q, diff, ss, mid, 2*id+1);
        updateHelper(q, diff, mid+1, se, 2*id+2);
    }
public:
    NumArray(vector<int> &nums) {
        segmentvec.clear();
        num.clear();
        n = nums.size();
        if(n){
            int h = ceil(log2(n));
            int maxn = pow(2, h+1) -1;
            segmentvec.resize(maxn);
            num = nums;
            construct(0, nums.size()-1, 0);
        }
    }

    void update(int i, int val) {
        if(i<0 || i>=n || num[i]==val) return;
        int diff = val-num[i];
        num[i] = val;
        updateHelper(i, diff, 0, n-1, 0);
    }

    int sumRange(int i, int j) {
        return getsum(i, j, 0, n-1, 0);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
