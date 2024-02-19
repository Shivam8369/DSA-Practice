/* The `#include <iostream>` directive is including the input/output stream library in the C++ program.
This library provides functionality for reading input from the user and printing output to the
console. */
#include <iostream>
#include <vector>
using namespace std;

vector<int> dp(46, -1);

class Solution
{
public:
    int climbStairs(int n)
    {
        // base case
            return dp[n];

        if (n <= 2)
            return dp[n] = n;

        // recursive case
        return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};

int main()
{

    int TestCases;
    cout << "Enter the Number of testcases you want to run  ";
    cin >> TestCases;

    while (TestCases--)
    {

        Solution solution;
        int n;
        cout << "Enter the Number ";
        cin >> n;

        int ways = solution.climbStairs(n);
        cout << "Number of ways to climb " << n << " stairs: " << ways << endl;
    }
    return 0;
}
