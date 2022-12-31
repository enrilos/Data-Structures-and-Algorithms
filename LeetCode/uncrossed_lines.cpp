#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
    int maxUncrossedLines(vector<int> &setOne, vector<int> &setTwo)
    {
        int setOneSize = setOne.size();
        int setTwoSize = setTwo.size();

        vector<vector<int>> matrix(setOneSize + 1, vector<int>(setTwoSize + 1, 0));

        for (int i = 1; i <= setOneSize; i++)
        {
            for (int j = 1; j <= setTwoSize; j++)
            {
                int up = matrix[i - 1][j];
                int left = matrix[i][j - 1];

                int max = std::max(up, left);

                if (setOne[i - 1] == setTwo[j - 1])
                {
                    max = std::max(matrix[i - 1][j - 1] + 1, max);
                }

                matrix[i][j] = max;
            }
        }

        return matrix[setOneSize][setTwoSize];
    }
};

int main()
{
    // Uncrossed Lines
    // Difficulty: Medium

    vector<int> setOne = {2, 5, 1, 2, 5};
    vector<int> setTwo = {10, 5, 2, 1, 5, 2};

    Solution solution;
    std::cout << solution.maxUncrossedLines(setOne, setTwo) << std::endl;
    return 0;
}