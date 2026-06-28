
class MinStack {
    stack<int> st;
        stack<int> s;
public:
    MinStack() {
       
    }
    
    void push(int val) {
        st.push(val);
        if(s.empty() || s.top()>=val)
          s.push(val);
    }
    
    void pop() {
        if(st.top()==s.top())
          s.pop();
        st.pop();

    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return s.top();
    }
};