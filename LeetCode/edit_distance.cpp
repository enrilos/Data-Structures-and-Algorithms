#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::vector;

class Solution
{
public:
    int minDistance(string setOne, string setTwo)
    {
        size_t setOneLen = setOne.length();
        size_t setTwoLen = setTwo.length();

        vector<vector<int>> matrix(setOneLen + 1, vector<int>(setTwoLen + 1, 0));

        for (int i = 1; i <= setOneLen; i++)
        {
            matrix[i][0] = matrix[i - 1][0] + 1;
        }

        for (int i = 1; i <= setTwoLen; i++)
        {
            matrix[0][i] = matrix[0][i - 1] + 1;
        }

        for (int i = 1; i <= setOneLen; i++)
        {
            for (int j = 1; j <= setTwoLen; j++)
            {
                if (setOne[i - 1] == setTwo[j - 1])
                {
                    matrix[i][j] = matrix[i - 1][j - 1];
                }
                else
                {
                    // Bearing in mind that all actions have the cost of 1.
                    int deleteCost = matrix[i - 1][j] + 1;
                    int insertCost = matrix[i][j - 1] + 1;
                    int replaceCost = matrix[i - 1][j - 1] + 1;
                    matrix[i][j] = std::min(deleteCost, std::min(insertCost, replaceCost));
                }
            }
        }

        return matrix[setOneLen][setTwoLen];
    }
};

int main()
{
    // Edit Distance
    // Difficulty: Hard
    string setOne, setTwo;
    getline(cin, setOne), getline(cin, setTwo);

    Solution solution;
    cout << solution.minDistance(setOne, setTwo) << endl;
    return 0;
}