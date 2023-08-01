 private:
        int average(TreeNode *root,int count)
        {
            if(root==NULL)
            {
                return 0;
            }
            count++;
            int left=average(root->left,count);
            int right=average(root->right,count);
            int sum=left+right+root->val;
            return sum;
        }
public:
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int count=0;
        int sum=average(root,count);
        if(root->val==sum/count)
        {
            count++;
        }
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);
        return count;
    }