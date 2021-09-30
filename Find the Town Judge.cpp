class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n+1, 0), out(n+1, 0);
        for(auto& list:trust){
            int u = list[0], v = list[1];
            in[v]++;
            out[u]++;
        }
        for(int i=1;i<=n;i++){
            if(in[i] == n-1 && out[i] == 0){
                return i;
            }
        }
        return -1;
    }
};
