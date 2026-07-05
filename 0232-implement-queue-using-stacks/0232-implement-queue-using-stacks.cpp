class MyQueue {
    private: stack<int> instack;
    private: stack<int> outstack;
public:
    MyQueue() {
    
        
    }
    
    void push(int x) {
        instack.push(x);

        
    }
    
    int pop() {
        peek();
        const int val = outstack.top();
        outstack.pop();
        return val;
        
    }
    
    int peek() {
        if(outstack.empty())
        while(!instack.empty())
            outstack.push(instack.top()),instack.pop();
            return outstack.top();
        
    }
    
    bool empty() {
        return instack.empty() && outstack.empty();
        
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