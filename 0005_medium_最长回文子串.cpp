#include <string>
#include <vector>

class Solution {
public:
    // 枚举法,时间复杂度:n^3,空间复杂度:1
	std::string longestPalindrome1(std::string s) {
        int pos = 0;
        int maxLen = 1;
        int len = s.size();
        for (int i = 0; i < len - 1; i++) { // 从不同起点开始寻找是否存在回文子串
            for (int j = i + 1; j < len; j++) {
                if (j - i + 1 > maxLen && isPalindrome(s, i, j)) {
                    maxLen = j - i + 1;
                    pos = i;
                }
            }
        }

        return s.substr(pos, maxLen);
    }
    bool isPalindrome(std::string &s, int i, int j) {    // 判断子串是否为回文子串
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    // 动态规划,时间复杂度:n^2,空间复杂度:n^2
	std::string longestPalindrome2(std::string s) {
        int l = s.size();
        if (l < 2) {
            return s;
        }

		std::vector<std::vector<bool>> dp;
		std::vector<bool> temp;
        // 创建动态规划表
        for (int i = 0; i < l; i++) {
            temp.push_back(false);
        }
        for (int i = 0; i < l; i++) {
            dp.push_back(temp);
            dp[i][i] = true;
        }

        int maxlen = 1;
        int pos = 0;
        // 遍历动态规划表上半部分确定最长回文串的初始位置和最大长度
        for (int j = 1; j < l; j++) {   // i为起始下标,j为终止下标
            for (int i = 0; i < j; i++) {
                if (j - i == 1) {
                    // 偶数类型动态规划
                    if (s[i] == s[j]) {
                        dp[i][j] = true;
                    }
                } else {
                    if (dp[i + 1][j - 1] == true && s[i] == s[j]) {
                        dp[i][j] = true;
                    }
                }

                if (dp[i][j]) {
                    int lentemp = j - i + 1;
                    if (lentemp > maxlen) {
                        maxlen = lentemp;
                        pos = i;
                    }
                }
            }
        }
        return s.substr(pos, maxlen);
    }
};