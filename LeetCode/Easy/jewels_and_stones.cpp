#include <iostream>
#include <string>
#include <set>

using std::string;

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        std::set<char> set(jewels.begin(), jewels.end());
        int total = 0;

        for (auto stone : stones)
        {
            if (set.count(stone))
            {
                total++;
            }
        }

        return total;
    }
};

int main()
{
    string jewels = "aA";
    string stones = "aAAbbbb";

    Solution solution;
    std::cout << solution.numJewelsInStones(jewels, stones) << std::endl;
    return 0;
}