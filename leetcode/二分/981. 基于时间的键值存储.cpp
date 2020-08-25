创建一个基于时间的键值存储类 TimeMap，它支持下面两个操作：

1. set(string key, string value, int timestamp)

存储键 key、值 value，以及给定的时间戳 timestamp。
2. get(string key, int timestamp)

返回先前调用 set(key, value, timestamp_prev) 所存储的值，其中 timestamp_prev <= timestamp。
如果有多个这样的值，则返回对应最大的  timestamp_prev 的那个值。
如果没有值，则返回空字符串（""）。
 

示例 1：

输入：inputs = ["TimeMap","set","get","get","set","get","get"], inputs = [[],["foo","bar",1],["foo",1],["foo",3],["foo","bar2",4],["foo",4],["foo",5]]
输出：[null,null,"bar","bar",null,"bar2","bar2"]
解释：  
TimeMap kv;   
kv.set("foo", "bar", 1); // 存储键 "foo" 和值 "bar" 以及时间戳 timestamp = 1   
kv.get("foo", 1);  // 输出 "bar"   
kv.get("foo", 3); // 输出 "bar" 因为在时间戳 3 和时间戳 2 处没有对应 "foo" 的值，所以唯一的值位于时间戳 1 处（即 "bar"）   
kv.set("foo", "bar2", 4);   
kv.get("foo", 4); // 输出 "bar2"   
kv.get("foo", 5); // 输出 "bar2"   

题解：

二分法：寻找小于等于x的最大值，可以转换为寻找大于x的最小值，这样大于x的最小值的前一个就是小于等于x的最大值了。
思路：将<key,val,time>存在放一个unordered_map<string,map<int,string>>map中，在get(key,timestamp)使用map的二分查找函数upper_bound来寻找大于x的最小值，若最小值的位置为第一个元素的位置，表示小于等于x的位置不存在，那么我们应该返回空字符串；否则，我们就返回最小值位置的前一个位置的字符串。
代码如下：

class TimeMap {
private:
    unordered_map<string,map<int,string>> m;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp]=value;
    }
    
    //二分法：求小于等于x的最大值res1，转换为求大于x的最小值res2，然后res2-1=res1为最大值
    string get(string key, int timestamp) {
        auto& myMap=m[key];
        //二分求出大于timestamp的最小值，若大于timestamp的最小值为第一个时间，那么应该返回空字符串；若不为第一个时间，那么返回前一个时间的value，转换为小于等于x的最大值了
        auto it=myMap.upper_bound(timestamp);
        return it==myMap.begin()?"":prev(it)->second;
    }
};