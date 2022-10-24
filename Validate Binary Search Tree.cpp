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
    vector<int> traversal;
    void inorder(TreeNode* root)
    {
        if(root == nullptr) return;
        inorder(root->left);
        traversal.push_back(root->val);
        inorder(root->right);
    }
    bool incSorted(vector<int>& arr)
    {
        int n = arr.size();
        for(int i=0;i<n-1;i++)
        {
            if(arr[i] >= arr[i+1]) return false;
        }
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        inorder(root);
        return incSorted(traversal);
    }
};
