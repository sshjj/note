class MedianFinder {
public:
    priority_queue<int>p;
    priority_queue<int,vector<int>,greater<int>>q;
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(p.empty() || num>p.top())q.push(num);
        else{
            p.push(num);
            q.push(p.top());
            p.pop();
        }
        if(q.size()>p.size()+1){
            p.push(q.top());
            q.pop();
        }
    }
    
    double findMedian() {
        if((p.size()+q.size())%2==0){
            return (p.top()+q.top())/2.0;
        }
        else 
            return q.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */