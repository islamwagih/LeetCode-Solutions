class Solution {
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        if (root == NULL) return 0;
        int maxWidth = 1;
        queue<pair<TreeNode*, int>> que; //pair of node, index
        que.push({root, 0});

        while (!que.empty())
        {
            int levelSize = que.size();
            int startInd = que.front().second;
            int endInd = que.back().second;
            maxWidth = max(maxWidth, endInd - startInd + 1);
            while(levelSize--)
            {
                auto currNodePair = que.front();
                TreeNode* currNode = currNodePair.first;
                int currNodeInd = currNodePair.second - startInd;
                que.pop();
                if (currNode->left != nullptr)
                {
                    que.push({currNode->left, 2LL * currNodeInd + 1});
                }
                if (currNode->right != nullptr)
                {
                    que.push({currNode->right, 2LL * currNodeInd + 2});
                }
            }
        }
        
        return maxWidth;
    }
};
