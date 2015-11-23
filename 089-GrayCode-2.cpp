class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> vec;
        vec.push_back(0);
        for(int i = 0; i<n; i++)
            for(int j = vec.size()-1; j>=0; j--)
                vec.push_back(pow(2,i)+vec[j]);
        return vec;
    }
};

//
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> vec(pow(2,n), 0);
        for(int t = 1; t<vec.size(); t++){
            int lastAge = t-1;
            for(int i = 0; i<n; i++){
                int age = t>>i;
                int lastBit = (vec[t-1]&(1<<i))>>i;
                if(age==(lastAge>>i) || age%2==0){
                    vec[t] |= lastBit<<i;
                }
                else{
                    vec[t] |= (!lastBit)<<i;
                }
            }
        }
        return vec;
    }
};
