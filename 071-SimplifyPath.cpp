class Solution {
public:
    string simplifyPath(string path) {
        string s = "";
        int index = 0;
        int last = -1;
        int i = 0;
        while(i<path.size() && path[i]=='/'){
            i++;
        }
        for(; i<path.size(); i++){
            string temp = "";
            while(i<path.size() && path[i]!='/'){
                temp.push_back(path[i]);
                i++;
            }
            if(temp==".."){
                int k = s.size()-1;
                while(k>0 && s[k]!='/'){
                    s.pop_back();
                    k--;
                }
                if(s.size()) s.pop_back();
            }
            else if(temp!="."){
                s.push_back('/');
                s.append(temp);
            }
            while(i+1<path.size() && path[i+1]=='/')
                i++;
        }
        return s.size()? s : "/";
    }
};
