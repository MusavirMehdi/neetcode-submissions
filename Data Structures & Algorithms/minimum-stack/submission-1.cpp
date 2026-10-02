class MinStack {
    stack <int> s;
    stack <int> smin;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(smin.empty()){
            smin.push(s.top());
        }
        else{
            smin.push(min(val,smin.top()));
        }
    }
    
    void pop() {
        s.pop();
        smin.pop();
    }
    
    int top() {
        int top = s.top();
        return top;
    }
    
    int getMin() {
        
        return smin.top();
    }
};
