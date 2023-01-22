#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
    int maxSubArrayDP(vector<int> &nums)
    {
        vector<int> dp(nums.size());
        dp[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = (dp[i - 1] > 0) ? nums[i] + dp[i - 1] : nums[i];
        }

        int max = INT32_MIN;

        for (int i = 0; i < dp.size(); i++)
        {
            if (max < dp[i])
                max = dp[i];
        }

        return max;
    }
    int maxSubArray(vector<int> &nums)
    {
        int max = nums[0];
        int currentMax = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            currentMax = std::max(nums[i] + currentMax, nums[i]);

            if (currentMax > max)
            {
                max = currentMax;
            }
        }

        return max;
    }
};

int main()
{
    // Maximum Subarray
    // Difficulty: Medium

    vector<int> nums = {5, 4, -1, 7, 8};
    Solution solution;
    int result = solution.maxSubArray(nums);

    std::cout << result << std::endl;

    return 0;
}