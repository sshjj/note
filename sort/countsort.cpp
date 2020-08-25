#include <iostream>
#include <vector>
using namespace std;
 
void CountSort(vector<int> &arr, int maxVal) {
	int len = arr.size();
	if (len < 1)
		return;
	vector<int> count(maxVal+1, 0);
	vector<int> tmp(arr);
	for (auto x : arr)
		count[x]++;
	for (int i = 1; i <= maxVal; ++i)
		count[i] += count[i - 1];
	for (int i = len - 1; i >= 0; --i) {
		arr[count[tmp[i]] - 1] = tmp[i];
		count[tmp[i]]--;				//注意这里要减1
	}
}
 
int main()
{
	vector<int> arr = { 1,5,3,7,6,2,8,9,4,3,3 };
	int maxVal = 9;
	CountSort(arr,maxVal);
	for (auto x : arr)
		cout << x << " ";
	cout << endl;
	return 0;
}



void sort::sort_count(std::vector<int> &data)
  {
    // 思想：
    // 计数排序的思想比较新颖,不再是基于元素之间的比较,而是将待排序序列的元素当作容器的索引,记录索引出现的次数;
    // 比如临时容器的a[i] = n,表示元素i出现n次;
    // 记录玩出现次数之后,将临时容器从小到大将元素汇总起来,则变为有序;
    // 我的方法是有所改进,临时容器记录的不是元素出现的次数,而是记录小于等于该元素的元素个数;
    // 这样做的优点是可以保证稳定排序.
    // 计数排序的缺点：只能对整数序列进行排序,而且不适合最大元素和最小元素差得很大的情况（为什么呢）.
 
    // 1.遍历待排序数组,获取最大和最小元素,并求得插值d.
    int max = data.at(0);
    int min = data.at(0);
    int length = static_cast<int>(data.size());
    for(int i = 1; i < length; i++)
    {
      if(data.at(i) > max)
      {
        max = data.at(i);
      }
      if(data.at(i) < min)
      {
        min = data.at(i);
      }
    }
    int d = max - min;
    // 2.创建统计容器,并遍历待排序序列进行统计元素出现的次数.
    // 容器元素默认值为0.
    std::vector<int> count_data;
    count_data.resize(d+1);
    for(int i = 0; i < length; i++)
    {
      // min值作为一个偏移量的角色.
      ++count_data.at(data.at(i) - min);
    }
    // 3.改进以实现稳定排序,对统计容器做变形,统计容器元素存的不再是待排序元素出现的次数,
    // 而是记录小于等于该索引的元素个数.
    int sum = 0;
    for(auto &value : count_data)
    {
      sum += value;
      value = sum;
    }
    // 4.倒序遍历原始待排序序列,从统计容器中找到正确位置输出到结果容器,
    // 如果没有第3步,那么就是简单的输出,是非稳定的.
    std::vector<int> sorted_data;
    sorted_data.resize(data.size());
    // 注意：此处的i的类型不能用auto来排段,因为size()返回的类型为unsigned long,又因为是i--,
    // 所以如果是用auto的活,这个将是一个死循环,而且基本上会造成std::out_of_range错误.
    for(int i = static_cast<int>(data.size() - 1); i >= 0; i--)
    {
      // 代码有点绕:
      // data.at(i)-min是当前元素与最小值的差值,
      // 以差值作为count_data的索引值,则count_data.at(data.at(i)-min)代表小于等于当前元素data.at(i)的个数,
      // 所以count_data(data.at(i)-min)-1表示当前元素data.at(i)的升序序号.
      // 将当前元素data.at(i)放入sorted_data的正确的位置上.
      sorted_data.at(count_data.at(data.at(i) - min) - 1) = data.at(i);
      // 随后更新统计容器的元素值,这和倒序遍历是实现稳定排序的关键.
      --count_data.at(data.at(i)-min);
    }
    // 5.最后将已排序容器赋给原始序列,排序结束.
    data = sorted_data;
  }