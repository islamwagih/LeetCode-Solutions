class Solution {
    vector<vector<pair<int, int>>> graph;
    int bfs(int src, int dst, int n, int k)
    {
        #define OO 1e9
        vector<int> dist(n+5, OO);
        queue<pair<int, int>> que;
        que.push({src, 0});
        int steps = 0;
        while(que.size())
        {
            int sz = que.size();
            while(sz--)
            {
                auto [node, totalCost] = que.front(); que.pop();
                for(auto& [neigh, neighCost]:graph[node])
                {
                    if(totalCost + neighCost < dist[neigh] && steps <= k)
                    {
                        dist[neigh] = totalCost + neighCost;
                        que.push({neigh, dist[neigh]});
                    }
                }
            }
            steps++;
        }
        return dist[dst] == OO ? -1:dist[dst];
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        graph = vector<vector<pair<int, int>>>(n);
        for(auto& flight:flights)
        {
            graph[flight[0]].push_back(make_pair(flight[1], flight[2]));
        }
        return bfs(src, dst, n, k);        
    }
};
