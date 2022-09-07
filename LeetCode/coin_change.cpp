#include <iostream>
#include <string>
#include <vector>

using std::vector;

class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }

        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                int prev = i - coins[j];

                if (prev >= 0 && dp[prev] != amount + 1)
                {
                    dp[i] = std::min(dp[prev] + 1, dp[i]);
                }
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

int main()
{
    // Coin Change
    // Difficulty: Medium

    vector<int> coins = { 2 };
    int amount = 11;

    Solution solution;
    std::cout << solution.coinChange(coins, amount) << std::endl;
    return 0;
}