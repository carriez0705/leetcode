class Solution {
public:
    int nthUglyNumber(int n) {
        if(!n) return 0;
        vector<int> vec(1,1);
        int p2=0,p3=0,p5=0;
        while(vec.size()<n){
            int min_=0;
            int *i = &p2;
            if(vec[p2]*2<vec[p3]*3){
                min_=vec[p2]*2;
                i=&p2;
            }
            else{
                min_ = vec[p3]*3;
                i = &p3;
            }
            if(min_>vec[p5]*5){
                min_= vec[p5]*5;
                i = &p5;
            }
            if(min_!=vec[vec.size()-1]) vec.push_back(min_);
            (*i)++;
        }
        return vec[n-1];
    }
};
