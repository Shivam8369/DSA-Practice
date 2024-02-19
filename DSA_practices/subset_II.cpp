#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void help(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, int index) {
        ans.push_back(temp);  // Add the current subset to the result
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue;  // Skip duplicates
            }
            temp.push_back(nums[i]);
            help(nums, temp, ans, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        help(nums, temp, ans, 0);
        return ans;
    }
};

int main() {
    Solution solution;

    int n;
    cout<<"Enter the size of the array  ";
    cin >> n;

    vector<int> nums(n);
    cout<<"Enter the element  ";
    for(int i=0; i<n; i++)
    {
        cin >>nums[i];
    }
    
    vector<vector<int>> result = solution.subsetsWithDup(nums);
    
    // Print the subsets
    for (const auto& subset : result) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    
    return 0;
}
