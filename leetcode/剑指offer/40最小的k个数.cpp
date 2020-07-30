输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> heap;
        for(auto x:arr){
            heap.push(x);
            if(heap.size()>k)heap.pop();
        }
        vector<int> res;
        while(heap.size())res.push_back(heap.top()),heap.pop();
        reverse(res.begin(),res.end());
        return res;
    }
};