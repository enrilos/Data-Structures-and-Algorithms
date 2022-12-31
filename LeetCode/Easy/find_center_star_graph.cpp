#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
        {
            return edges[0][0];
        }

        return edges[0][1];
    }
};

int main()
{
    // Find Center of Star Graph
    vector<vector<int>> edges(4, vector<int>(2));
    edges[0][0] = 1;
    edges[0][1] = 2;
    edges[1][0] = 5;
    edges[1][1] = 1;
    edges[2][0] = 1;
    edges[2][1] = 3;
    edges[3][0] = 1;
    edges[3][1] = 4;

    Solution solution;
    std::cout << solution.findCenter(edges) << std::endl;
    return 0;
}