//1. optimization - deque + hashmap to store iterator (constant time access and insert and delete)

class LRUCache{
    list<pair<int, int> > nodelist;
    unordered_map<int, list<pair<int, int> >::iterator> keymap;
    int cap;
public:
    LRUCache(int capacity):cap(capacity){
       nodelist.clear();
       keymap.clear();
    }
    ~LRUCache(){
       nodelist.clear();
       keymap.clear();
    }
    int get(int key) {
        if(keymap.find(key)==keymap.end())
            return -1;
        nodelist.splice(nodelist.begin(), nodelist, keymap[key]);
        keymap[key] = nodelist.begin();
        return (*nodelist.begin()).second;
    }
    
    void set(int key, int value) {
        if(keymap.find(key)==keymap.end()){
            if(nodelist.size()==cap){
                int rekey = (*nodelist.rbegin()).first;
                keymap.erase(rekey);
                nodelist.pop_back();
            }
            nodelist.emplace_front(key,value);
            keymap[key] = nodelist.begin();
        }
        else{
            nodelist.splice(nodelist.begin(), nodelist, keymap[key]);
            (*nodelist.begin()).second = value;
            keymap[key] = nodelist.begin();
        }
    
    }
};

//2. version 1- straight forward intuition: linked list
struct Node{
    int key;
    int value;
    Node *next;
    Node(int k, int v):key(k),value(v),next(NULL){}
};
class LRUCache{
    Node *head;
    unordered_set<int> keyset;
    int length;
    int cap;
    int findNode(int key){
        Node *n = head->next;
        Node *prev = head;
        while(n && n->key!=key){
                prev = n;
                n = n->next;
        }
        int v = n->value;
        prev->next = n->next;
        n->next = head->next;
        head->next= n;
        return v;
    }
    int removeTail(){
        Node *n =head->next;
        Node *prev = head;
        if(!n) return -1;
        while(n->next){
            prev = n;
            n = n->next;
        }
        int k = n->key;
        prev->next = NULL;
        return k;
    }
    void insertNode(int k, int v){
        Node *n = new Node(k,v);
        n->next = head->next;
        head->next = n;
    }
    void deleteNode(Node *node){
        while(node){
            Node *p = node;
            node = node->next;
            delete p;
        }
    }
public:
    LRUCache(int capacity): cap(capacity),length(0){
        head = new Node(-1,-1);
        keyset.clear();
    }
    ~LRUCache(){
        deleteNode(head);
    }
    int get(int key) {
        if(keyset.find(key)==keyset.end())
            return -1;
        else
            return findNode(key);
    }
    
    void set(int key, int value) {
        if(keyset.find(key)!=keyset.end()){
            int v = findNode(key);
            if(v!=value)
                head->next->value = value;
        }
        else{
            length += 1;
            if(length>cap){
                int remkey = removeTail();
                keyset.erase(remkey);
                length = cap;
            }
            insertNode(key, value);
            keyset.insert(key);
        }
    }
};

//3. version 2- hardward acceleration - bitmap
#define MAXCAP 2048


class LRUCache{
    vector<bitset<MAXCAP> > bitvec;
    int length;
    int cap;
    unordered_map<int, pair<int,int> > keymap;
    unordered_map<int, int> ivt;
    std::set<int> hole;
    void reach(int pos){
        bitvec[pos].set();
        for(int i = 0; i<bitvec.size(); i++){
            bitvec[i].reset(MAXCAP-pos-1);
        }
    }
    int oldest(){
        int old = MAXCAP+1;
        int pos = MAXCAP;
        for(int i = 0; i<cap; i++){
            if(bitvec[i].count()<old){
                old = bitvec[i].count();
                pos = i;
            }
        }
        return pos;
    }
public:
    LRUCache(int capacity): cap(capacity),length(0){
       for(int i = 0; i<cap; i++)
            hole.insert(i);
       bitvec.clear();
       keymap.clear();
       bitvec.resize(cap);
    }
    ~LRUCache(){
        hole.clear();
        bitvec.clear();
        keymap.clear();
    }
    int get(int key) {
        if(keymap.find(key)==keymap.end())
            return -1;
        int v = keymap[key].first;
        reach(keymap[key].second);
        return v;
    }
    
    void set(int key, int value) {
        if(keymap.find(key)!=keymap.end()){
            if(keymap[key].first!=value)
                keymap[key].first = value;
            reach(keymap[key].second);
        }
        else{
            length += 1;
            if(length>cap){
                int pos = oldest();
                keymap.erase(ivt[pos]);
                ivt.erase(pos);
                hole.insert(pos);
                length = cap;
            }
            int newpos = *hole.begin();
            keymap[key] = pair<int, int>(value,newpos);
            ivt[newpos] = key;
            reach(newpos);
        }
    }
};

//4: version 3- aging algorithm
