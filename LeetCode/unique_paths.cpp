#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> matrix(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 1;
        }

        for (int j = 0; j < n; j++)
        {
            matrix[0][j] = 1;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
            }
        }

        return matrix[m - 1][n - 1];
    }
};

int main()
{
    // Unique Paths
    // Difficulty: Medium

    int m = 3;
    int n = 7;

    Solution solution;
    std::cout << solution.uniquePaths(m, n) << std::endl;
    return 0;
}