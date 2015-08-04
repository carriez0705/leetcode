class Solution {
public:
    void convert(string &s, int n, unsigned int &ret){
        char c = s[n];
        switch(c){
                case 'A': ret = (ret<<2)|0; break;
                case 'C': ret = (ret<<2)|1; break;
                case 'G': ret = (ret<<2)|2; break;
                case 'T': ret = (ret<<2)|3; break;
            }
        ret = ret&0xFFFFF;
        }

    string toString(const unsigned int &num){
        string str;
        int i = 0;
        int mask = (1<<19)+(1<<18);
        unsigned int n = num;
        while(i<10){
            int j = (n&mask)>>18;
            switch(j){
                case 0: str.push_back('A');break;
                case 1: str.push_back('C');break;
                case 2: str.push_back('G'); break;
                case 3: str.push_back('T'); break;
            }
             i += 1;
             n = n<<2;
        }
        return str;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<unsigned int, bool> smap;
        vector<string> ret;
        if(s.size()<=10) return ret;
        unsigned int uint = 0;
        for(int i = 0; i<10; i++){
            convert(s,i,uint);
        }
        smap[uint] = false;
        for(int i = 1; i<=s.size()-10; i++){
            convert(s, i+9, uint);
            if(smap.find(uint)==smap.end())
                smap[uint] = false;
            else
                smap[uint] = true;
        }
        for(auto iter = smap.begin(); iter!= smap.end(); iter++){
            if(iter->second)
                ret.push_back(toString(iter->first));
        }
        return ret;
    }
};
