/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution 
{
    unordered_map<int, Node*> db;
public:
    Node* cloneGraph(Node* node)
    {
       if(node == nullptr) return nullptr;
       if(db.find(node->val) != db.end()) return db[node->val];
       Node* curr = new Node(node->val);
       db[node->val] = curr;
       for(Node* neigh:node->neighbors)
       {
           Node* clonedNode = cloneGraph(neigh);
           curr->neighbors.push_back(clonedNode);
       } 
       return curr;
    }
};
