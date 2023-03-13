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
   bool same(TreeNode* r1, TreeNode* r2)
   {
       if(!r1 && !r2) return true;
       if(!r1 || !r2 || r1->val != r2->val) return false;
       return same(r1->left, r2->right) && same(r1->right, r2->left);
   }
public:
    bool isSymmetric(TreeNode* root)
    {
       if(root == nullptr) return true;
       return same(root->left, root->right); 
    }
};
