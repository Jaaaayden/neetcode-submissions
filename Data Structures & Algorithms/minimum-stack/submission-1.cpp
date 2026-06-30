class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        all_values.push(val);

        int min_val;
        if (min_stack.empty())
            min_val = val;
        else
            min_val = min(val, min_stack.top());
        min_stack.push(min_val);
    }
    
    void pop() {
        if (min_stack.empty() || all_values.empty())
            return;
        all_values.pop();
        min_stack.pop();
    }
    
    int top() {
        return all_values.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
private:
    stack<int> all_values; // contains values themselves
    stack<int> min_stack; // contains the min of everything below (inclusive)
    // need some data structure that can getMin() in O(1) which is why we need two
};
