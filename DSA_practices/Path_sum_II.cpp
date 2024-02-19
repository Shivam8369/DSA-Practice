#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    void help(TreeNode *root, int targetSum, vector<vector<int>> &ans, vector<int> &temp)
    {
        if (root == nullptr)
            return;

        temp.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr && root->val - targetSum == 0)
        {
            ans.push_back(temp);
        }

        help(root->left, targetSum - root->val, ans, temp);
        help(root->right, targetSum - root->val, ans, temp);

        temp.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        help(root, targetSum, ans, temp);
        return ans;
    }
};

// Function to create a binary tree from an array
TreeNode *createTree(const vector<int> &nodes, int idx)
{
    if (idx >= nodes.size() || nodes[idx] == -1)
        return nullptr;

    TreeNode *root = new TreeNode(nodes[idx]);
    root->left = createTree(nodes, 2 * idx + 1);
    root->right = createTree(nodes, 2 * idx + 2);
    return root;
}

// Function to delete a binary tree
void deleteTree(TreeNode *root)
{
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Function to print a 2D vector
void printVector(const vector<vector<int>> &vec)
{
    for (auto row : vec)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Input binary tree structure
    //      5
    //     / \
    //    4   8
    //   /   / \
    //  11  13  4
    // /  \    / \
    // 7   2  5   1
    vector<int> nodes = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1};
    TreeNode *root = createTree(nodes, 0);

    int targetSum = 27;

    Solution solution;
    vector<vector<int>> result = solution.pathSum(root, targetSum);

    cout << "Path sums that equal " << targetSum << ":\n";
    printVector(result);

    // Clean up
    deleteTree(root);

    return 0;
}
