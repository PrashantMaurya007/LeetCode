#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Check if 1 exists
        bool containsOne = false;
        for (int num : nums) {
            if (num == 1) {
                containsOne = true;
                break;
            }
        }

        if (!containsOne)
            return 1;

        // If size is 1 and contains 1
        if (n == 1)
            return 2;

        // Replace invalid numbers with 1
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }

        // Use index as a hash key
        for (int i = 0; i < n; i++) {
            int a = abs(nums[i]);

            if (a == n) {
                nums[0] = -abs(nums[0]);
            } else {
                nums[a] = -abs(nums[a]);
            }
        }

        // Find first positive index
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) {
                return i;
            }
        }

        // Check for n
        if (nums[0] > 0) {
            return n;
        }

        return n + 1;
    }
};