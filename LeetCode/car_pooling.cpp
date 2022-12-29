#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int tripsLengths[1001] = {};

        for (auto trip : trips)
        {
            tripsLengths[trip[1]] += trip[0];
            tripsLengths[trip[2]] -= trip[0];
        }

        int carLoad = 0;

        for (int i = 0; i < 1001; i++)
        {
            carLoad += tripsLengths[i];

            if (carLoad > capacity)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    // Car Pooling
    // Difficulty: Medium
    vector<vector<int>> trips(2, vector<int>(3, 0));
    trips[0] = {2, 1, 5};
    trips[1] = {3, 3, 7};
    int capacity = 5;

    Solution solution;
    std::cout << solution.carPooling(trips, capacity) << std::endl;
    return 0;
}