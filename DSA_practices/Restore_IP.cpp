#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    bool check(string s)
    {
        if (s[0] == '0')
            return false;
        int val = (int)stoi(s);
        return val <= 255;
    }

    void help(string &s, int i, int partition, string temp, vector<string> &ans)
    {
        // base case
        if (s.length() == i or partition == 4)
        {
            if (s.length() == i and partition == 4)
            {
                ans.push_back(temp.substr(0, temp.length() - 1));
            }
            return;
        }

        help(s, i + 1, partition + 1, temp + s[i] + ".", ans);

        if (i + 2 <= s.length() and check(s.substr(i, 2)))
            help(s, i + 2, partition + 1, temp + s.substr(i, 2) + ".", ans);

        if (i + 3 <= s.length() and check(s.substr(i, 3)))
            help(s, i + 3, partition + 1, temp + s.substr(i, 3) + ".", ans);
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        help(s, 0, 0, "", ans);
        return ans;
    }
};

int main()
{
    Solution solution;
    string input;
    cout << "Enter the IP Address:  ";
    cin >> input;

    vector<string> result = solution.restoreIpAddresses(input);

    if (result.empty())
    {
        cout << "No possible IP Addresses\n";
        return 0;
    }

    cout << "Possible IP Addresses:\n";
    for (const string ip : result)
    {
        cout << ip << endl;
    }

    return 0;
}
