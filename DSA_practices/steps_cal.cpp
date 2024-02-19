#include <iostream>

class Solution
{
    int help(int n, int step)
    {
        if (n == 0)
            return step; // base case

        if (n % 2 == 0)
            return help(n / 2, step + 1);

        return help(n - 1, step + 1); // if not odd
    }
public:
    int numberOfSteps(int num)
    {
        int step = 0;
        return help(num, step);
    }
};

int main()
{
    Solution solution;
    int num = 14;

    // std::cout << "Enter a number: ";
    // std::cin >> num;

    int steps = solution.numberOfSteps(num);

    std::cout << "Number of steps required: " << steps << std::endl;

    return 0;
}
