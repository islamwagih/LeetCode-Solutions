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
    bool isCompleteTree(TreeNode* root)
    {
        if( root == nullptr || 
            (root && (!root->left && !root->right)) // empty tree or only one node 
          ) return true;

        queue<TreeNode*> bfs;
        bfs.push(root);
        bool nullNode = false;

        while(bfs.size())
        {
           TreeNode* curr = bfs.front(); bfs.pop();
           if(curr == nullptr)
           {
               nullNode = true;
           }else
           {
               if(nullNode) return false;
               bfs.push(curr->left);
               bfs.push(curr->right);
           }
        }
        return true;
    }
};
