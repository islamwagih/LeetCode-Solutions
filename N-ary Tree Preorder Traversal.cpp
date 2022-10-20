/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    stack<Node*> stk;
    vector<int> vals;
    void solve(Node* root){
        if(root == nullptr) return;
        stk.push(root);
        while(stk.size())
        {
            Node* node = stk.top();
            stk.pop();
            vals.push_back(node->val);
            for(int i=node->children.size()-1;i>=0;i--)
            {
                stk.push(node->children[i]);
            }
        }
    }
public:
    vector<int> preorder(Node* root) {
        solve(root);
        return vals;        
    }
};
