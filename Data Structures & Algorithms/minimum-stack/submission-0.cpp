class MinStack {
    stack <int> s;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        int top = s.top();
        return top;
    }
    
    int getMin() {
        int min = INT_MAX;
        stack <int> s2;
        while(!s.empty()){
            s2.push(s.top());
            if(s.top()<min){
                min = s.top();
            }
            s.pop();
        }
        while(!s2.empty()){
            s.push(s2.top());
            s2.pop();
        }
        return min;
    }
};
