#include <iostream>
#include <map>
#include <vector>
#include <list>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::map<int, std::list<int>> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]].push_back(i);
        }
        for (int i = 0; i < nums.size(); i++) {
            int expected = target - nums[i];
            if (map.find(expected) != map.end()) {
                std::list<int> list = map[expected];
                for (int &it : list) {
                    if (it == i) {
                        continue;
                    }
                    return std::vector {i, it};
                }
            }
        }
        return {};
    }
    int romanToInt(std::string s) {
        std::map<char, int> scores {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000},
        };
        int sum = 0;
        for (int i = (int) s.size() - 1; i >= 0; --i) {
            if (i + 1 == s.size()
                || scores[s[i]] >= scores[s[i + 1]]) {
                sum += scores[s[i]];
            } else {
                sum -= scores[s[i]];
            }
        }
        return sum;
    }
    
};

int main() {
    Solution solution;
    std::cout << solution.romanToInt("III") << ", " << 3 << std::endl;
    std::cout << solution.romanToInt("IV") << ", " << 4 << std::endl;
    std::cout << solution.romanToInt("LVIII") << ", " << 58 << std::endl;
    std::cout << solution.romanToInt("MCMXCIV") << ", " << 1994 << std::endl;
    return 0;
}
