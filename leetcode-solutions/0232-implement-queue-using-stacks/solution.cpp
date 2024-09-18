class MyQueue {
public:
    stack<int>s1,s2;

    MyQueue() {
        // not needed
    }
    
    void push(int x) {
        // Step 1: s1->s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        // Step 2: x->s1
        s1.push(x);
        // Step 3: s2->s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int val = s1.top();
        s1.pop();
        return val;
    }
    
    int peek() {
        int val = s1.top();
        return val;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
