#include <iostream>
#include <string>
#include <vector>

using std::vector;

class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount + 1, amount);
        dp[0] = 0;

        for (int i = 0; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                int prev = i - coins[j];

                if (prev < 0)
                {
                    prev = 0;
                }

                if (coins[j] <= i)
                {
                    dp[i] = std::min(dp[prev] + 1, dp[i]);
                }
            }
        }

        if (dp[amount] == amount && dp.size() > 1)
        {
            for (int i = 0; i < coins.size(); i++)
            {
                if (coins[i] == 1)
                {
                    return amount;
                }
            }

            return -1;
        }

        return dp[amount];
    }
};

int main()
{
    // Coin Change
    // Difficulty: Medium

    vector<int> coins = { 1, 2, 5 };
    int amount = 11;

    Solution solution;
    std::cout << solution.coinChange(coins, amount) << std::endl;
    return 0;
}