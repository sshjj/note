设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。
 
示例:

输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    stack<int>stk,minv;
    void push(int x) {
        stk.push(x);
        if(minv.empty()){
            minv.push(x);
        }
        else if(x<=minv.top()){
            minv.push(x);
        }
    }
    
    void pop() {
        int tmp = stk.top();
        stk.pop();
        if(tmp == minv.top()){
            minv.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minv.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
