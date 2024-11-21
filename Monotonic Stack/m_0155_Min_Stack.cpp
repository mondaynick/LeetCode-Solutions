/*
  設計一個堆疊，給定的API如下：
    push(val)：將val push進堆疊
    pop()：從堆疊pop出一個元素
    top()：回傳堆疊的top元素
    getMin()：回傳堆疊中最小的元素

    建立兩個堆疊，一個堆疊式同一般的堆疊，一個堆疊為單調堆疊，只會加入越來越小的數值
 */

class MinStack {
private:
    stack<int> oriStk, minStk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        oriStk.push(val);
        if (minStk.empty()) {
            minStk.push(val);
        } else {
            if (val < minStk.top()) {
                minStk.push(val);
            } else {
                minStk.push(minStk.top());
            }
        }
    }
    
    void pop() {
        oriStk.pop();
        minStk.pop();
    }
    
    int top() {
        return oriStk.top();
    }
    
    int getMin() {
        return minStk.top();
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
