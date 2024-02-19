#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int CalScore(vector<int> &nums, int left, int right, int chance) {
        if (left > right)
            return 0; // base case

        // if chance = 0; it's First Player's Chance
        if (chance == 0) {
            return max(nums[left] + CalScore(nums, left + 1, right, 1),
                       nums[right] + CalScore(nums, left, right - 1, 1));
        }

        return min(CalScore(nums, left + 1, right, 0), CalScore(nums, left, right - 1, 0));
    }

public:
    bool PredictTheWinner(vector<int> &nums) {
        int n = nums.size();
        int TotalSum = 0;
        for (auto x : nums)
            TotalSum += x;

        int one = CalScore(nums, 0, n - 1, 0); // 1st player
        int two = TotalSum - one;

        return one >= two;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 5, 2};
    bool result = solution.PredictTheWinner(nums);
    cout << "Can the first player win? " << (result ? "Yes" : "No") << endl;

    return 0;
}
