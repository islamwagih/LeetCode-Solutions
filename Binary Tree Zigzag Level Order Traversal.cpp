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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        if(root == nullptr) return vector<vector<int>>();
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> vecs;
        int rev = 0;
        while(que.size())
        {
            int sz = que.size();
            vector<int> vec;
            while(sz--)
            {
                TreeNode* curr = que.front(); que.pop();
                vec.push_back(curr->val);
                if(curr->left != nullptr) que.push(curr->left);
                if(curr->right != nullptr) que.push(curr->right);
            }
            if(rev) reverse(vec.begin(), vec.end());
            rev ^= 1;
            vecs.push_back(vec);
        }
        return vecs;
    }
};
