class Solution {
public:
    bool Solve(TreeNode*root,int &targetSum,int&sum,bool&ans)
    {
        if(root==NULL) return false;
        sum+=root->val;
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==targetSum)
            {
                ans=true;
            }
            sum-=root->val;
            return ans;
        }
        if(ans==true) return ans;
        Solve(root->left,targetSum,sum,ans);
        if(ans==true) return ans;
        Solve(root->right,targetSum,sum,ans);
        sum-=root->val;
        return ans;
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        int sum=0;
        bool ans=false;
        if(root==NULL) return false;
        return Solve(root,targetSum,sum,ans);
    }
};