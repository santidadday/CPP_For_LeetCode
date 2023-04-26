#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        // 只遍历一遍,从头开始遍历
        // 当前字符与前方所有字符都不重复是len+1
        // 当前字符与前方字符有重复时从重复处截断,并统计tag值
        int l = 0;
        int pos = 0;
        for (int i = 0; i < s.size(); i++) {
            // 查找从pos之后s[i]第一次出现位置是否与i相同
            int p = s.find(s[i], pos);
            if (p == i) {
                // 在pos之后第一次出现
                l++;
            } else {
                if (l > result) {
                    result = l;
                }
                // 两个重复元素之间的距离为i - p
                l = i - p;
                pos = p + 1;    // 更新新的pos在重复元素之后
            }
        }
        if (l > result) {
            result = l;
        }
        return result;
    }
};