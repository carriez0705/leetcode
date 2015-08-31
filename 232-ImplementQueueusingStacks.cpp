class Queue {
    stack<int> stk1;
    stack<int> stk2;
    void transfer(){
        if(stk2.empty()){
            while(!stk1.empty()){
                int t = stk1.top();
                stk1.pop();
                stk2.push(t);
            }
        }
    }
public:
    Queue(){
        while(!stk1.empty())
            stk1.pop();
        while(!stk2.empty())
            stk2.pop();
    }
    // Push element x to the back of queue.
    void push(int x) {
        stk1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        transfer();
        if(!stk2.empty()) stk2.pop();
        else cout<<"empty"<<endl;
    }

    // Get the front element.
    int peek(void) {
        transfer();
        if(!stk2.empty()) return stk2.top();
        else{
            cout<<"empty"<<endl;
            return -1;
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk1.empty()&&stk2.empty();
    }
};
