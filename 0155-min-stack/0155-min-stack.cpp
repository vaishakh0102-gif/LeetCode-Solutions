class MinStack {
    stack<long long >st;
    long long mini;
public:
    MinStack() {
        mini=INT_MAX;
        
    }
    
    void push(int value) {
        if(st.empty()){
            mini=value;
            st.push(value);

        }
        else {
            if(value>mini)st.push(value);
            else{
                st.push(2LL*value-mini);
                mini=value;
            }
        }
        
    }
    
    void pop() {
        if(st.empty())return;
        long long x=st.top();
        
        if(st.top()<mini){
            mini=2LL*mini-x;
            st.pop();
        }
        else st.pop();
        
        
    }
    
    int top() {
        if(!st.empty() && st.top()>mini){
            return st.top();
        }
        else{
            return mini;
        }
        
        
    }
    
    int getMin() {
        if(st.empty())return -1;
        return mini;
        
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