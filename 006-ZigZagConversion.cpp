class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1) return s;
        string result = "";
        int index = 0;
        for(int i = 0; i<numRows; i++){
            index = i;
            if(i==0 || i==numRows-1){
                while(index<s.size()){
                    result.push_back(s[index]);
                    index += 2*(numRows-1);
                }
            }
            else{
                bool up = true;
                while(index<s.size()){
                    result.push_back(s[index]);
                    if(up)
                        index += 2*(numRows-i-1);
                    else
                        index += 2*i;
                    up = !up;
                }
            }
        }
        return result;
    }
};
