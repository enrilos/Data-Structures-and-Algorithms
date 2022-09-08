#include <iostream>
#include <string>
#include <vector>

using std::vector;

class Solution
{
public:
    int change(int amount, vector<int>& coins)
    {
        const int rows = coins.size();

        vector<vector<int>> dp(rows + 1, vector<int>(amount + 1, 0));

        for (int row = 0; row <= rows; row++)
        {
            dp[row][0] = 1;
        }

        for (int row = 1; row <= rows; row++)
        {
            for (int col = 1; col <= amount; col++)
            {
                int prev = col - coins[row - 1];

                if (prev < 0)
                {
                    dp[row][col] = dp[row - 1][col];
                    continue;
                }
                
                dp[row][col] = dp[row - 1][col] + dp[row][prev];
            }
        }

        return dp[rows][amount];
    }
};

int main()
{
    // Coin Change II
    // Difficulty: Medium

    int amount = 5;
    vector<int> coins = { 1, 2, 5 };

    Solution solution;
    std::cout << solution.change(amount, coins) << std::endl;
    return 0;
}