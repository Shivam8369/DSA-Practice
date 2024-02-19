#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void help(string curr, vector<string>& ans, int open, int close, int n) {
        // Base case
        if (open == n && close == n) {
            ans.push_back(curr);
            return;
        }
        
        // Open case
        if (open < n)
            help(curr + '(', ans, open + 1, close, n);
        
        // Close case
        if (open > close)
            help(curr + ')', ans, open, close + 1, n);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        help("", ans, 0, 0, n);
        return ans;
    }
};

int main() {
    Solution solution;
    int n;
    cout <<"Enter the value  ";
    cin >> n;
    
    vector<string> result = solution.generateParenthesis(n);
    
    // Print the generated parenthesis combinations
    for (const string& str : result) {
        cout << str << endl;
    }
    
    return 0;
}
