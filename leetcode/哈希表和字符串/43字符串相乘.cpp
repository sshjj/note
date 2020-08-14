给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"

class Solution {
public:
    string multiply(string nums1, string nums2) {
        if(nums1 == "0"||nums2 == "0")return "0";
        vector<int>res(nums1.size()+nums2.size()+1,0);
        for(int i =0;i<nums1.size();i++){
            for(int j =0;j<nums2.size();j++){
                res[i+j+1] +=(nums1[i]-'0')*(nums2[j]-'0');
            }
        }
        for(int i = res.size()-1;i>0;i--){
            if(res[i]<10)continue;
            res[i-1] +=res[i]/10;
            res[i]%=10;
        }
        string r="";
        bool zero = true;
        for(int i =0;i<res.size()-1;i++){
            if(zero && res[i] == 0)continue;
            zero = false;
            r.push_back(res[i]+'0');
        }
        return r;

    }
};