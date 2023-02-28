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
   unordered_map<string, int> ids;
   unordered_map<int, int> cnt;
   vector<TreeNode*> res;
   int inorder(TreeNode* root)
   {
       if(root == nullptr) return 0;
       string rep = 
       to_string(inorder(root->left)) + "," +
       to_string(root->val) + "," +
       to_string(inorder(root->right));
       if(ids.find(rep) == ids.end())
       {
           ids[rep] = ids.size() + 1;
       }
       int id = ids[rep];
       cnt[id]++;
       if(cnt[id] == 2)
       {
           res.push_back(root);
       }
       return id;
   }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
       inorder(root);
       return res;
    }
};
