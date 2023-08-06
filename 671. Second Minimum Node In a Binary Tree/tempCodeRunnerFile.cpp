class Solution
{
private:
    long long int firstMinimum, secondMinimum = LONG_LONG_MAX;
    void dfs(TreeNode *root)
    {
        if (root == NULL)
            return;

        if (root->val > firstMinimum)
            if (root->val <= secondMinimum)
                secondMinimum = root->val;

        dfs(root->left);
        dfs(root->right);
    }

public:
    int findSecondMinimumValue(TreeNode *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        firstMinimum = root->val;

        if (secondMinimum == LONG_LONG_MAX)
            return -1;
        return secondMinimum;
    }
};