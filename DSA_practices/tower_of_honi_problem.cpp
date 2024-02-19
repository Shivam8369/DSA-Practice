#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void towerOfHanoi(int n, int from_rod, int to_rod, int aux_rod, long long &ans)
    {
        if (n == 0)
        { // base case
            return;
        }

        towerOfHanoi(n - 1, from_rod, aux_rod, to_rod, ans);
        ans++;
        cout << "move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
        towerOfHanoi(n - 1, aux_rod, to_rod, from_rod, ans);
    }

    long long toh(int N, int from, int to, int aux)
    {

        long long ans = 0;
        towerOfHanoi(N, from, to, aux, ans);
        return ans;
    }
};

int main()
{

    int T;
    cout<<"Enter the No. of testcases you want to run ";
    cin >> T; // testcases

    while (T--)
    {

        int N;
        cout<<"Enter the No. ";
        cin >> N; // taking input N

        Solution ob;

        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}