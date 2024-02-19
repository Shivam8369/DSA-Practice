#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{

    if (n <= 2)
    {
        return n;
    }
    return n * factorial(n - 1);
}

vector<int> factorial2(int N)
{
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            int val = ans[j] * i + carry;
            ans[j] = val % 10;
            carry = val / 10;
        }

        // if carry exist
        while (carry > 0)
        {
            ans.push_back(carry % 10);
            carry = carry / 10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{

    long long int factorials = factorial(20); // can't find if n>19
    cout << factorials<<endl;

    vector<int> res = factorial2(1001);
    cout<<"The size of Factorial is: "<< res.size()<<endl;

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
    return 0;
}