#include <iostream>
#include <vector>

using std::vector;

class Solution
{
private:
    void uniquePerms(int index, vector<int> &nums, vector<int> &perms, vector<bool> &used, vector<vector<int>> &results)
    {
        if (index >= nums.size())
        {
            results.push_back(perms);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!used[i])
            {
                used[i] = true;
                perms[index] = nums[i];
                this->uniquePerms(index + 1, nums, perms, used, results);
                used[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> perms(size);
        vector<bool> used(size);
        vector<vector<int>> results(!size, vector<int>(size, 0));

        this->uniquePerms(0, nums, perms, used, results);
        return results;
    }
};

int main()
{
    // Permutations
    // Difficulty: Medium

    vector<int> nums = {1, 2, 3, 4};

    Solution solution;
    vector<vector<int>> results = solution.permute(nums);

    for (int row = 0; row < results.size(); row++)
    {
        for (int col = 0; col < results[row].size(); col++)
        {
            std::cout << results[row][col];
        }

        std::cout << std::endl;
    }

    return 0;
}