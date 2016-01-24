class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
       ostringstream oss;
       for(int i = 0; i<strs.size(); i++){
           oss<<setw(4)<<setfill('0')<<strs[i].size();
           oss<<strs[i];
       }
       return oss.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int i = 0;
        vector<string> strs;
        while(i<s.size()){
            int n = stoi(s.substr(i,4));
            if(i+4+n>s.size()) break;
            string str = s.substr(i+4, n);
            strs.push_back(str);
            i += 4+n;
        }
        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
