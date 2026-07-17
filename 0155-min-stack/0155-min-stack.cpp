class MinStack {
public:
        stack<int>st,minm;

    MinStack() {


    }
    
    void push(int val) {
        if(minm.empty() || val<=minm.top()) minm.push(val);
        st.push(val);    
    }
    
    void pop() {
        if(st.top()==minm.top()) minm.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minm.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */