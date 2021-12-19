class MinStack {
public:
    stack<pair<int, int>>stp;
    MinStack() { 
    }
    
    void push(int val) {
        if(stp.empty()){
            stp.push({val, val});
        }
        else{
            if(stp.top().second > val){
                stp.push({val, val});
            }
            else{
                stp.push({val, stp.top().second});
            }
        }
    }
    
    void pop() {
        stp.pop();
    }
    
    int top() {
        return stp.top().first;
    }
    
    int getMin() {
        return stp.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
