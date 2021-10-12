class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int n, m;
    vector<vector<int>> vis;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size(), m = image[0].size();
        vis = vector<vector<int>>(n, vector<int>(m));
        int orgCol = image[sr][sc];
        vis[sr][sc] = 1;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while(q.size()){
            int i = q.front().first, j = q.front().second;
            q.pop();
            image[i][j] = newColor;
            for(int k=0;k<4;k++){
                int newi = i+dx[k];
                int newj = j+dy[k];
                if(valid(newi, newj) && !vis[newi][newj] && image[newi][newj] == orgCol){
                    vis[newi][newj] = 1;
                    q.push({newi, newj});
                }
            }
        }
        return image;
    }
    bool valid(int i, int j){
        return i < n && i >= 0 && j < m && j >= 0;
    }
};
