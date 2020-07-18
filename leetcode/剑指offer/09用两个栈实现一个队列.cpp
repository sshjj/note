class CQueue {
public:
    stack<int>stk,cache;
    void copy(stack<int>&s1,stack<int>&s2){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    CQueue() {

    }
    
    void appendTail(int value) {
        stk.push(value);
    }
    
    int deleteHead() {
        while(stk.empty())return -1;
        copy(stk,cache);
        int res = cache.top();
        cache.pop();
        copy(cache,stk);
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */