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
public:
    int maxLevelSum(TreeNode* root)
    {

        queue<TreeNode*> que;
        que.push(root);
        int level = 1, maxSum = root->val;
        int currLvl = 1;
        while(que.size())
        {
            int levelSize = que.size();
            int currLvlSum = 0;
            while(levelSize--)
            {
                TreeNode* curr = que.front(); que.pop();
                currLvlSum += curr->val;
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            }
            if(currLvlSum > maxSum)
            {
                level = currLvl;
                maxSum = currLvlSum;
            }
            currLvl++;
        }

        return level;
        
    }
};
