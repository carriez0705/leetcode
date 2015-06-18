class Stack {
    queue<int> q1;
    queue<int> q2;
    bool q1on=true;
public:
    
    // Push element x onto stack.
    void push(int x) {
        if(q1on)
            q1.push(x);
        else
            q2.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
       
        if(q1on){
            int s = q1.size();
            for(int i = 0;i<s-1; i++){
                int n = q1.front();
                q1.pop();
                q2.push(n);
            }
            
            q1.pop();
            q1on = false;
        }
        else{
            int s = q2.size();
            for(int i = 0;i<s-1; i++){
                int n = q2.front();
                q2.pop();
                q1.push(n);
            }
           
            q2.pop();
            q1on = true;
        }
        
    }

    // Get the top element.
    int top() {
        int top = 0;
        if(q1on){
            int s = q1.size();
            for(int i = 0;i<s; i++){
                top = q1.front();
                q1.pop();
                q2.push(top);
            }
            q1on = false;
        }
        else{
            int s = q2.size();
            for(int i = 0;i<s; i++){
                top = q2.front();
                q2.pop();
                q1.push(top);
            }
            q1on = true;
        }
        return top;
    }

    // Return whether the stack is empty.
    bool empty() {
        if(q1on){
            return q1.empty();
        }
        else
            return q2.empty();
    }
};
