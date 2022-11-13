class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int o = 0, n = matrix.size(), m = matrix[0].size();
        int sz = n*m;
        vector<int> ret;
        while(o < min(n, m))
        {
            int i = o;
            while(i < m) ret.push_back(matrix[o][i++]);
            if(ret.size() == sz) return ret;
            i = o+1;
            while(i < n) ret.push_back(matrix[i++][m-1]);
            if(ret.size() == sz) return ret;
            i = m-2;
            while(i >= o) ret.push_back(matrix[n-1][i--]);
            if(ret.size() == sz) return ret;
            i = n-2;
            while(i > o) ret.push_back(matrix[i--][o]);
            if(ret.size() == sz) return ret;
            n--, m--;
            o++;
        }
        return ret;
    }
};