#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<bool>> passable(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    passable[i][j] = true;
                }

                matrix[i][j] = 0;
            }
        }

        for (int i = 0; i < rows; i++)
        {
            if (passable[i][0] == 0)
            {
                break;
            }

            matrix[i][0] = 1;
        }

        for (int i = 0; i < cols; i++)
        {
            if (passable[0][i] == 0)
            {
                break;
            }

            matrix[0][i] = 1;
        }

        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (passable[i][j] == 0)
                {
                    continue;
                }

                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
            }
        }

        return matrix[rows - 1][cols - 1];
    }
};

int main()
{
    // Unique Paths II
    // Difficulty: Medium

    vector<vector<int>> matrix(3, vector<int>(3, 0));

    matrix[1][1] = 1;

    Solution solution;
    std::cout << solution.uniquePathsWithObstacles(matrix) << std::endl;
    return 0;
}