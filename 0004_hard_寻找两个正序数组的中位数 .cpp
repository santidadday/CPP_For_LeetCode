#include <vector>
#include <algorithm>

class Solution {
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
		double result;
		std::vector<int> nums;
		int len = nums1.size() + nums2.size();
		nums.resize(len);
		merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums.begin());

		if (len == 1) {
			return double(nums[0]);
		}

		if (len % 2 == 0) {
			int middle = len / 2;
			result = (double(nums[middle]) + double(nums[middle - 1])) / 2;
		} else {
			int middle = len / 2;
			result = double(nums[middle]);
		}

		return result;
	}
};