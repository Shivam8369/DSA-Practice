#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> dp(101, -1);

class Solution
{
    int help(string s, int pos, int n)
    {
        // base case
        if (pos == n)
            return 1;
        if (s[pos] == '0')
            return 0;
        if (dp[pos] != -1)
            return dp[pos];

        int count1 = help(s, pos + 1, n);

        if (pos < n - 1 && s.substr(pos, 2) < "27")
            count1 += help(s, pos + 2, n);

        return dp[pos] = count1;
    }

public:
    int numDecodings(string s)
    {
        fill(dp.begin(), dp.end(), -1);
        return help(s, 0, s.length());
    }
};

int main()
{

    int TestCases;
    cout << "Enter the Number of testcases you want to run  ";
    cin >> TestCases;

    while (TestCases--)
    {
        string str;
        cout << "Enter the String  ";
        cin >> str;

        if (isalpha(str[0]))
        {
            cout << "Invalid input enter the number " << endl;
            break;
        }

        Solution obj;
        int count = obj.numDecodings(str);
        cout << "Number of decodings: " << count << endl;
    }
    return 0;
}
