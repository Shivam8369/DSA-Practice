/**
 * The above code is a C++ implementation of a backtracking algorithm to find all possible paths in a
 * matrix from the top-left corner to the bottom-right corner.
 *
 * @return The function `findPath` returns a vector of strings, which represents the paths from the
 * top-left cell to the bottom-right cell in the given matrix.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> m)
    {
        if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1)
            return true;

        else
            return false;
    }

    void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y,
               vector<vector<int>> visited, string path)
    {

        // base case
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;

        // four choice D,U,R,L

        // down
        int newx = x + 1;
        int newy = y;
        if (isSafe(newx, newy, n, visited, m))
        {
            path.push_back('D');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // left
        newx = x;
        newy = y - 1;
        if (isSafe(newx, newy, n, visited, m))
        {
            path.push_back('L');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // right
        newx = x;
        newy = y + 1;
        if (isSafe(newx, newy, n, visited, m))
        {
            path.push_back('R');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // up
        newx = x - 1;
        newy = y;
        if (isSafe(newx, newy, n, visited, m))
        {
            path.push_back('U');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        visited[x][y] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;

        if (m[0][0] == 0)
            return ans;

        int srcx = 0;
        int srcy = 0;
        vector<vector<int>> visited = m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }

        if (m[0][0] == 0)
            return ans;

        string path = "";
        solve(m, n, ans, srcx, srcy, visited, path);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cout << "Enter the number of testcases: ";
    cin >> t;
    while (t--)
    {
        int n;
        cout << "Enter the size of the matrix: ";
        cin >> n;

        cout << "Enter the elements to the matrix either as 0 or 1: ";
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(m, n);

        sort(result.begin(), result.end());

        if (result.size() == 0)
            cout << -1;
        else

            cout << "The path is: " << endl;
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}