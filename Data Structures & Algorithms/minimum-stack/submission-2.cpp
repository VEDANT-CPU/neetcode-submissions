class MinStack {
public:
    int curr_min;
    stack<int>* new_stack;
    stack<int>* prefix_min;
    MinStack() {
        this->new_stack = new stack<int>();
        this->prefix_min = new stack<int>();
        this->curr_min = INT_MAX;
    }
    
    void push(int val) {
        if(val < this->curr_min) {
            this->curr_min = val;
        }
        this->new_stack->push(val);
        this->prefix_min->push(curr_min);
    }
    
    void pop() {
        if(!this->new_stack->empty() && !this->prefix_min->empty()) {
            this->new_stack->pop();
            this->prefix_min->pop();
            if(!this->prefix_min->empty())
                this->curr_min = this->prefix_min->top();
            else
                curr_min = INT_MAX;
        }
    }
    
    int top() {
        int stack_top = INT_MAX;
        if(!this->new_stack->empty())stack_top = this->new_stack->top();
        return stack_top;
    }
    
    int getMin() {
        int min_ele = INT_MAX;
        if(!this->new_stack->empty())
            min_ele = this->prefix_min->top();
        return min_ele;
    }
};
