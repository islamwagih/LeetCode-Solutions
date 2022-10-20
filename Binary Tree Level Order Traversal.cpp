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
    vector<vector<int>> levelTraversal;
    void levelBFS(TreeNode* node)
    {
        if(node == nullptr) return;
        queue<TreeNode*> que;
        que.push(node);
        while(que.size())
        {
            int lvlSize = que.size();
            vector<int> level;
            while(lvlSize--)
            {
                TreeNode* curr = que.front();
                que.pop();
                level.push_back(curr->val);
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            }
            levelTraversal.push_back(level);
        }

    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        levelBFS(root);
        return levelTraversal;
    }
};
