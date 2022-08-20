#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::vector;

class Solution {
public:
    int longestCommonSubsequence(string setOne, string setTwo)
    {
        size_t setOneLen = setOne.length();
        size_t setTwoLen = setTwo.length();

        vector<vector<int>> matrix(setOneLen + 1, vector<int>(setTwoLen + 1, 0));

        for (int i = 1; i <= setOneLen; i++)
        {
            for (int j = 1; j <= setTwoLen; j++)
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

        return matrix[setOneLen][setTwoLen];
    }
};

int main()
{
    // Longest Common Subsequence
    // Difficulty: Medium
    string setOne, setTwo;
    getline(cin, setOne), getline(cin, setTwo);

    Solution solution;
    cout << solution.longestCommonSubsequence(setOne, setTwo) << endl;
    return 0;
}