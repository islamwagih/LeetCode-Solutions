/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution
{
    vector<vector<int>> grid;
    struct Point
    {
        int x, y;
    };

    //first: leaf or not, second: val
    pair<bool, bool> isLeaf(Point& topLeft, Point& bottomRight)
    {
        int allZeros = 1, allOnes = 1;
        for(int i=topLeft.x;i<=bottomRight.x;i++)
        {
            for(int j=topLeft.y;j<=bottomRight.y;j++)
            {
                allZeros &= (grid[i][j] == 0);
                allOnes &= (grid[i][j] == 1);
            }
        }
        pair<bool, bool> ret;
        ret.first = allZeros || allOnes;
        ret.second = allZeros ? 0:1;
        return ret;
    }

    void getTopLeftChilds(Point& topLeft, Point& bottomRight, vector<Point>& points)
    {
        Point childTopLeft1;
        childTopLeft1.x = topLeft.x;
        childTopLeft1.y = topLeft.y;

        Point childTopLeft2;
        childTopLeft2.x = (bottomRight.x+topLeft.x)/2;
        childTopLeft2.y = (bottomRight.y+topLeft.y)/2;

        points.push_back(childTopLeft1);
        points.push_back(childTopLeft2);

    }

    void getTopRightChilds(Point& topLeft, Point& bottomRight, vector<Point>& points)
    {
        Point childTopRight1;
        childTopRight1.x = topLeft.x;
        childTopRight1.y = ((topLeft.y+bottomRight.y)/2)+1;

        Point childTopRight2;
        childTopRight2.x = (bottomRight.x+topLeft.x)/2;
        childTopRight2.y = bottomRight.y;

        points.push_back(childTopRight1);
        points.push_back(childTopRight2);
    }

    void getBottomLeftChilds(Point& topLeft, Point& bottomRight, vector<Point>& points)
    {  
        Point childBottomLeft1;
        childBottomLeft1.x = ((bottomRight.x+topLeft.x)/2)+1;
        childBottomLeft1.y = topLeft.y;

        Point childBottomLeft2;
        childBottomLeft2.x = bottomRight.x;
        childBottomLeft2.y = (bottomRight.y+topLeft.y)/2;

        points.push_back(childBottomLeft1);
        points.push_back(childBottomLeft2);
    }

    void getBottomRightChilds(Point& topLeft, Point& bottomRight, vector<Point>& points)
    {
        Point childBottomRight1;
        childBottomRight1.x = ((bottomRight.x+topLeft.x)/2)+1;
        childBottomRight1.y = ((bottomRight.y+topLeft.y)/2)+1;

        Point childBottomRight2;
        childBottomRight2.x = bottomRight.x;
        childBottomRight2.y = bottomRight.y;

        points.push_back(childBottomRight1);
        points.push_back(childBottomRight2);
    }


    vector<Point> partition(Point& topLeft, Point& bottomRight)
    {
        vector<Point> points;
        getTopLeftChilds(topLeft, bottomRight, points);
        getTopRightChilds(topLeft, bottomRight, points);
        getBottomLeftChilds(topLeft, bottomRight, points);
        getBottomRightChilds(topLeft, bottomRight, points);
        return points; 
    }

    Node* helper(Point topLeft, Point bottomRight)
    {
        pair<bool, bool> leafTest = isLeaf(topLeft, bottomRight);
        if(leafTest.first)
        {
            return new Node(leafTest.second, true);
        }
        Node* root = new Node(leafTest.second, false);
        vector<Point> childs = partition(topLeft, bottomRight);
        root->topLeft = helper(childs[0], childs[1]);
        root->topRight = helper(childs[2], childs[3]);
        root->bottomLeft = helper(childs[4], childs[5]);
        root->bottomRight = helper(childs[6], childs[7]);
        return root;
    }
public:
   
    Node* construct(vector<vector<int>>& grid)
    {
        this->grid = grid;
        Point topLeft;
        topLeft.x = 0, topLeft.y = 0;
        Point bottomRight;
        bottomRight.x = grid.size() - 1;
        bottomRight.y = grid.size() - 1;
        return helper(topLeft, bottomRight);
    }

};
