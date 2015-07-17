class MinStack {
    vector<int> mystack;
    vector<int> mymin;
public:
    void push(int x) {
        mystack.push_back(x);
        if(!mymin.size() || x<=mymin[mymin.size()-1]){
            mymin.push_back(x);
        }
    }

    void pop() {
        int x = mystack[mystack.size()-1];
        mystack.pop_back();
        if(x==mymin[mymin.size()-1])
            mymin.pop_back();
    }

    int top() {
        return mystack[mystack.size()-1];
    }

    int getMin() {
        return mymin[mymin.size()-1];
    }
};
