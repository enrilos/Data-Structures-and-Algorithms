#include <iostream>
#include <vector>

using std::vector;

class Solution
{
private:
    bool isFieldSafe(int row, int col, vector<vector<int>> &grid)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[row].size())
        {
            return false;
        }

        if (grid[row][col] == -1)
        {
            return false;
        }

        return true;
    }
    void findPaths(int row, int col, vector<vector<int>> &grid, int emptyCellsCount, int currentEmptyCellsCount, int *totalCount)
    {
        if (!this->isFieldSafe(row, col, grid))
        {
            return;
        }

        if (grid[row][col] == 2)
        {
            if (emptyCellsCount + 1 == currentEmptyCellsCount)
            {
                (*totalCount)++;
            }

            return;
        }

        grid[row][col] = -1;
        findPaths(row - 1, col, grid, emptyCellsCount, currentEmptyCellsCount + 1, totalCount);
        findPaths(row + 1, col, grid, emptyCellsCount, currentEmptyCellsCount + 1, totalCount);
        findPaths(row, col - 1, grid, emptyCellsCount, currentEmptyCellsCount + 1, totalCount);
        findPaths(row, col + 1, grid, emptyCellsCount, currentEmptyCellsCount + 1, totalCount);
        grid[row][col] = 0;
    }

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int emptyCellsCount = 0;
        int startRow = 0;
        int startCol = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 0)
                {
                    emptyCellsCount++;
                }
                else if (grid[i][j] == 1)
                {
                    startRow = i;
                    startCol = j;
                }
            }
        }

        int totalCount = 0;
        this->findPaths(startRow, startCol, grid, emptyCellsCount, 0, &totalCount);
        return totalCount;
    }
};

int main()
{
    // Unique Paths III
    // Difficulty: Hard
    vector<vector<int>> grid(3, vector<int>(4, 0));

    grid[0] = {1, 0, 0, 0};
    grid[1] = {0, 0, 0, 0};
    grid[2] = {0, 0, 2, -1};

    Solution solution;
    std::cout << solution.uniquePathsIII(grid) << std::endl;
    return 0;
}