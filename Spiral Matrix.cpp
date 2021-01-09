class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int sr,er,sc,ec;
        sr = sc = 0;
        er = m-1, ec = n-1;
        int count = 0;
        while(sr <= er && sc <= ec){
            for(int i = sc; i <= ec;i++){
                ans.push_back(matrix[sr][i]);
                count++;
            }
            sr++;
            if(count == m*n) return ans;
            for(int i = sr; i <= er; i++){
                ans.push_back(matrix[i][ec]);
                count++;
            }
            ec--;
            if(count == m*n) return ans;
            for(int i = ec; i >= sc; i--){
                ans.push_back(matrix[er][i]);
                count++;
            }
            er--;
            if(count == m*n) return ans;
            for(int i = er; i >= sr; i--){
                ans.push_back(matrix[i][sc]);
                count++;
            }
            sc++;
            if(count == m*n) return ans;
        }
        return ans;   
    }
};
