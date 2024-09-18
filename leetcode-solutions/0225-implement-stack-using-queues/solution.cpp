class MyStack {
public:
    queue<int> q; // Define a queue to simulate stack behavior

    MyStack() {
        // Constructor: no explicit initialization required.
        // The stack will be simulated using a single queue.
    }
    
    void push(int x) {
        // Add the new element 'x' to the queue.
        q.push(x);

        // Rotate the queue to maintain the stack order.
        // Move all elements, except the newly added one, to the back of the queue.
        for(int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front()); // Move the front element to the back.
            q.pop();           // Remove the front element.
        }
    }
    
    int pop() {
        // The front of the queue is the "top" of the stack due to the previous push logic.
        int val = q.front(); // Store the front element (top of stack).
        q.pop();             // Remove the front element.
        return val;          // Return the popped element.
    }
    
    int top() {
        // Return the front element which simulates the "top" of the stack.
        return q.front();
    }
    
    bool empty() {
        // Check if the queue is empty, which means the stack is empty.
        return q.size() < 1;
    }
};

/**
 * Usage:
 * MyStack* obj = new MyStack(); // Create a new MyStack object.
 * obj->push(x);                 // Push an element 'x' onto the stack.
 * int param_2 = obj->pop();      // Pop the top element from the stack.
 * int param_3 = obj->top();      // Get the top element without removing it.
 * bool param_4 = obj->empty();   // Check if the stack is empty.
 */

