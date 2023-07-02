if(root==NULL)
            return 0;
        int leftAns=maxDepth(root->left);
        int rightAns=maxDepth(root->right);
        return max(leftAns,rightAns)+1;