#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int lastZeroIndex = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                int temp = nums[i];
                nums[i] = nums[lastZeroIndex];
                nums[lastZeroIndex++] = temp;
            }
        }
    }
};

int main()
{
    // Move Zeroes
    // Difficulty: Easy

    vector<int> nums = {0, 3, 5, 9, 0, 0, 23, 2};
    Solution solution;
    solution.moveZeroes(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << std::endl;
    }

    return 0;
}