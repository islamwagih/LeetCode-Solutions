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
class Solution {
public:
    int minDepth(TreeNode* root)
    {
        if(root == nullptr) return 0;
        queue<TreeNode*> toVis;
        toVis.push(root);
        int depth = 1;
        while(toVis.size())
        {
            int sz = toVis.size();
            while(sz--)
            {
                TreeNode* curr = toVis.front(); toVis.pop();
                if(curr->left == nullptr && curr->right == nullptr)
                {
                    return depth;
                }
                if(curr->left) toVis.push(curr->left);
                if(curr->right) toVis.push(curr->right);
            }
            depth++;
        }
        return 0;
    }
};
