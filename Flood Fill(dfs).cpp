class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int n, m;
    vector<vector<int>> vis;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size(), m = image[0].size();
        vis = vector<vector<int>>(n, vector<int>(m));
        dfs(sr, sc, newColor, image);
        return image;
    }
    bool valid(int i, int j){
        return i < n && i >= 0 && j < m && j >= 0;
    }
    void dfs(int i, int j, int c, vector<vector<int>>& image){
        vis[i][j] = 1;
        for(int k=0;k<4;k++){
            int newi = i+dx[k];
            int newj = j+dy[k];
            if(valid(newi, newj) && !vis[newi][newj] &&image[newi][newj] == image[i][j]){
                dfs(newi, newj, c, image);
            }
        }
        image[i][j] = c;
    }
};
