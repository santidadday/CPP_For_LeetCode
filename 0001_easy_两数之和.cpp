#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> result;
        // 使用暴力枚举法,双循环
        int count = nums.size();
        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }

    vector<int> twoSum2(vector<int>& nums, int target) {
        int count = nums.size();
        map<int, int> hashMap;

        // 哈希算法, 使用空间换时间
        for (int i = 0; i < count; i++) {
            map<int, int>::const_iterator it = hashMap.find(target - nums[i]);
            if (it == hashMap.end()) {
                hashMap.insert(pair<int, int>(nums[i], i));
            } else {
                return {it->second, i};
            }
        }
        return {};
    }
};