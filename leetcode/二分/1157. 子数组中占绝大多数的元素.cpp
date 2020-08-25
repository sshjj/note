实现一个 MajorityChecker 的类，它应该具有下述几个 API：

MajorityChecker(int[] arr) 会用给定的数组 arr 来构造一个 MajorityChecker 的实例。
int query(int left, int right, int threshold) 有这么几个参数：
0 <= left <= right < arr.length 表示数组 arr 的子数组的长度。
2 * threshold > right - left + 1，也就是说阈值 threshold 始终比子序列长度的一半还要大。
每次查询 query(...) 会返回在 arr[left], arr[left+1], ..., arr[right] 中至少出现阈值次数 threshold 的元素，如果不存在这样的元素，就返回 -1。

 

示例：

MajorityChecker majorityChecker = new MajorityChecker([1,1,2,2,1,1]);
majorityChecker.query(0,5,4); // 返回 1
majorityChecker.query(0,3,3); // 返回 -1
majorityChecker.query(2,3,2); // 返回 2
 
二分法
使用map来存放<元素值，等于该元素值的所有下标>，调用query()时，我们需要遍历map使用二分法来获得[left,right]内的元素个数，若元素个数大于等于thresshold，则我们直接返回该元素值；否则我们继续遍历map，直到遍历完成都没找到合适的值，则返回-1。

class MajorityChecker {
private:
    map<int,vector<int>> m;//<元素，等于该元素值下标>
public:
    MajorityChecker(vector<int>& arr) {
        for(int i=0;i<arr.size();++i){
            m[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        for(auto &it:m){
            if(it.second.size()<threshold)continue;
            //使用二分来查找[left,right]范围内的元素个数，若大于等于threshold则直接返回该元素，否则进行下一次遍历
            auto a=lower_bound(begin(it.second),end(it.second),left);
            auto b=upper_bound(begin(it.second),end(it.second),right);
            if(b-a>=threshold)return it.first;
        }
        return -1;
    }
};