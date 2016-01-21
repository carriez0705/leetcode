struct Entry{
    string val;
    Entry *next;
    Entry(string str):val(str), next(NULL){}
};
class ValidWordAbbr {
    unordered_map<string, Entry*> abb;
    string coding(string str){
        int n = str.size();
        if(n<=2) return str;
        string res(1, str[0]);
        res.append(to_string(n-2));
        res.push_back(str[n-1]);
        return res;
    }
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(int i= 0; i<dictionary.size(); i++){
            string code = coding(dictionary[i]);
            if(abb.find(code)==abb.end()){
                abb[code] = new Entry(dictionary[i]);
            }
            else{
                Entry *n = abb[code];
                if(n->val!=dictionary[i]){
                    abb[code] = new Entry(dictionary[i]);
                    abb[code]->next = n;
                }
            }
        }
    }

    bool isUnique(string word) {
        string code = coding(word);
        if(abb.find(code)==abb.end()) return true;
        Entry *ent = abb[code];
        return ent->val==word && ent->next==NULL;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
