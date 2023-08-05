/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    map<pair<int, int>, vector<TreeNode*>> dp;
    vector<TreeNode*> generate(int left, int right)
    {
        if(left > right) return vector<TreeNode*>{nullptr};
        vector<TreeNode*> result;
        if(dp.find({left, right}) != dp.end())
        {
            return dp[{left, right}];
        }
        for(int i=left;i<=right;i++)
        {
            vector<TreeNode*> leftSubTree = generate(left, i-1);
            vector<TreeNode*> rightSubTree = generate(i+1, right);
            for(TreeNode* leftNode:leftSubTree)
            {
                for(TreeNode* rightNode:rightSubTree)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftNode;
                    root->right = rightNode;
                    result.push_back(root);
                }
            }
        }
        return dp[{left, right}] = result;
    }
public:
    vector<TreeNode*> generateTrees(int n)
    {
        dp.clear();
        return generate(1, n);
    }
};
