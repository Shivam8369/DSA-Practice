#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    bool isSafePlace(int n, vector<string> &nQueens, int row, int col)
    {

        // row left
        for (int i = 0; i < n; i++)
        {
            if (nQueens[i][col] == 'Q')
            {
                return false;
            }
        }

        // upper diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (nQueens[i][j] == 'Q')
            {
                return false;
            }
        }

        // lower diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (nQueens[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }

    void solveNQueens(int n, vector<vector<string>> &output, vector<string> &nQueens, int row)
    {

        // base case
        if (row == n)
        {
            output.push_back(nQueens);
            return;
        }

        for (int col = 0; col < n; col++)
        {

            if (isSafePlace(n, nQueens, row, col))
            {
                nQueens[row][col] = 'Q';
                solveNQueens(n, output, nQueens, row + 1);
                nQueens[row][col] = '.'; // back-track
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {

        vector<vector<string>> output;
        vector<string> nQueens(n, string(n, '.'));
        solveNQueens(n, output, nQueens, 0);
        return output;
    }
};

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    Solution obj;
    vector<vector<string>> ans = obj.solveNQueens(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}