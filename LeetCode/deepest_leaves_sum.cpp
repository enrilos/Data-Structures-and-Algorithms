#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    void dfs(TreeNode *node, int &sum, int level, int &deepestLevel)
    {
        if (NULL == node)
        {
            return;
        }

        if (level == deepestLevel)
        {
            sum += node->val;
        }
        else if (level >= deepestLevel)
        {
            sum = 0;
            sum += node->val;
            deepestLevel = level;
        }

        dfs(node->left, sum, level + 1, deepestLevel);
        dfs(node->right, sum, level + 1, deepestLevel);
    }

public:
    int deepestLeavesSum(TreeNode *root)
    {
        int sum = 0;
        int bestLevel = 1;
        this->dfs(root, sum, 1, bestLevel);
        return sum;
    }
};

int main()
{
    TreeNode root = {3};
    Solution solution;
    std::cout << solution.deepestLeavesSum(&root) << std::endl;

    return 0;
}